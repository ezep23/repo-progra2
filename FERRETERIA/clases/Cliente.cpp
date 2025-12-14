#include <iostream>
using namespace std;

#include "Cliente.h"
#include "Persona.h"

void Cliente::setId(int id){
    _id = id;
}
void Cliente::setDni(int dni){
    _dni = dni;
}

void Cliente::setEstado(bool est){
    _estado = est;
}

int Cliente::getId(){
    return _id;
}

int Cliente::getDni(){
    return _dni;
}

bool Cliente::getEstado(){
    return _estado;
}

void Cliente::cargar(){
    system("cls");
    cout <<  "------ NUEVO PROVEEDOR ------" << endl;

    cout << " Ingrese su nombre: ";
    cin.ignore();
    cin.getline(_nombre, 50);

    cout << " Ingrese su apellido: ";
    cin.ignore();
    cin.getline(_apellido, 50);

    cout << " Ingrese su telefono: ";
    cin.ignore();
    cin.getline(_telefono, 50);

    cout << " Ingrese su email: ";
    cin.ignore();
    cin.getline(_email, 50);

    cout << " -----------------------------" << endl;
    cout << " # Plantilla de cliente completa!" << endl;
    system("pause");
}

void Cliente::mostrar(){
    system("cls");
    cout << " -----------------------------" << endl;
    cout << " ID: " << _id << endl;
    cout << " NOMBRE: " << _nombre << endl;
    cout << " APELLIDO: " << _apellido << endl;
    cout << " TELEFONO: " << _telefono << endl;
    cout << " EMAIL: " << _email << endl;
    cout << " -----------------------------" << endl;
    system("pause");
}
