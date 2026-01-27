#include <iostream>

#include "CategoriaManager.h"
#include "../Entidades/Categoria.h"

#include "../Utils.h"

using namespace std;


CategoriaManager::CategoriaManager(){

}

void CategoriaManager::cargar(){
  string nombre;
  int id;

  id = _repo.getNuevoID();

  cout << "NUEVA CATEGORIA" << endl;
  cout << "Ingrese el nombre: ";
  nombre = cargarCadena();

  if(_repo.guardar(Categoria(id, nombre))){
    cout << "CATEGORIA GUARDADA" << endl;
  }else{
    cout << "NO SE PUDO GUARDAR LA CATEGORIA" << endl;
  }
}

void CategoriaManager::mostrar(){
  int cantidad = _repo.getCantidadRegistros();
  Categoria *vCategoria = new Categoria[cantidad];

  if(vCategoria == nullptr){
    cout << "No se pudo asignar memoria..." << endl;
    exit(-100);
  }

  _repo.leerTodos(vCategoria, cantidad);

  cout << "CLIENTES: " << endl;

  for(int i=0; i<cantidad; i++){
    if(vCategoria[i].getEstado()){
        mostrarLista(vCategoria[i]);
    }
  }
    delete [] vCategoria;
}

void CategoriaManager::eliminar(){
  int id, pos;
  cout << "Ingrese el ID de la categoria: ";
  cin >> id;

  pos = _repo.buscarID(id);
  Categoria reg = _repo.leer(pos);

  reg.setEstado(false);
  cout << "CATEGORIA ELIMINADO" << endl;
}

void CategoriaManager::actualizar(){
  int id, pos, opc;
  cout << "Ingrese el ID del proveedor: ";
  cin >> id;

  pos = _repo.buscarID(id);
  Categoria reg = _repo.leer(pos);

  system("cls");
  cout << "Que desea modificar?" << endl;
  cout << " 1 - NOMBRE" << endl;
  cout << " 0 - SALIR" << endl;
  cout << " Opcion: ";
  cin >> opc;

  switch(opc){
    case 0:{
        return;
     }
    case 1:{
        string nombre;
        nombre = cargarCadena();

        reg.setNombre(nombre);
        _repo.guardar(pos, reg);

        cout << "NOMBRE ACTUALIZADO" << endl;
        return;

     }
  }

}

void CategoriaManager::mostrarLista(const Categoria &reg){
  cout << "ID: " << reg.getId() << endl;
  cout << "ID Empresa: " << reg.getNombre() << endl;
  cout << "------------" <<endl;
}
