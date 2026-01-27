#pragma once
#include "../Archivos/ClienteArchivo.h"


class ClienteManager{
  public:
    ClienteManager();

    void cargar();
    void mostrar();
    void eliminar();
    void actualizar();

  protected:
    void mostrarLista(const Cliente &reg);
  private:
    ClienteArchivo _repo;
};
