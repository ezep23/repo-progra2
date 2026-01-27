#pragma once
#include <string>

class Empresa{
 private:
     int  _id;
     char _nombre[20];
     bool _estado=true;
 public:

    Empresa();
    Empresa(int id, std::string nombre, bool estado);

    void setId(int);
    void setNombre(std::string nombre);
    void setEstado(bool);

    int getId() const;
    std::string getNombre() const;
    bool getEstado() const;

    void mostrar();
};
