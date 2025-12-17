#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "Persona.h"

class Cliente : public Persona{
 private:
    int _id;
    int _dni;
    bool _estado;
 public:

    Cliente();
    Cliente(const char * nom, const char *  ape, const char *  tel, const char *  em, int id, int dni, bool est);

    void setId(int);
    void setDni(int);
    void setEstado(bool);

    int getId();
    int getDni();
    bool getEstado();

    void cargar();
    void mostrar();

};

#endif // CLIENTE_H_INCLUDED
