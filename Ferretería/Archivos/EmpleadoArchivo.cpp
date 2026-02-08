#include <iostream>
using namespace std;

#include "EmpleadoArchivo.h"

EmpleadoArchivo::EmpleadoArchivo(std::string nombreArchivo): _nombreArchivo(nombreArchivo){

}

bool EmpleadoArchivo::guardar(const Empleado &reg){
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  result = fwrite(&reg, sizeof(Empleado), 1, pFile);

  fclose(pFile);

  return result;
}

bool EmpleadoArchivo::guardar(int pos, const Empleado &registro){
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb+");

  if(pFile == nullptr){
    return false;
  }

  fseek(pFile, sizeof(Empleado)*pos, SEEK_SET);

  result = fwrite(&registro, sizeof(Empleado), 1, pFile);

  fclose(pFile);

  return result;
}

int EmpleadoArchivo::buscarID(int id){
  Empleado reg;
  FILE *pFile;
  int pos = -1;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return pos;
  }

  while(fread(&reg, sizeof(Empleado), 1, pFile)){
    if(reg.getId() == id){
      pos = ftell(pFile) / sizeof(Empleado) - 1;
      break;
    }
  }

  fclose(pFile);

  return pos;
}

Empleado EmpleadoArchivo::leer(int pos){
  Empleado reg;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    reg.setId(-1);
    return reg;
  }

  fseek(pFile, sizeof(Empleado)*pos, SEEK_SET);

  fread(&reg, sizeof(Empleado), 1, pFile);

  fclose(pFile);

  return reg;
}

int EmpleadoArchivo::leerTodos(Empleado regs[], int cantidad){
  int result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return 0;
  }

  result = fread(regs, sizeof(Empleado), cantidad, pFile);

  fclose(pFile);

  return result;
}

int EmpleadoArchivo::getCantidadRegistros(){
  int cantidad;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  cantidad = ftell(pFile) / sizeof(Empleado);

  fclose(pFile);

  return cantidad;
}

int EmpleadoArchivo::getNuevoID(){
    return getCantidadRegistros() + 1;
}

bool EmpleadoArchivo::eliminar(int pos){
  Empleado reg = leer(pos);
  if(reg.getId() == -1){
    return false;
  }

  reg.setEstado(false);

  return guardar(pos, reg);
}
