#pragma once
#include <string>

class Categoria {
 private:
     int  _id;
     char _nombre[25];
     bool _estado;
 public:

    void setId(int);
    void setNombre(std::string);
    void setEstado(bool);

    int getId();
    std::string getNombre();
    bool getEstado();
};
