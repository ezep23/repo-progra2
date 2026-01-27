#include <iostream>
using namespace std;

#include "ProductoMenu.h"

ProductoMenu::ProductoMenu(){
  _cantidadOpciones = 4;
}

void ProductoMenu::mostrarOpciones(){
  cout << "--- MENU PRODUCTOS ---" << endl;
  cout << "1 - CARGAR" << endl;
  cout << "2 - MOSTRAR" << endl;
  cout << "3 - ACTUALIZAR" << endl;
  cout << "4 - ELIMINAR" << endl;
  cout << "---------------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "--------------------"<<endl;
}

void ProductoMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _productoManager.cargar();
  break;
  case 2:
    _productoManager.mostrar();
  break;
  case 3:
    _productoManager.actualizar();
  break;
  case 4:
    _productoManager.eliminar();
  break;
  }
}
