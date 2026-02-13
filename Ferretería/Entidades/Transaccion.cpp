#include<cstring>
#include <iostream>
using namespace std;

#include "Transaccion.h"

#include "Fecha.h"
#include "Hora.h"

Transaccion::Transaccion(){
    setIdTransaccion(0);
    Fecha();
    Hora();
    setIdPersona(0);
    setIdEmpleado(0);
    setMontoTotal(0);
    setTipoFactura('X');
    setEstado(false);
}

Transaccion::Transaccion(int id, int idPersona, int idEmpleado, float montoTotal, Hora hora, Fecha fecha, char tipoFactura){

    setIdTransaccion(id);
    setIdPersona(idPersona);
    setIdEmpleado(idEmpleado);
    setMontoTotal(montoTotal);
    setHoraEmision(hora);
    setFechaEmision(fecha);
    setTipoFactura(tipoFactura);
    setEstado(true);
}

void Transaccion::setIdTransaccion(int id){
    _id = id;
}

void Transaccion::setIdPersona(int id){
    _idPersona = id;
}

void Transaccion::setIdEmpleado(int id){
    _idEmpleado = id;
}

void Transaccion::setMontoTotal(float monto){
    _montoTotal = monto;
}

void Transaccion::setHoraEmision(Hora h){
    _hora = h;
}

void Transaccion::setFechaEmision(Fecha f){
    _fecha = f;
}

void Transaccion::setTipoFactura(char tipoFactura){
    _tipoFactura = tipoFactura;
}

void Transaccion::setEstado(bool estado){
    _estado = estado;
}

int Transaccion::getIdTransaccion() const{
    return _id;
}

int Transaccion::getIdPersona() const{
    return _idPersona;
}

int Transaccion::getIdEmpleado() const{
    return _idEmpleado;
}

float Transaccion::getMontoTotal() const{
    return _montoTotal;
}

Hora Transaccion::getHoraTransaccion() const{
    return _hora;
}

Fecha Transaccion::getFechaTransaccion() const{
    return _fecha;
}

char Transaccion::getTipoFactura() const{
    return _tipoFactura;
}

bool Transaccion::getEstado() const{
    return _estado;
}

