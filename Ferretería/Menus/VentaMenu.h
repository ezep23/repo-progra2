#pragma once

#include "Menu.h"
#include "../Managers/VentasManager.h"

class VentaMenu: public Menu{
  public:
    VentaMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

    VentasManager _ventasManager;
};
