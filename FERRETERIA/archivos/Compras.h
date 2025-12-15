#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED

#include "../clases/Transaccion.h"
#include "string.h"

class ArchivoCompras{
 private:
    char _nombre[30];
    int _tamCompra;
 public:
    ArchivoCompras(const char *n="Compras.dat"){
        strcpy(_nombre, n);
        _tamCompra=sizeof(Transaccion);
    }

    void validarArchivoExiste();

    int contarCompras();
    int generarNuevoID();

    bool guardarCompra(Transaccion Compra);
    bool editarCompra(Transaccion Compra, int pos);

    Transaccion obtenerCompra(int pos);
    int obtenerUbicacionCompra(int id);

    bool listarCompras();
    bool listarComprasInactivas();

    bool bajaCompra(int id);
    bool altaCompra(int id);


    bool borrar();
};

#endif // COMPRAS_H_INCLUDED
