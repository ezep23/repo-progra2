#include <iostream>
#include <cstring>
using namespace std;

#include "Proveedor.h"

Proveedor::Proveedor(){
    setNombre("");
    setApellido("");
    setTelefono("");
    setEmail("");
    setDni("");
    setId(0);
    setIdEmpresa(0);
    setNombreEmpresa("");
    setRazonSocial("");
    _estado=false;
}

Proveedor::Proveedor(string nom, string ape, string tel, string em, string dni, int id, int idE, string nE, string rS){
    setNombre(nom);
    setApellido(ape);
    setTelefono(tel);
    setEmail(em);
    setDni(dni);
    setId(id);
    setIdEmpresa(idE);
    setNombreEmpresa(nE);
    setRazonSocial(rS);
}


void Proveedor::setId(int id){
    _id = id;
}
void Proveedor::setIdEmpresa(int idEmpresa){
    _idEmpresa = idEmpresa;
}
void Proveedor::setNombreEmpresa(string nE){
    strncpy(_nombreEmpresa, nE.c_str(), 50);
}
void Proveedor::setRazonSocial(string razon){
    strncpy(_razonSocial, razon.c_str(), 50);
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
string Proveedor::getNombreEmpresa(){
    return string(_nombreEmpresa);
}
string Proveedor::getRazonSocial(){
    return string(_razonSocial);
}
bool Proveedor::getEstado(){
    return _estado;
}
