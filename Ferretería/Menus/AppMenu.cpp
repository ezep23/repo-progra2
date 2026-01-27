#include <iostream>
using namespace std;

#include "AppMenu.h"

AppMenu::AppMenu(){
  _cantidadOpciones = 5;
}

void AppMenu::mostrarOpciones(){
  cout << "--- MENU PRINCIPAL ---" << endl;
  cout << "1 - VENTAS " << endl;
  cout << "2 - COMPRAS " << endl;
  cout << "3 - CLIENTES" << endl;
  cout << "4 - PROVEEDORES" << endl;
  cout << "5 - PRODUCTOS" << endl;
  cout << "6 - CATEGORIAS" <<endl;
  cout << "----------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "----------------------"<<endl;
}

void AppMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _ventaMenu.mostrar();
  break;
  case 2:
    //_personalMenu.mostrar();
    break;
  case 3:
    _clienteMenu.mostrar();
    break;
  case 4:
    _proveedorMenu.mostrar();
    break;
  case 5:
    _productoMenu.mostrar();
    break;
  case 6:
    _categoriaMenu.mostrar();
    break;
  }
}
