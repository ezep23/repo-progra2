#pragma once
#include "../Archivos/EmpresaArchivo.h"


class EmpresaManager{
  public:
    EmpresaManager();

    void cargar();
    void mostrar();
    void eliminar();
    void actualizar();

  protected:
    void mostrarLista(const Empresa &reg);
  private:
    EmpresaArchivo _repo;
};
