#include <iostream>
using namespace std;

#include "Fecha.h"

Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int d, int m, int a){
    _dia = d;
    _mes = m;
    _anio = a;
}

void Fecha::setDia(int d){
    _dia = d;
}

void Fecha::setMes(int m){
    _mes = m;
}

void Fecha::setAnio(int a){
    _anio = a;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::Cargar(){
int dia, mes, anio;

    while (true) {
        cout << "DIA: ";
        cin >> dia;
        cout << "MES: ";
        cin >> mes;
        cout << "ANIO: ";
        cin >> anio;

        if (validarFecha(dia, mes, anio)) {
            _dia = dia;
            _mes = mes;
            _anio = anio;
            break;
        } else {
            cout << "Fecha invalida. Por favor, ingrese una fecha valida." << endl;
        }
    }
}

void Fecha::Mostrar(){
    cout << "FECHA: " << _dia << "/" << _mes << "/" << _anio;
}

bool Fecha::esBisiesto(int a){
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

bool Fecha::validarFecha(int d, int m, int a){

    if (a < 2024 || a > 2025){
        return false;
    }

    if (m < 1 || m > 12){
        return false;

    }

    int diasEnMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // febrero
    if (m == 2 && esBisiesto(a)) {
        diasEnMes[1] = 29;
    }

    return d >= 1 && d <= diasEnMes[m - 1];
}
