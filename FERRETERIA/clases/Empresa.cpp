#include <iostream>
using namespace std;

#include "Empresa.h"
#include "string.h"

Empresa::Empresa(){
    _id = 0;
    strcpy(_nombre, "");
    _estado = true;
}

Empresa::Empresa(int id, const char* nom, bool est){
    _id = id;
    strcpy(_nombre, nom);
    _estado = est;
}

void Empresa::setId(int id){
    _id = id;
}
void Empresa::setNombre(const char * n){
    strcpy(_nombre, n);
}
void Empresa::setEstado(bool est){
    _estado = est;
}

int Empresa::getId(){
    return _id;
}
const char* Empresa::getNombre(){
    return _nombre;
}
bool Empresa::getEstado(){
    return _estado;
}

void Empresa::mostrar(){
    cout << " -------------"<<endl;
    cout << " ID: " << _id <<endl;
    cout << " NOMBRE: " << _nombre << endl;
    cout << " -------------"<<endl;
}
