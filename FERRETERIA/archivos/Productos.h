#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include "string.h"
#include "../clases/Producto.h"

class ArchivoProductos{
 private:
    char _nombre[30];
    int _tamProducto;
 public:
    ArchivoProductos(const char *n="Productos.dat"){
        strcpy(_nombre, n);
        _tamProducto=sizeof(Producto);
    }

    int contarProductos();
    int generarNuevoID();

    bool validarNombre(const char* nombre);
    bool validarDisponibilidad(int id);

    bool guardarProducto(Producto obj);
    int editarProducto(Producto obj, int pos);

    Producto obtenerProducto(int pos);
    int obtenerUbicacionProducto(int id);

    bool listarProductos();
    bool listarProductosInactivos();

    bool bajaProducto(int id);
    bool altaProducto(int id);

};

#endif // PRODUCTOS_H_INCLUDED
