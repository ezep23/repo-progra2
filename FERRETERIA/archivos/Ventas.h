#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include <cstring>

#include "../clases/Transaccion.h"

class ArchivoVentas{
 private:
    char _nombre[30];
    int _tamVenta;
 public:
    ArchivoVentas(const char *n="Ventas.dat"){
        strcpy(_nombre, n);
        _tamVenta=sizeof(Transaccion);
    }

    int contarVentas();
    int generarNuevoID();

    bool guardarVenta(Transaccion venta);
    int editarVenta(Transaccion venta, int pos);

    Transaccion obtenerVenta(int pos);
    int obtenerUbicacionVenta(int id);

    bool listarVentas();
    bool listarVentasInactivas();

    bool bajaVenta(int id);
    bool altaVenta(int id);

};



#endif // VENTAS_H_INCLUDED
