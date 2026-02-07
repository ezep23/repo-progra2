
#include "DetalleTransaccion.h"

DetalleTransaccion::DetalleTransaccion(){
    setId(0);
    setIdTransaccion(0);
    setIdProducto(0);
    setCantidad(0);
    setPrecioUnitario(0);
    setEstado(false);
}

DetalleTransaccion::DetalleTransaccion(int id, int idTransaccion, int idProducto, int cantidad, float precioUnitario){
    setId(id);
    setIdTransaccion(idTransaccion);
    setIdProducto(idProducto);
    setCantidad(cantidad);
    setPrecioUnitario(precioUnitario);
    setEstado(true);
}

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

int DetalleTransaccion::getId() const{
    return _id;
}
int DetalleTransaccion::getIdTransaccion() const{
    return _idTransaccion;
}
int DetalleTransaccion::getIdProducto() const{
    return _idProducto;
}
int DetalleTransaccion::getCantidad() const{
    return _cantidad;
}
float DetalleTransaccion::getPrecioUnitario() const{
    return _precioUnitario;
}
bool DetalleTransaccion::getEstado() const{
    return _estado;
}
