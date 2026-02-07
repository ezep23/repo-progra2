
#include "string.h"
#include "Cliente.h"

Cliente::Cliente(){
    setId(0);
    setDni("");
    setNombre("");
    setApellido("");
    setEmail("");
    setTelefono("");
    setEstado(false);
}

Cliente::Cliente(std::string nombre, std::string apellido, std::string telefono, std::string email, std::string dni, int id){
    setId(id);
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setEstado(true);
}

void Cliente::setId(int id){
    _id = id;
}

void Cliente::setEstado(bool est){
    _estado = est;
}

int Cliente::getId() const{
    return _id;
}

bool Cliente::getEstado() const{
    return _estado;
}
