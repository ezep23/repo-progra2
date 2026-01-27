#pragma once

#include "Menu.h"
#include "../Managers/ClienteManager.h"

class ClienteMenu: public Menu{
  public:
    ClienteMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
  private:
    ClienteManager _clienteManager;
};

