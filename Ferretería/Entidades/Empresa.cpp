#include "Empresa.h"
#include "string.h"
using namespace std;

Empresa::Empresa(){
    setId(0);
    setNombre("");
    setEstado(false);
}

Empresa::Empresa(int id, string nom, bool est){
    setId(id);
    setNombre(nom);
    setEstado(est);
}

void Empresa::setId(int id){
    _id = id;
}
void Empresa::setNombre(string n){
    strncpy(_nombre, n.c_str(), 19);
}
void Empresa::setEstado(bool est){
    _estado = est;
}

int Empresa::getId() const{
    return _id;
}
string Empresa::getNombre() const{
    return  string(_nombre);
}
bool Empresa::getEstado() const{
    return _estado;
}
