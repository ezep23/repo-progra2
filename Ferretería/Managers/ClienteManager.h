#pragma once
#include "../Archivos/ClienteArchivo.h"


class ClienteManager{
  public:
    ClienteManager();

    void cargar();
    void mostrar();
    void mostrar(int id);
    void eliminar();
    void actualizar();

    bool existeRegistro(int id);

  protected:
    void mostrarLista(const Cliente &reg);
  private:
    ClienteArchivo _repo;
};
