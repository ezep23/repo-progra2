#ifndef DETALLECOMPRAS_H_INCLUDED
#define DETALLECOMPRAS_H_INCLUDED

#include <cstring>

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

     void validarArchivoExiste();

    int contarDetallesCompras();
    int generarNuevoID();

    int guardarDetalleCompra(DetalleTransaccion detalle);
    bool editarDetalleCompra(DetalleTransaccion detalle, int pos);

    DetalleTransaccion obtenerDetalleCompra(int pos);
    int obtenerUbicacionDetalleCompra(int id);
    float obtenerMontoTotal(int idTransaccion);

    void listarDetallesDeCompra(int idTransaccion);
    bool listarDetallesTransaccion();
    bool listarDetallesTransaccionInactivas();

    bool bajaDetalleCompra(int id);
    bool altaDetalleCompra(int id);

    bool borrar();

};

#endif // DETALLECOMPRAS_H_INCLUDED
