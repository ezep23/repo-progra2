#include <iostream>
using namespace std;

#include "CategoriaArchivo.h"

CategoriaArchivo::CategoriaArchivo(std::string nombreArchivo): _nombreArchivo(nombreArchivo){

}

bool CategoriaArchivo::guardar(const Categoria &reg){
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  result = fwrite(&reg, sizeof(Categoria), 1, pFile);

  fclose(pFile);

  return result;
}

bool CategoriaArchivo::guardar(int pos, const Categoria &registro){
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb+");

  if(pFile == nullptr){
    return false;
  }

  fseek(pFile, sizeof(Categoria)*pos, SEEK_SET);

  result = fwrite(&registro, sizeof(Categoria), 1, pFile);

  fclose(pFile);

  return result;
}

int CategoriaArchivo::buscarID(int id){
  Categoria reg;
  FILE *pFile;
  int pos = -1;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return pos;
  }

  while(fread(&reg, sizeof(Categoria), 1, pFile)){
    if(reg.getId() == id){
      pos = ftell(pFile) / sizeof(Categoria) - 1;
      break;
    }
  }

  fclose(pFile);

  return pos;
}

Categoria CategoriaArchivo::leer(int pos){
  Categoria reg;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    reg.setId(-1);
    return reg;
  }

  fseek(pFile, sizeof(Categoria)*pos, SEEK_SET);

  fread(&reg, sizeof(Categoria), 1, pFile);

  fclose(pFile);

  return reg;
}

int CategoriaArchivo::leerTodos(Categoria regs[], int cantidad){
  int result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return 0;
  }

  result = fread(regs, sizeof(Categoria), cantidad, pFile);

  fclose(pFile);

  return result;
}

int CategoriaArchivo::getCantidadRegistros(){
  int cantidad;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  cantidad = ftell(pFile) / sizeof(Categoria);

  fclose(pFile);

  return cantidad;
}

int CategoriaArchivo::getNuevoID(){
    return getCantidadRegistros() + 1;
}

bool CategoriaArchivo::eliminar(int pos){
  Categoria reg = leer(pos);
  if(reg.getId() == -1){
    return false;
  }

  reg.setEstado(false);

  return guardar(pos, reg);
}
