#pragma once
#include "../Archivos/ProveedorArchivo.h"
#include "EmpresaManager.h"


class ProveedorManager{
  public:
    ProveedorManager();

    void cargar();
    void mostrar();
    void eliminar();
    void actualizar();

    bool existeProveedor(int id);

  protected:
    void mostrarLista(const Proveedor &reg);
  private:
    ProveedorArchivo _repo;
    EmpresaManager _empresaManager;
};
