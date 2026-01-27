#pragma once
#include "Persona.h"
#include <string>

class Proveedor : public Persona{
 private:
    int _id;
    int _idEmpresa;
    bool _estado;
 public:

    Proveedor();
    Proveedor(std::string nom, std::string ape, std::string  tel, std::string em, std::string dni, int id, int idE);

    void setId(int);
    void setIdEmpresa(int);
    void setEstado(bool);

    int getId() const;
    int getIdEmpresa() const;
    bool getEstado() const;

};

