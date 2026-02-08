#pragma once
#include "../Archivos/CompraArchivo.h"
#include "../Archivos/EmpleadoArchivo.h"

class CompraManager
{
  public:
    CompraManager();

    int cargar();
    bool guardar(int pos, Transaccion reg);

    int buscarPosicion(int id);
    Transaccion traerRegistro(int pos);

    int obtenerNumeroRegistros();

    void mostrar();
    void mostrar(int id);

    void modificar();
    void eliminar();

    void mostrarCompraCompleta(const Transaccion &reg);
  private:
    EmpleadoArchivo _repoEmpleado;
    CompraArchivo _repo;
};
