
#include <iostream>
using namespace std;

#include "Hora.h"

Hora::Hora(){
 _hora = 0;
 _minutos = 0;
}

Hora::Hora(int h, int m){
 _hora = h;
 _minutos = m;
}

void Hora::setHora(int h){
    _hora = h;
}
void Hora::setMinutos(int m){
    _minutos = m;
}

int Hora::getHora(){
    return _hora;
}
int Hora::getMinutos(){
    return _minutos;
}

bool Hora::validarHora(int hora, int minutos){

    if (hora < 0 || hora > 24){
        return false;
    }

    if (minutos < 0 || minutos > 59 ){
        return false;
    }

    return true;
}

void Hora::cargar(){
    int hora, minutos;

    while (true) {
        cout << "HORA: ";
        cin >> hora;
        cout << "MINUTOS: ";
        cin >> minutos;

        if (validarHora(hora, minutos)) {
            _hora = hora;
            _minutos = minutos;
            break;
        } else {
            cout << "Esa hora no existe, ingrese nuevamente!" << endl;
        }
    }
}

void Hora::mostrar(){
    cout << "HORA: " << _hora << ":" << _minutos;
}

