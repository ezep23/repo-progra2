#include <iostream>
using namespace std;

#include "EmpresaMenu.h"

EmpresaMenu::EmpresaMenu(){
  _cantidadOpciones = 4;
}

void EmpresaMenu::mostrarOpciones(){
  cout << "--- MENU EMPRESA ---" << endl;
  cout << "1 - CARGAR" << endl;
  cout << "2 - MOSTRAR" << endl;
  cout << "3 - ACTUALIZAR" << endl;
  cout << "4 - ELIMINAR" << endl;
  cout << "---------------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "--------------------"<<endl;
}

void EmpresaMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _empresaManager.cargar();
  break;
  case 2:
    _empresaManager.mostrar();
  break;
  case 3:
    _empresaManager.actualizar();
  break;
  case 4:
    _empresaManager.eliminar();
  break;
  }
}
