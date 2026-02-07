#include <iostream>
using namespace std;

#include "AlmacenMenu.h"

AlmacenMenu::AlmacenMenu(){
  _cantidadOpciones = 4;
}

void AlmacenMenu::mostrarOpciones(){
  cout << "--- MENU ALMACEN ---" << endl;
  cout << "1 - CARGAR PRODUCTO" << endl;
  cout << "2 - MOSTRAR PRODUCTO" << endl;
  cout << "3 - ACTUALIZAR PRODUCTO" << endl;
  cout << "4 - ELIMINAR PRODUCTO" << endl;
  cout << "---------------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "--------------------"<<endl;
}

void AlmacenMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _almacenManager.cargarProducto();
  break;
  case 2:
    _almacenManager.mostrarProducto();
  break;
  case 3:
    _almacenManager.actualizarProducto();
  break;
  case 4:
    _almacenManager.eliminarProducto();
  break;
  }
}
