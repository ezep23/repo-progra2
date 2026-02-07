#pragma once

#include "Menu.h"

#include "VentaMenu.h"
#include "ClienteMenu.h"
#include "ProveedorMenu.h"
#include "AlmacenMenu.h"
#include "CategoriaMenu.h"
#include "EmpresaMenu.h"

//#include "ReporteMenu.h"

class AppMenu: public Menu{
 public:
    AppMenu();
    void mostrarOpciones();
  protected:

    void ejecutarOpcion(int opcion);

    VentaMenu _ventaMenu;
    ClienteMenu _clienteMenu;
    ProveedorMenu _proveedorMenu;
    AlmacenMenu _almacenMenu;
    CategoriaMenu _categoriaMenu;
    EmpresaMenu _empresaMenu;
    //ReporteMenu _reporteMenu;
};
