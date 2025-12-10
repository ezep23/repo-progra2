#ifndef DETALLECOMPRAS_H_INCLUDED
#define DETALLECOMPRAS_H_INCLUDED

#include "../clases/DetalleTransaccion.h"

class ArchivoDetallesCompra{
 private:
    char _nombre[30];
    int _tamDetalleCompra;
 public:
    ArchivoDetallesCompra(const char *n="DetallesCompras.dat"){
        strcpy(_nombre, n);
        _tamDetalleCompra=sizeof(DetalleTransaccion);
    }

    int contarDetallesCompras();
    int generarNuevoID();

    int guardarDetalleCompra(DetalleTransaccion detalle);
    int editarDetalleCompra(DetalleTransaccion detalle, int pos);
    DetalleTransaccion buscarDetallesCompra(int pos);

    bool listarDetallesDeCompra(int idTransaccion);
    bool listarDetallesCompra();
    bool listarDetallesCompraInactivas();

    bool bajaDetalleCompra(int id);
    bool altaDetalleCompra(int id);

};

#endif // DETALLECOMPRAS_H_INCLUDED
