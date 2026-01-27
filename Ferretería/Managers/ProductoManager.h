#pragma once
#include "../Archivos/ProductoArchivo.h"


class ProductoManager{
  public:
    ProductoManager();

    void cargar();
    void mostrar();
    void eliminar();
    void actualizar();

  protected:
    void mostrarLista(const Producto &reg);
  private:
    ProductoArchivo _repo;
};
