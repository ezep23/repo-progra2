
#include "Categoria.h"
#include <cstring>
using namespace std;

void Categoria::setId(int id){
    _id = id;
}
void Categoria::setNombre(string n){
    strncpy(_nombre, n.c_str(), 24);
}
void Categoria::setEstado(bool est){
    _estado = est;
}

int Categoria::getId(){
    return _id;
}
string Categoria::getNombre(){
    return string(_nombre);
}
bool Categoria::getEstado(){
    return _estado;
}
