#include <iostream>
using namespace std;

#include "ProveedorArchivo.h"

ProveedorArchivo::ProveedorArchivo(std::string nombreArchivo): _nombreArchivo(nombreArchivo){

}

bool ProveedorArchivo::guardar(const Proveedor &reg){
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  result = fwrite(&reg, sizeof(Proveedor), 1, pFile);

  fclose(pFile);

  return result;
}

bool ProveedorArchivo::guardar(int pos, const Proveedor &registro){
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb+");

  if(pFile == nullptr){
    return false;
  }

  fseek(pFile, sizeof(Proveedor)*pos, SEEK_SET);

  result = fwrite(&registro, sizeof(Proveedor), 1, pFile);

  fclose(pFile);

  return result;
}

int ProveedorArchivo::buscarID(int id){
  Proveedor reg;
  FILE *pFile;
  int pos = -1;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return pos;
  }

  while(fread(&reg, sizeof(Proveedor), 1, pFile)){
    if(reg.getId() == id){
      pos = ftell(pFile) / sizeof(Proveedor) - 1;
      break;
    }
  }

  fclose(pFile);

  return pos;
}

Proveedor ProveedorArchivo::leer(int pos){
  Proveedor reg;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    reg.setId(-1);
    return reg;
  }

  fseek(pFile, sizeof(Proveedor)*pos, SEEK_SET);

  fread(&reg, sizeof(Proveedor), 1, pFile);

  fclose(pFile);

  return reg;
}

int ProveedorArchivo::leerTodos(Proveedor regs[], int cantidad){
  int result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return 0;
  }

  result = fread(regs, sizeof(Proveedor), cantidad, pFile);

  fclose(pFile);

  return result;
}

int ProveedorArchivo::getCantidadRegistros(){
  int cantidad;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  cantidad = ftell(pFile) / sizeof(Proveedor);

  fclose(pFile);

  return cantidad;
}

int ProveedorArchivo::getNuevoID(){
    return getCantidadRegistros() + 1;
}
