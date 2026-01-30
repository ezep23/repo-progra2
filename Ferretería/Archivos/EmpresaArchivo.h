#pragma once
#include <string>
#include "../Entidades/Empresa.h"

class EmpresaArchivo{
  public:
    EmpresaArchivo(std::string nombreArchivo = "Empresas.dat");
    bool guardar(const Empresa &reg);
    bool guardar(int pos, const Empresa &reg);

    int buscarID(int id);
    Empresa leer(int pos);

    bool eliminar(int pos);

    int leerTodos(Empresa regs[], int cantidad);
    int getCantidadRegistros();
    int getNuevoID();

  private:
    std::string _nombreArchivo;
};
