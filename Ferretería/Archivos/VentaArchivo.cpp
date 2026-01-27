#include <iostream>
using namespace std;

#include "VentaArchivo.h"

VentaArchivo::VentaArchivo(std::string nombreArchivo)
  : _nombreArchivo(nombreArchivo)
{
  /// validar
}

bool VentaArchivo::guardar(const Transaccion &registro){
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  result = fwrite(&registro, sizeof(Transaccion), 1, pFile);

  fclose(pFile);

  return result;
}

bool VentaArchivo::guardar(int pos, const Transaccion &registro){
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb+");

  if(pFile == nullptr){
    return false;
  }

  fseek(pFile, sizeof(Transaccion)*pos, SEEK_SET);

  result = fwrite(&registro, sizeof(Transaccion), 1, pFile);

  fclose(pFile);

  return result;
}

Transaccion VentaArchivo::leer(int pos){
  Transaccion registro;
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr){
    registro.setIdTransaccion(-1);
    return registro;
  }

  fseek(pFile, sizeof(Transaccion)*pos, SEEK_SET);

  fread(&registro, sizeof(Transaccion), 1, pFile);

  fclose(pFile);

  return registro;
}



int VentaArchivo::leerTodos(Transaccion ventas[], int cantidad){
  int result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr)
  {
    return 0;
  }

  result = fread(ventas, sizeof(Transaccion), cantidad, pFile);

  fclose(pFile);

  return result;
}

int VentaArchivo::getCantidadRegistros()
{
  int cantidad;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr)
  {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  cantidad = ftell(pFile) / sizeof(Transaccion);

  fclose(pFile);

  return cantidad;
}

int VentaArchivo::getNuevoID(){
  return getCantidadRegistros() + 1;
}


int VentaArchivo::buscarID(int id){
  Transaccion registro;
  FILE *pFile;
  int pos = -1;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr)
  {
    return pos;
  }

  while(fread(&registro, sizeof(Transaccion), 1, pFile)){
    if(registro.getIdTransaccion() == id){
      pos = ftell(pFile) / sizeof(Transaccion) - 1;
      break;
    }
  }

  fclose(pFile);

  return pos;
}

bool VentaArchivo::eliminar(int pos){
  Transaccion registro = leer(pos);
  if(registro.getIdTransaccion() == -1){
    return false;
  }

  registro.setEstado(false);

  return guardar(pos, registro);
}

