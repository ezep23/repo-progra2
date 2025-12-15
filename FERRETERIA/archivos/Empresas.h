#ifndef EMPRESAS_H_INCLUDED
#define EMPRESAS_H_INCLUDED

#include "string.h"
#include "../clases/Empresa.h"

class ArchivoEmpresas{
    private:
        char _nombre[30];
        int _tamEmpresa;
    public:
        ArchivoEmpresas(const char *n="Empresas.dat"){
            strcpy(_nombre, n);
            _tamEmpresa=sizeof(Empresa);
        }


        int generarNuevoID();

        void validarArchivoExiste();
        bool validarIdExiste(int id);
        bool validarEmpresaExiste(const char * nombre);

        int contarEmpresas();

        bool guardarEmpresa(Empresa obj);
        bool modificarEmpresa(Empresa obj, int pos);

        bool listarEmpresas();
        bool listarEmpresasInactivas();

        int obtenerUbicacionEmpresa(int _id);
        Empresa obtenerEmpresa(int pos);

        bool bajaEmpresa(int _id);
        bool altaEmpresa(int _id);

        bool borrar();
};

#endif // EMPRESAS_H_INCLUDED
