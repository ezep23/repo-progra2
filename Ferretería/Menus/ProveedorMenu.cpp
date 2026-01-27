#include <iostream>
using namespace std;

#include "ProveedorMenu.h"

ProveedorMenu::ProveedorMenu(){
  _cantidadOpciones = 4;
}

void ProveedorMenu::mostrarOpciones(){
  cout << "--- MENU PROVEEDORES ---" << endl;
  cout << "1 - CARGAR" << endl;
  cout << "2 - MOSTRAR" << endl;
  cout << "3 - ACTUALIZAR" << endl;
  cout << "4 - ELIMINAR" << endl;
  cout << "---------------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "--------------------"<<endl;
}

void ProveedorMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _proveedorManager.cargar();
  break;
  case 2:
    _proveedorManager.mostrar();
  break;
  case 3:
    _proveedorManager.actualizar();
  break;
  case 4:
    _proveedorManager.eliminar();
  break;
  }
}
