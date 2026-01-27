#include <iostream>
using namespace std;

#include "VentaMenu.h"

VentaMenu::VentaMenu(){
  _cantidadOpciones = 4;
}

void VentaMenu::mostrarOpciones(){
  cout << "--- MENU VENTA ---" << endl;
  cout << "1 - CREAR VENTA " << endl;
  cout << "2 - MOSTRAR VENTA " << endl;
  cout << "3 - MODIFICAR VENTA " << endl;
  cout << "4 - ELIMINAR VENTA " << endl;
  cout << "---------------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "--------------------"<<endl;
}

void VentaMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _ventaManager.cargarVenta();
  break;
  case 2:
    _ventaManager.mostrarVentas();
  break;
  case 3:
    _ventaManager.modificarVenta();
  break;
  case 4:
    _ventaManager.eliminarVenta();
  break;
  }
}
