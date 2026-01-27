#pragma once
#include "../Archivos/ProveedorArchivo.h"


class ProveedorManager{
  public:
    ProveedorManager();

    void cargar();
    void mostrar();
    void eliminar();
    void actualizar();

  protected:
    void mostrarLista(const Proveedor &reg);
  private:
    ProveedorArchivo _repo;
};
