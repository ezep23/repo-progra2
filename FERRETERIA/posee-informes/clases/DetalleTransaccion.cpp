#include <iostream>
using namespace std;

#include "DetalleTransaccion.h"

#include "../clases/Almacen.h"
#include "../archivos/Productos.h"
#include "../archivos/DetalleVentas.h"

void DetalleTransaccion::setId(int id){
    _id = id;
}
void DetalleTransaccion::setIdTransaccion(int id){
    _idTransaccion = id;
}
void DetalleTransaccion::setIdProducto(int id){
    _idProducto = id;
}
void DetalleTransaccion::setCantidad(int cant){
    _cantidad = cant;
}
void DetalleTransaccion::setPrecioUnitario(float prec){
    _precioUnitario = prec;
}
void DetalleTransaccion::setEstado(bool est){
    _estado = est;
}

int DetalleTransaccion::getId(){
    return _id;
}
int DetalleTransaccion::getIdTransaccion(){
    return _idTransaccion;
}
int DetalleTransaccion::getIdProducto(){
    return _idProducto;
}
int DetalleTransaccion::getCantidad(){
    return _cantidad;
}
float DetalleTransaccion::getPrecioUnitario(){
    return _precioUnitario;
}
bool DetalleTransaccion::getEstado(){
    return _estado;
}

void DetalleTransaccion::cargar(int idTransaccion){

    if(idTransaccion <= 0){
        cout << "ERROR, FALTA ID DE TRANSACCIÓN" << endl;
        system("pause");
        return;
    }

    _estado = true;
    _idTransaccion = idTransaccion;

    Almacen almacen;
    ArchivoProductos archivo("Productos.dat");
    Producto producto;

    cout << "ID de producto: ";
    cin >> _idProducto;

    while(!archivo.validarDisponibilidad(_idProducto)){
        cout << "Producto inexistente u agotado" << endl;
        cout << "Ingrese otro: ";
        cin >> _idProducto;
    }

    int pos = archivo.obtenerUbicacionProducto(_idProducto);
    producto = archivo.obtenerProducto(pos);
    _precioUnitario = producto.getPrecio();
    cout << "PRECIO UNITARIO DEL PRODUCTO: " << _precioUnitario << endl;
    cout << "STOCK DISPONIBLE: " << producto.getStock() << endl;

    cout << "CANTIDAD DEL PRODUCTO: ";
    cin >> _cantidad;

    while (_cantidad <= 0 || _cantidad > producto.getStock()) {
    if (_cantidad <= 0) {
        cout << "La cantidad de producto no puede ser cero o negativa." << endl;
        } else if (_cantidad > producto.getStock()) {
        cout << "Cantidad ingresada mayor al stock disponible." << endl;
        }
        cout << "CANTIDAD DE PRODUCTO: ";
        cin >> _cantidad;
    }

    almacen.descontarStock(_idProducto, _cantidad);
}

void DetalleTransaccion::mostrar(){
    cout << endl;
    cout << "---" << "ID Detalle: " << _id << "--------------" << endl;
    cout << "ID Articulo: " << _idProducto << endl;
    cout << "Precio unitario: " << _precioUnitario << endl;
    cout << "Cantidad: " << _cantidad << endl;
    cout << endl;
}
