#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#include "../clases/Cliente.h"
#include "string.h"

class ArchivoClientes{
    private:
        char _nombre[30];
        int _tamCliente;
    public:
        ArchivoClientes(const char *n="Clientes.dat"){
            strcpy(_nombre, n);
            _tamCliente = sizeof(Cliente);
        }

       /* bool archivoExiste() {
            FILE *p = fopen(_nombre, "rb");
            if (p == NULL) {
                return false;
            }
            fclose(p);
            return true;
        } */ /// IMPORTANTE ESTO VALIDAR EN TODOS LOS ARCHIVOS SI EXISTE

        int generarNuevoID();
        int contarClientes();

        int guardarCliente(Cliente obj);

        bool listarClientes();
        bool listarClientesInactivos();

        int obtenerUbicacionCliente(int _id);
        Cliente obtenerCliente(int pos);

        int modificarCliente(Cliente obj, int pos);

        bool bajaCliente(int _id);
        bool altaCliente(int _id);
};



#endif // CLIENTES_H_INCLUDED
