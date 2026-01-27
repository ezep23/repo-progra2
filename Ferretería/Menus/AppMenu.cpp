#include <iostream>
using namespace std;

#include "AppMenu.h"

AppMenu::AppMenu(){
  _cantidadOpciones = 3;
}

void AppMenu::mostrarOpciones(){
  cout << "--- MENU PRINCIPAL ---" << endl;
  cout << "1 - VENTAS " << endl;
  cout << "2 - COMPRAS " << endl;
  cout << "3 - CLIENTES" << endl;
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
    //_reporteMenu.mostrar();
    break;
  }
}
