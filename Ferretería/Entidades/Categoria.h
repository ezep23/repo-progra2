#pragma once
#include <string>

class Categoria {
 private:
     int  _id;
     char _nombre[25];
     bool _estado;
 public:

    Categoria();
    Categoria(int id, std::string nombre);

    void setId(int);
    void setNombre(std::string);
    void setEstado(bool);

    int getId() const;
    std::string getNombre() const;
    bool getEstado() const;
};
