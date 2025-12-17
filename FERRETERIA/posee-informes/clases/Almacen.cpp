#include <iostream>
using namespace std;

#include "Almacen.h"

#include "Producto.h"
#include "../archivos/Productos.h"

bool Almacen::descontarStock(int id, int cantidad){
    ArchivoProductos archivo("Productos.dat");
    Producto obj;

    int pos = archivo.obtenerUbicacionProducto(id);
    obj = archivo.obtenerProducto(pos);

    obj.setStock( obj.getStock() - cantidad );

    bool modificado = archivo.editarProducto(obj, pos);

    if(!modificado){
        cout << " #ERROR - NO SE PUDO DESCONTAR EL STOCK";
        return false;
    }

    cout << "STOCK ACTUALIZADO" << endl;
    system("pause");
    return true;
}

bool Almacen::reponerStock(int id, int cantidad){
    ArchivoProductos archivo("Productos.dat");
    Producto obj;

    int pos = archivo.obtenerUbicacionProducto(id);
    obj = archivo.obtenerProducto(pos);

    obj.setStock( obj.getStock() + cantidad );

    bool modificado = archivo.editarProducto(obj, pos);

    if(!modificado){
        cout << " #ERROR - NO SE PUDO REPONER EL STOCK";
        return false;
    }

    cout << "STOCK ACTUALIZADO" << endl;
    system("pause");
    return true;
}

void Almacen::listarProducto(int id){
    ArchivoProductos archivo("Productos.dat");
    archivo.listarProducto(id);
}

void Almacen::listarProductosCategoria(int idCat){
    ArchivoProductos archivo("Productos.dat");
    archivo.listarProductosCategoria(idCat);
}

void Almacen::listarProductosInactivos(){
    ArchivoProductos archivo("Productos.dat");
    archivo.listarProductosInactivos();
}

void Almacen::listarProductosInactivosCategoria(int idCat){
    ArchivoProductos archivo("Productos.dat");
    archivo.listarProductosInactivosCategoria(idCat);
}

void Almacen::consultarStock(int id){
    ArchivoProductos archivo("Productos.dat");
    archivo.listarProducto(id);
}

void Almacen::consultarProductosBajoStock(){
    ArchivoProductos archivo("Productos.dat");
    archivo.listarProductosBajoStock();
}

void Almacen::consultarProductosBajoStock(int idCat){
    ArchivoProductos archivo("Productos.dat");
    archivo.listarProductosBajoStock(idCat);
}

void Almacen::consultarProductosProveedor(int idProv){
    ArchivoProductos archivo("Productos.dat");
    archivo.listarProductosProveedor(idProv);
}

void Almacen::consultarProductosMismoNombre(const char* nombre){
    ArchivoProductos archivo("Productos.dat");
    archivo.listarProductosMismoNombre(nombre);
}
void Almacen::consultarProductoMimasMarca(const char* marca){
    ArchivoProductos archivo("Productos.dat");
    archivo.listarProductosMismaMarca(marca);
}
