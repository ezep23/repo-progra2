#pragma once
#include "../Archivos/VentaArchivo.h"
#include "../Archivos/ClienteArchivo.h"

class VentaManager
{
  public:
    VentaManager();

    int cargar();
    bool guardar(int pos, Transaccion reg);

    int buscarPosicion(int id);
    Transaccion traerRegistro(int pos);

    int obtenerNumeroRegistros();

    void recaudacionMensual(int anio);
    void recaudacionAnual();

    void mostrar();
    void mostrar(int id);

    void modificar();
    void eliminar();

    void mostrarVentaCompleta(const Transaccion &reg);
  private:
    ClienteArchivo _repoCliente;
    VentaArchivo _repo;
};
