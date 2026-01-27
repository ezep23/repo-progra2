
#include "DetalleTransaccion.h"

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
