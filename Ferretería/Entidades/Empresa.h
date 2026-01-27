#pragma once
#include <string>

class Empresa{
 private:
     int  _id;
     char _razonSocial[50];
     bool _estado;
 public:

    Empresa();
    Empresa(int id, std::string razonSocial);

    void setId(int);
    void setRazonSocial(std::string rS);
    void setEstado(bool);

    int getId() const;
    std::string getRazonSocial() const;
    bool getEstado() const;

    void mostrar();
};

