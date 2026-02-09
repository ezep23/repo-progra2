#pragma once

#include "Menu.h"
#include "../Managers/InformeManager.h"

class InformeMenu: public Menu{
  public:
    InformeMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
  private:
    InformeManager _informeManager;
};

