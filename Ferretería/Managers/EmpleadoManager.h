#pragma once
#include "../Archivos/EmpleadoArchivo.h"


class EmpleadoManager{
  public:
    EmpleadoManager();

    void cargar();
    void mostrar();
    void mostrar(int id);
    void eliminar();
    void actualizar();

    bool existeRegistro(int id);
    int obtenerNumeroProximoID();

  protected:
    void mostrarLista(const Empleado &reg);
  private:
    EmpleadoArchivo _repo;
};
