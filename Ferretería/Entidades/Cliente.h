#pragma once
#include <string>
#include "Persona.h"

class Cliente : public Persona{
 private:
    int _id;
    bool _estado;
 public:

    Cliente();
    Cliente(std::string nom, std::string ape, std::string tel, std::string em, std::string dni, int id);

    void setId(int);
    void setEstado(bool);

    int getId() const;
    bool getEstado() const;

};
