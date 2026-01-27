#pragma once
#include "Persona.h"
#include <string>

class Proveedor : public Persona{
 private:
    int _id;
    int _idEmpresa;
    char _nombreEmpresa[50];
    char _razonSocial[50];
    bool _estado;
 public:

    Proveedor();
    Proveedor(std::string nom, std::string ape, std::string  tel, std::string em, std::string dni, int id, int idE, std::string nE, std::string rS);

    void setId(int);
    void setIdEmpresa(int);
    void setNombreEmpresa(std::string);
    void setRazonSocial(std::string);
    void setEstado(bool);

    int getId();
    int getIdEmpresa();
    std::string getNombreEmpresa();
    std::string getRazonSocial();
    bool getEstado();

};
