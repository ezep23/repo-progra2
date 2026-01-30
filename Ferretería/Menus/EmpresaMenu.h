#pragma once

#include "Menu.h"
#include "../Managers/EmpresaManager.h"

class EmpresaMenu: public Menu{
  public:
    EmpresaMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
  private:
    EmpresaManager _empresaManager;
};

