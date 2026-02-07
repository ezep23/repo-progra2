#pragma once

#include "Menu.h"
#include "../Managers/AlmacenManager.h"

class AlmacenMenu: public Menu{
  public:
    AlmacenMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

    AlmacenManager _almacenManager;
};
