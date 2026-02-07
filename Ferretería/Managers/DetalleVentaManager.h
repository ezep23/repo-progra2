#pragma once
#include "../Archivos/DetalleVentaArchivo.h"
#include "AlmacenManager.h"

class DetalleVentaManager
{
  public:
    DetalleVentaManager();

    int obtenerNumeroRegistros();
    int buscarPosicion(int id);
    DetalleTransaccion traerRegistro(int pos);

    float cargar(int id);

    void mostrar();
    void mostrar(int id);

    void modificar();
    void eliminar();

    void mostrarDetalleCompleto(const DetalleTransaccion &reg);
  private:
    DetalleVentaArchivo _repo;
    AlmacenManager _almacenManager;
};
