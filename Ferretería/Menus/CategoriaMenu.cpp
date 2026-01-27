#include <iostream>
using namespace std;

#include "CategoriaMenu.h"

CategoriaMenu::CategoriaMenu(){
  _cantidadOpciones = 4;
}

void CategoriaMenu::mostrarOpciones(){
  cout << "--- MENU CATEGORIAS ---" << endl;
  cout << "1 - CARGAR" << endl;
  cout << "2 - MOSTRAR" << endl;
  cout << "3 - ACTUALIZAR" << endl;
  cout << "4 - ELIMINAR" << endl;
  cout << "---------------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "--------------------"<<endl;
}

void CategoriaMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _categoriaManager.cargar();
  break;
  case 2:
    _categoriaManager.mostrar();
  break;
  case 3:
    _categoriaManager.actualizar();
  break;
  case 4:
    _categoriaManager.eliminar();
  break;
  }
}
