#pragma once

#include "Menu.h"

#include "VentaMenu.h"
#include "ClienteMenu.h"
//#include "ReporteMenu.h"

class AppMenu: public Menu{
 public:
    AppMenu();
    void mostrarOpciones();
  protected:

    void ejecutarOpcion(int opcion);

    VentaMenu _ventaMenu;
    ClienteMenu _clienteMenu;
    //ReporteMenu _reporteMenu;
};
