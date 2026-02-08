#pragma once
#include <string>
#include "Persona.h"

class Empleado : public Persona{
 private:
    int _id;
    bool _estado;
 public:

    Empleado();
    Empleado(std::string nom, std::string ape, std::string tel, std::string em, std::string dni, int id);

    void setId(int);
    void setEstado(bool);

    int getId() const;
    bool getEstado() const;

};
