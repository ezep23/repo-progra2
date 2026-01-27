#pragma once

#include "Menu.h"
#include "../Managers/ProveedorManager.h"

class ProveedorMenu: public Menu{
  public:
    ProveedorMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
  private:
    ProveedorManager _proveedorManager;
};

