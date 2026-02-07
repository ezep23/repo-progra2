#pragma once
#include <string>

class Empresa{
 private:
     int  _id;
     char _razonSocial[50];
     char _nombreComercial[50];
     bool _estado;
 public:

    Empresa();
    Empresa(int id, std::string razonSocial, std::string _nombreComercial);

    void setId(int);
    void setRazonSocial(std::string rS);
    void setNombreComercial(std::string nC);
    void setEstado(bool);

    int getId() const;
    std::string getRazonSocial() const;
    std::string getNombreComercial() const;
    bool getEstado() const;

    void mostrar();
};

