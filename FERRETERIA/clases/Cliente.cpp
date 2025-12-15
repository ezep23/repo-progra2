#include <iostream>
using namespace std;

#include "Cliente.h"
#include "Persona.h"

#include "string.h"

Cliente::Cliente(){
    _id = 0;
    _dni = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    _estado=true;
}

Cliente::Cliente(const char * nombre, const char *  apellido, const char *  telefono, const char *  email, int id, int dni, bool est){
    _id = id;
    _dni = dni;
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    strcpy(_telefono, telefono);
    strcpy(_email, email);
    _estado = est;
}

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
    cin.getline(_nombre, 50);

    cout << " Ingrese su apellido: ";
    cin.getline(_apellido, 50);

    cout << " Ingrese su DNI: ";
    cin >> _dni;

    cout << " Ingrese su telefono: ";
    cin.getline(_telefono, 50);

    cout << " Ingrese su email: ";
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
    cout << " DNI: " << _dni << endl;
    cout << " TELEFONO: " << _telefono << endl;
    cout << " EMAIL: " << _email << endl;
    cout << " -----------------------------" << endl;
    system("pause");
}


