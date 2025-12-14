#ifndef DETALLEVENTAS_H_INCLUDED
#define DETALLEVENTAS_H_INCLUDED

#include <cstring>

#include "../clases/DetalleTransaccion.h"

class ArchivoDetallesVenta{
 private:
    char _nombre[30];
    int _tamDetalleVenta;
 public:
    ArchivoDetallesVenta(const char *n="DetallesVentas.dat"){
        strcpy(_nombre, n);
        _tamDetalleVenta=sizeof(DetalleTransaccion);
    }

    int contarDetallesVentas();
    int generarNuevoID();

    int guardarDetalleVenta(DetalleTransaccion detalle);
    int editarDetalleVenta(DetalleTransaccion detalle, int pos);

    DetalleTransaccion obtenerDetalleVenta(int pos);
    int obtenerUbicacionDetalleVenta(int id);

    bool listarDetallesDeVenta(int idTransaccion);
    bool listarDetallesTransaccion();
    bool listarDetallesTransaccionInactivas();

    bool bajaDetalleVenta(int id);
    bool altaDetalleVenta(int id);

};

#endif // DETALLEVENTAS_H_INCLUDED
