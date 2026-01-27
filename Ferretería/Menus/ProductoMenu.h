#pragma once

#include "Menu.h"
#include "../Managers/ProductoManager.h"

class ProductoMenu: public Menu{
  public:
    ProductoMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

    ProductoManager _productoManager;
};
