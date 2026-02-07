#include <iostream>
using namespace std;

#include "AppMenu.h"

AppMenu::AppMenu(){
  _cantidadOpciones = 7;
}

void AppMenu::mostrarOpciones(){
    cout << endl;
  cout << "--- MENU PRINCIPAL ---" << endl;
  cout << endl;
  cout << " 1 - VENTAS " << endl;
  cout << " 2 - COMPRAS " << endl;
  cout << " 3 - CLIENTES" << endl;
  cout << " 4 - PROVEEDORES" << endl;
  cout << " 5 - ALMACEN" << endl;
  cout << " 6 - CATEGORIAS" <<endl;
  cout << " 7 - EMPRESAS" << endl;
  cout << " 8 - REPORTES" << endl;
  cout << endl;
  cout << "----------------------" << endl;
  cout << endl;
  cout << " 0 - SALIR" << endl;
  cout << endl;
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
    _almacenMenu.mostrar();
    break;
  case 6:
    _categoriaMenu.mostrar();
    break;
  case 7:
    _empresaMenu.mostrar();
    break;
  }
}
