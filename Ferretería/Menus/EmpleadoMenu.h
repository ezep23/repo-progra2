#pragma once

#include "Menu.h"
#include "../Managers/EmpleadoManager.h"

class EmpleadoMenu: public Menu{
  public:
    EmpleadoMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
  private:
    EmpleadoManager _empleadoManager;
};

