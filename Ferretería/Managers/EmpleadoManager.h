#pragma once
#include "../Archivos/EmpleadoArchivo.h"


class EmpleadoManager{
  public:
    EmpleadoManager();

    void cargar();
    void mostrar();
    void eliminar();
    void actualizar();

  protected:
    void mostrarLista(const Empleado &reg);
  private:
    EmpleadoArchivo _repo;
};
