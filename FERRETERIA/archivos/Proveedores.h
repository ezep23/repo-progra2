#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED

#include "../clases/Proveedor.h"
#include "string.h"

class ArchivoProveedores{
    private:
        char _nombre[30];
        int _tamProveedor;
    public:
        ArchivoProveedores(const char *n="Proveedores.dat"){
            strcpy(_nombre, n);
            _tamProveedor=sizeof(Proveedor);
        }

        int generarNuevoID();

        void validarArchivoExiste();
        bool validarIdExiste(int id);

        int contarProveedores();
        int guardarProveedor(Proveedor obj);

        bool listarProveedores();
        bool listarProveedoresInactivos();

        int obtenerUbicacionProveedor(int _id);
        Proveedor obtenerProveedor(int pos);

        bool modificarProveedor(Proveedor obj, int pos);
        bool bajaProveedor(int _id);
        bool altaProveedor(int _id);

        bool borrar();
};



#endif // PROVEEDORES_H_INCLUDED
