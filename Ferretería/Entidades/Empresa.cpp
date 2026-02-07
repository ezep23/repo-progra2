#include "Empresa.h"
#include "string.h"
using namespace std;

Empresa::Empresa(){
    setId(0);
    setRazonSocial("");
    setNombreComercial("");
    setEstado(false);
}

Empresa::Empresa(int id, string rS, string nC){
    setId(id);
    setRazonSocial(rS);
    setNombreComercial(nC);
    setEstado(true);
}

void Empresa::setId(int id){
    _id = id;
}
void Empresa::setRazonSocial(string rS){
    strncpy(_razonSocial, rS.c_str(), 49);
}
void Empresa::setNombreComercial(string nC){
    strncpy(_nombreComercial, nC.c_str(), 49);
}
void Empresa::setEstado(bool est){
    _estado = est;
}

int Empresa::getId() const{
    return _id;
}
string Empresa::getRazonSocial() const{
    return string(_razonSocial);
}
string Empresa::getNombreComercial()const{
    return string(_nombreComercial);
}
bool Empresa::getEstado() const{
    return _estado;
}
