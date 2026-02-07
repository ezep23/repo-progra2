#pragma once
#include "../Archivos/ProductoArchivo.h"
#include "ProveedorManager.h"
#include "CategoriaManager.h"

class AlmacenManager{
  public:
    AlmacenManager();

    void cargarProducto();
    void mostrarProducto();
    void eliminarProducto();
    void actualizarProducto();

    int obtenerStock(int id);
    float obtenerPrecio(int id);

    void actualizarStock(int id, int cantidad);

    bool validarID(int id);

  protected:
    void mostrarLista(const Producto &reg);
  private:
    ProductoArchivo _repo;
    ProveedorManager _proveedorManager;
    CategoriaManager _categoriaManager;
};
