#include<cstring>
#include <iostream>
using namespace std;

#include "Transaccion.h"

#include "Fecha.h"
#include "Hora.h"

#include "../archivos/Clientes.h"
#include "../archivos/Ventas.h"
#include "../archivos/DetalleVentas.h"

Transaccion::Transaccion(){
    _id = 0;
    _fecha=Fecha(0,0,0);
    _hora=Hora(0,0);
    _idPersona=0;
    _montoTotal=0;
    strcpy(_tipoFactura, "");
}

Transaccion::Transaccion(int id, int idPersona, float montoTotal, Hora hora, Fecha fecha, const char* tipoFactura){

    setIdTransaccion(id);
    setIdPersona(idPersona);
    setMontoTotal(montoTotal);
    setHoraEmision(hora);
    setFechaEmision(fecha);
    setTipoFactura(tipoFactura);
}

void Transaccion::setIdTransaccion(int id){
    _id = id;
}

void Transaccion::setIdPersona(int id){
    _idPersona = id;
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

void Transaccion::setTipoFactura(const char* tipoFactura){
    strcpy(_tipoFactura, tipoFactura);
}

void Transaccion::setEstado(bool estado){
    _estado = estado;
}

int Transaccion::getIdTransaccion(){
    return _id;
}

int Transaccion::getIdPersona(){
    return _idPersona;
}

float Transaccion::getMontoTotal(){
    return _montoTotal;
}

Hora Transaccion::getHoraTransaccion(){
    return _hora;
}

Fecha Transaccion::getFechaTransaccion(){
    return _fecha;
}

void Transaccion::getTipoFactura(){
    cout << _tipoFactura;
}

bool Transaccion::getEstado(){
    return _estado;
}

void Transaccion::mostrar(){
    system("cls");
    cout << " -----------------------------" << endl;
    cout << " ID TRANSACCION: " << _id << endl;
    cout << " ID CLIENTE: " << _idPersona << endl;
    cout << " FECHA EMISION: " << _fecha.getDia() << "/" << _fecha.getMes() << "/" << _fecha.getAnio() << endl;
    cout << " HORA EMISION: " << _hora.getHora() << ":" << _hora.getMinutos() << endl;
    cout << " MONTO TOTAL: " << _montoTotal << endl;
    cout << " TIPO FACTURA: " << _tipoFactura << endl;
    cout << " -----------------------------" << endl;
    system("pause");
}
