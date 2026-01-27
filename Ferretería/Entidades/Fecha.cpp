#include <iostream>
using namespace std;

#include "Fecha.h"

Fecha::Fecha(){
    setDia(0);
    setMes(0);
    setAnio(0);
}

Fecha::Fecha(int d, int m, int a){
    setDia(d);
    setMes(m);
    setAnio(a);
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

    /// si mes es febrero y se valida que a�o esBisiesto() -> true
    if (m == 2 && esBisiesto(a)) {
        diasEnMes[1] = 29; /// se agrega un dia al mes[1] el cual es el segundo mes, o sea febrero
    }

    return d >= 1 && d <= diasEnMes[m - 1];
}
