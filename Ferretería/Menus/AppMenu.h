#pragma once

#include "Menu.h"

#include "VentaMenu.h"
#include "ClienteMenu.h"
#include "ProveedorMenu.h"
#include "ProductoMenu.h"
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
    ProductoMenu _productoMenu;
    CategoriaMenu _categoriaMenu;
    EmpresaMenu _empresaMenu;
    //ReporteMenu _reporteMenu;
};
