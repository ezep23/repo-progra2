#pragma once

#include "Menu.h"
#include "../Managers/ComprasManager.h"

class CompraMenu: public Menu{
  public:
    CompraMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

    ComprasManager _comprasManager;
};
