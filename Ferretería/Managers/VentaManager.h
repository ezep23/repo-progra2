#pragma once
#include "../Archivos/VentaArchivo.h"
#include "../Archivos/ClienteArchivo.h"

class VentaManager
{
  public:
    VentaManager();

    void cargarVenta();
    void mostrarVentas();
    void modificarVenta();
    void eliminarVenta();
  protected:
    void mostrarVentaCompleta(const Transaccion &reg);
  private:
    VentaArchivo _repo;
    ClienteArchivo _repoCliente;
};
