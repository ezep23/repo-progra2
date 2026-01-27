#pragma once

#include "Menu.h"
#include "../Managers/VentaManager.h"

class VentaMenu: public Menu{
  public:
    VentaMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

    VentaManager _ventaManager;
};
