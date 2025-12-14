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
}

bool Almacen::reponerStock(int id, int cantidad){
    ArchivoProductos archivo("Productos.dat");
    Producto obj;

    int pos = archivo.obtenerUbicacionProducto(id);
    obj = archivo.obtenerProducto(pos);

    obj.setStock( obj.getStock() + cantidad );
}

void Almacen::consultarStock(){

}

void Almacen::consultarProductosBajoStock(){

}
