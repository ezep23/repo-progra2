#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

#include "Persona.h"

class Proveedor : public Persona{
 private:
    int _id;
    int _idEmpresa;
    char _nombreEmpresa[50];
    char _razonSocial[50];
    bool _estado;
 public:

    Proveedor();
    Proveedor(const char * nom, const char *  ape, const char *  tel, const char *  em, int id, int idE, const char* nE, const char* rS, bool est);

    void setId(int);
    void setIdEmpresa(int);
    void setNombreEmpresa(const char *);
    void setRazonSocial(const char*);
    void setEstado(bool);

    int getId();
    int getIdEmpresa();
    const char * getNombreEmpresa();
    const char* getRazonSocial();
    bool getEstado();

    void cargar();
    void mostrar();
};

#endif // PROVEEDOR_H_INCLUDED
