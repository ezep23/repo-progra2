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
    setEstado(false);
}

Proveedor::Proveedor(string nom, string ape, string tel, string em, string dni, int id, int idE){
    setNombre(nom);
    setApellido(ape);
    setTelefono(tel);
    setEmail(em);
    setDni(dni);
    setId(id);
    setIdEmpresa(idE);
    setEstado(true);
}


void Proveedor::setId(int id){
    _id = id;
}
void Proveedor::setIdEmpresa(int idEmpresa){
    _idEmpresa = idEmpresa;
}
void Proveedor::setEstado(bool est){
    _estado = est;
}

int Proveedor::getId() const{
    return _id;
}
int Proveedor::getIdEmpresa() const{
    return _idEmpresa;
}
bool Proveedor::getEstado() const{
    return _estado;
}
