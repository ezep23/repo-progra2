#ifndef CATEGORIAS_H_INCLUDED
#define CATEGORIAS_H_INCLUDED

#include "../clases/Categoria.h"
#include "string.h"

class ArchivoCategorias{
    private:
        char _nombre[30];
        int _tamCategoria;

    public:
        ArchivoCategorias(const char *n="Categorias.dat"){
            strcpy(_nombre, n);
            _tamCategoria = sizeof(Categoria);
        }

        void validarArchivoExiste();
        bool validarCategoriaExiste(const char * nombre);

        int contarCategorias();
        int generarNuevoID();

        int obtenerUbicacionCategoria(int id);
        int obtenerUbicacionCategoria(const char* categoria);
        Categoria obtenerCategoria(int pos);

        int guardarCategoria(Categoria);
        int modificarCategoria(Categoria obj, int pos);
        bool listarCategorias();
        bool bajaCategoria(int id);

        bool borrar();

};

#endif // CATEGORIAS_H_INCLUDED
