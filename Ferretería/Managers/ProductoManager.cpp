#include <iostream>

#include "ProductoManager.h"
#include "../Entidades/Producto.h"

#include "../Utils.h"

using namespace std;


ProductoManager::ProductoManager(){

}

void ProductoManager::cargar(){

}

void ProductoManager::mostrar(){
  int cantidad = _repo.getCantidadRegistros();
  Producto *vProducto = new Producto[cantidad];

  if(vProducto == nullptr){
    cout << "No se pudo asignar memoria..." << endl;
    exit(-100);
  }

  _repo.leerTodos(vProducto, cantidad);

  cout << "PRODUCTOS: " << endl;

  for(int i=0; i<cantidad; i++){
    if(vProducto[i].getEstado()){
        mostrarLista(vProducto[i]);
    }
  }
    delete [] vProducto;
}

void ProductoManager::eliminar(){
  int id, pos;
  cout << "Ingrese el ID del producto: ";
  cin >> id;

  pos = _repo.buscarID(id);
  Producto reg = _repo.leer(pos);

  reg.setEstado(false);
  cout << "PRODUCTO ELIMINADO" << endl;
}

void ProductoManager::actualizar(){

}



void ProductoManager::mostrarLista(const Producto &reg){
  cout << "ID: " << reg.getId() << endl;
  cout << "ID Categoria: " << reg.getIdCategoria() << endl;
  cout << "Nombre: "<< reg.getNombre() << endl;
  cout << "Marca: " << reg.getMarca() << endl;
  cout << "Precio: " << reg.getPrecio() << endl;
  cout << "Stock: " << reg.getStock() << endl;
  cout << "------------" <<endl;
}

