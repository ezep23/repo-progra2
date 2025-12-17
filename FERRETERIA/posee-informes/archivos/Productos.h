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

    bool validarIdExiste(int id);
    void validarArchivoExiste();
    bool validarNombre(const char* nombre);
    bool validarDisponibilidad(int id);

    bool guardarProducto(Producto obj);
    bool editarProducto(Producto obj, int pos);

    Producto obtenerProducto(const char* nombre);
    Producto obtenerProducto(int pos);
    int obtenerUbicacionProducto(int id);

    void listarProductosMismaMarca(const char* marca);
    void listarProductosMismoNombre(const char* nombre);
    void listarProducto(int id);
    void listarProductoStock(int id);
    void listarProductosBajoStock();
    void listarProductosBajoStock(int idCat);

    void listarProductos();
    void listarProductosCategoria(int idCat);
    void listarProductosInactivos();
    void listarProductosInactivosCategoria(int idCat);
    void listarProductosProveedor(int id);

    bool bajaProducto(int id);
    bool altaProducto(int id);

    bool borrar();
};

#endif // PRODUCTOS_H_INCLUDED
