#pragma once
#include "../Archivos/CategoriaArchivo.h"


class CategoriaManager{
  public:
    CategoriaManager();

    void cargar();
    void mostrar();
    void eliminar();
    void actualizar();

  protected:
    void mostrarLista(const Categoria &reg);
  private:
    CategoriaArchivo _repo;
};
