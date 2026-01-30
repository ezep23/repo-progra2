#include <iostream>

#include "EmpresaManager.h"
#include "../Entidades/Empresa.h"

#include "../Utils.h"

using namespace std;


EmpresaManager::EmpresaManager(){

}

void EmpresaManager::cargar(){
  string razonSocial;
  int id;

  id = _repo.getNuevoID();

  cout << "NUEVA EMPRESA" << endl;
  cout << "Ingrese la razon social: ";
  razonSocial = cargarCadena();

  if(_repo.guardar(Empresa(id, razonSocial))){
    cout << "EMPRESA GUARDADA" << endl;
  }else{
    cout << "NO SE PUDO GUARDAR LA EMPRESA" << endl;
  }
}

void EmpresaManager::mostrar(){
  int cantidad = _repo.getCantidadRegistros();
  Empresa *vEmpresa = new Empresa[cantidad];

  if(vEmpresa == nullptr){
    cout << "No se pudo asignar memoria..." << endl;
    exit(-100);
  }

  _repo.leerTodos(vEmpresa, cantidad);

  cout << "EMPRESAS: " << endl;

  for(int i=0; i<cantidad; i++){
    if(vEmpresa[i].getEstado()){
        mostrarLista(vEmpresa[i]);
    }
  }
    delete [] vEmpresa;
}

void EmpresaManager::eliminar(){
  int id, pos;
  cout << "Ingrese el ID de la empresa: ";
  cin >> id;

  pos = _repo.buscarID(id);
  if(_repo.eliminar(pos)){
    cout << "REGISTRO ELIMINADO" << endl;
    return;
  }

  cout << "NO SE PUDO ELIMINAR EL REGISTRO" << endl;
  return;
}

void EmpresaManager::actualizar(){
  int id, pos, opc;
  cout << "Ingrese el ID de la empresa: ";
  cin >> id;

  pos = _repo.buscarID(id);
  Empresa reg = _repo.leer(pos);

  system("cls");
  cout << "Que desea modificar?" << endl;
  cout << " 1 - RAZON SOCIAL" << endl;
  cout << " 0 - SALIR" << endl;
  cout << " Opcion: ";
  cin >> opc;

  switch(opc){
    case 0:{
        return;
     }
    case 1:{
        string razonSocial;

        cout << "Ingrese la nueva razon social: ";

        razonSocial = cargarCadena();

        reg.setRazonSocial(razonSocial);
        _repo.guardar(pos, reg);

        cout << "RAZON SOCIAL ACTUALIZADA" << endl;
        return;

     }
  }

}

void EmpresaManager::mostrarLista(const Empresa &reg){
  cout << "ID: " << reg.getId() << endl;
  cout << "Razon social: " << reg.getRazonSocial() << endl;
  cout << "------------" <<endl;
}
