
#include "Categoria.h"
#include <cstring>

using namespace std;

Categoria::Categoria(){
    setId(0);
    setNombre("");
}

Categoria::Categoria(int id, string nombre){
    setId(id);
    setNombre(nombre);
}

void Categoria::setId(int id){
    _id = id;
}
void Categoria::setNombre(string n){
    strncpy(_nombre, n.c_str(), 24);
}
void Categoria::setEstado(bool est){
    _estado = est;
}

int Categoria::getId() const{
    return _id;
}
string Categoria::getNombre() const{
    return string(_nombre);
}
bool Categoria::getEstado() const{
    return _estado;
}
