#include <iostream>
using namespace std;

#include "ClienteArchivo.h"

ClienteArchivo::ClienteArchivo(std::string nombreArchivo): _nombreArchivo(nombreArchivo){

}

bool ClienteArchivo::guardar(const Cliente &reg){
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  result = fwrite(&reg, sizeof(Cliente), 1, pFile);

  fclose(pFile);

  return result;
}

bool ClienteArchivo::guardar(int pos, const Cliente &registro){
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb+");

  if(pFile == nullptr){
    return false;
  }

  fseek(pFile, sizeof(Cliente)*pos, SEEK_SET);

  result = fwrite(&registro, sizeof(Cliente), 1, pFile);

  fclose(pFile);

  return result;
}

int ClienteArchivo::buscarID(int id){
  Cliente reg;
  FILE *pFile;
  int pos = -1;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return pos;
  }

  while(fread(&reg, sizeof(Cliente), 1, pFile)){
    if(reg.getId() == id){
      pos = ftell(pFile) / sizeof(Cliente) - 1;
      break;
    }
  }

  fclose(pFile);

  return pos;
}

Cliente ClienteArchivo::leer(int pos){
  Cliente reg;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    reg.setId(-1);
    return reg;
  }

  fseek(pFile, sizeof(Cliente)*pos, SEEK_SET);

  fread(&reg, sizeof(Cliente), 1, pFile);

  fclose(pFile);

  return reg;
}

int ClienteArchivo::leerTodos(Cliente regs[], int cantidad){
  int result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return 0;
  }

  result = fread(regs, sizeof(Cliente), cantidad, pFile);

  fclose(pFile);

  return result;
}

int ClienteArchivo::getCantidadRegistros(){
  int cantidad;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  cantidad = ftell(pFile) / sizeof(Cliente);

  fclose(pFile);

  return cantidad;
}

int ClienteArchivo::getNuevoID(){
    return getCantidadRegistros() + 1;
}

bool ClienteArchivo::eliminar(int pos){
  Cliente reg = leer(pos);
  if(reg.getId() == -1){
    return false;
  }

  reg.setEstado(false);

  return guardar(pos, reg);
}
