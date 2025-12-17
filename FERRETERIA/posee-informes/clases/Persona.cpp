#include <iostream>
#include "string.h"
using namespace std;

#include "Persona.h"


Persona::Persona(){
    strcpy(_nombre,"");
    strcpy(_apellido,"");
    strcpy(_telefono,"");
    strcpy(_email,"");
}

Persona::Persona(const char* nombre, const char* apellido, const char* telefono, const char* email){
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
}

void Persona::setNombre(const char* n){
    strcpy(_nombre, n);
}
void Persona::setApellido(const char* a){
    strcpy(_apellido, a);
}
void Persona::setTelefono(const char* tel){
    strcpy(_telefono, tel);
}
void Persona::setEmail(const char* email){
    strcpy(_email, email);
}

const char* Persona::getNombre(){
    return _nombre;
}
const char* Persona::getApellido(){
    return _apellido;
}
const char* Persona::getTelefono(){
    return _telefono;
}
const char* Persona::getEmail(){
    return _apellido;
}
