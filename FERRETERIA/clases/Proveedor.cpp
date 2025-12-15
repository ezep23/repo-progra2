#include <iostream>
using namespace std;

#include "string.h"
#include "Persona.h"
#include "Proveedor.h"

Proveedor::Proveedor(){
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    _id=0;
    _idEmpresa=0;
    strcpy(_nombreEmpresa,"");
    strcpy(_razonSocial, "");
    _estado=true;
}

Proveedor::Proveedor(const char * nom, const char *  ape, const char *  tel, const char *  em, int id, int idE, const char* nE, const char* rS, bool est){
    strcpy(_nombre, nom);
    strcpy(_apellido, ape);
    strcpy(_telefono, tel);
    strcpy(_email, em);
    _id=id;
    _idEmpresa=idE;
    strcpy(_nombreEmpresa,nE);
    strcpy(_razonSocial, rS);
    _estado=est;
}


void Proveedor::setId(int id){
    _id = id;
}
void Proveedor::setIdEmpresa(int idEmpresa){
    _idEmpresa = idEmpresa;
}
void Proveedor::setNombreEmpresa(const char * nE){
    strcpy(_nombreEmpresa, nE);
}
void Proveedor::setRazonSocial(const char* razon){
    strcpy(_razonSocial, razon);
}
void Proveedor::setEstado(bool est){
    _estado = est;
}

int Proveedor::getId(){
    return _id;
}
int Proveedor::getIdEmpresa(){
    return _idEmpresa;
}
const char* Proveedor::getNombreEmpresa(){
    return _nombreEmpresa;
}
const char* Proveedor::getRazonSocial(){
    return _razonSocial;
}
bool Proveedor::getEstado(){
    return _estado;
}

void Proveedor::cargar(){
    cout << "------ NUEVO PROVEEDOR ------" << endl;

    cout << "Ingrese su nombre: ";
    cin.ignore();
    cin.getline(_nombre, 50);

    cout << "Ingrese su apellido: ";
    cin.ignore();
    cin.getline(_apellido, 50);

    cout << "Ingrese su telefono: ";
    cin.ignore();
    cin.getline(_telefono, 50);

    cout << "Ingrese su email: ";
    cin.ignore();
    cin.getline(_email, 50);

    cout << "Nombre de empresa: ";
    cin.ignore();
    cin.getline(_nombreEmpresa, 50);

    cout << "Razon social: ";
    cin.ignore();
    cin.getline(_razonSocial, 50);


    cout << "-----------------------------" << endl;
    cout << "# Plantilla de proveedor completa!" << endl;
}

void Proveedor::mostrar(){
    cout << "-----------------------------" << endl;
    cout << "ID: " << _id << endl;
    cout << "ID EMPRESA: " << _idEmpresa << endl;
    cout << "NOMBRE EMPRESA: " << _nombreEmpresa << endl;
    cout << "RAZON SOCIAL: " << _razonSocial << endl;
    cout << "NOMBRE: " << _nombre << endl;
    cout << "APELLIDO: " << _apellido << endl;
    cout << "TELEFONO: " << _telefono << endl;
    cout << "EMAIL: " << _email << endl;
    cout << "-----------------------------" << endl;
}
