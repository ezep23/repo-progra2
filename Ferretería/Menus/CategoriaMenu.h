#pragma once

#include "Menu.h"
#include "../Managers/CategoriaManager.h"

class CategoriaMenu: public Menu{
  public:
    CategoriaMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
  private:
    CategoriaManager _categoriaManager;
};

