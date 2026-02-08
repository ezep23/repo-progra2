
#include "string.h"
#include "Empleado.h"

Empleado::Empleado(){
    setId(0);
    setDni("");
    setNombre("");
    setApellido("");
    setEmail("");
    setTelefono("");
    setEstado(false);
}

Empleado::Empleado(std::string nombre, std::string apellido, std::string telefono, std::string email, std::string dni, int id){
    setId(id);
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setEstado(true);
}

void Empleado::setId(int id){
    _id = id;
}

void Empleado::setEstado(bool est){
    _estado = est;
}

int Empleado::getId() const{
    return _id;
}

bool Empleado::getEstado() const{
    return _estado;
}
