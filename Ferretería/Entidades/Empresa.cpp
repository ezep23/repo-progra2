#include "Empresa.h"
#include "string.h"
using namespace std;

Empresa::Empresa(){
    setId(0);
    setRazonSocial("");
    setEstado(false);
}

Empresa::Empresa(int id, string rS){
    setId(id);
    setRazonSocial(rS);
    setEstado(true);
}

void Empresa::setId(int id){
    _id = id;
}
void Empresa::setRazonSocial(string rS){
    strncpy(_razonSocial, rS.c_str(), 49);
}
void Empresa::setEstado(bool est){
    _estado = est;
}

int Empresa::getId() const{
    return _id;
}
string Empresa::getRazonSocial() const{
    return  string(_razonSocial);
}
bool Empresa::getEstado() const{
    return _estado;
}
