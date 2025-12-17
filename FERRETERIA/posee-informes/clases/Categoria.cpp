#include <iostream>
using namespace std;

#include "Categoria.h"
#include "string.h"

void Categoria::setId(int id){
    _id = id;
}
void Categoria::setNombre(const char* n){
    strcpy(_nombre, n);
}
void Categoria::setEstado(bool est){
    _estado = est;
}

int Categoria::getId(){
    return _id;
}
const char* Categoria::getNombre(){
    return _nombre;
}
bool Categoria::getEstado(){
    return _estado;
}

void Categoria::cargar(int){
    system("cls");
    cout << " -----------------------------------";
    cout << " Ingrese el nombre de la categoria: ";
    cin.getline(_nombre, 25);

    system("cls");
    cout << " # Categoria cargada correctamente!";
    mostrar();
}

void Categoria::mostrar(){
    cout << " -------------------------";
    cout << " ID: " << _id << endl;
    cout << " NOMBRE: " << _nombre << endl;
    cout << " -------------------------";
}
