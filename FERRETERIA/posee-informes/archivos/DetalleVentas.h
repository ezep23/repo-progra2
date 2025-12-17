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

     void validarArchivoExiste();

    int contarDetallesVentas();
    int generarNuevoID();

    int guardarDetalleVenta(DetalleTransaccion detalle);
    bool editarDetalleVenta(DetalleTransaccion detalle, int pos);

    DetalleTransaccion obtenerDetalleVenta(int pos);
    int obtenerUbicacionDetalleVenta(int id);
    float obtenerMontoTotal(int idTransaccion);

    void listarDetallesDeVenta(int idTransaccion);
    bool listarDetallesTransaccion();
    bool listarDetallesTransaccionInactivas();

    bool bajaDetalleVenta(int id);
    bool bajaDetallesVentasCliente(int id);
    bool altaDetalleVenta(int id);
    bool altaDetallesVentasCliente(int id);

    bool borrar();
};

#endif // DETALLEVENTAS_H_INCLUDED
