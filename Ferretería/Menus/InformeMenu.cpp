#include <iostream>
using namespace std;

#include "InformeMenu.h"

InformeMenu::InformeMenu(){
  _cantidadOpciones = 4;
}

void InformeMenu::mostrarOpciones(){
  cout << "--- MENU INFORMES ---" << endl;
  cout << "1 - RECAUDACION MENSUAL DE UN ANIO " << endl;
  cout << "2 - RECAUDACION ANUAL" << endl;
  cout << "---------------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "--------------------"<<endl;
}

void InformeMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _informeManager.recaudacionMensual();
  break;
  case 2:
    _informeManager.recaudacionAnual();
  break;
  case 3:
    //_informeManager.actualizar();
  break;
  case 4:
    //_informeManager.eliminar();
  break;
  }
}
