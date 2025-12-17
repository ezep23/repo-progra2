#include <iostream>
using namespace std;

#include "Categorias.h"
#include "../clases/Categoria.h"
#include "string.h"

bool ArchivoCategorias::validarCategoriaExiste(const char * nombre){

    Categoria obj;
    FILE *p=fopen("Categorias.dat", "rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while (fread(&obj, sizeof obj, 1, p) == 1)
    {
        if (strcmp(obj.getNombre(), nombre) == 0 )
        {
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}

int ArchivoCategorias::contarCategorias(){

    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    fseek(p,0,2);
    int tamTotal=ftell(p);

    fclose(p);
    int numCategorias;

    numCategorias=tamTotal/_tamCategoria;
    return numCategorias;

}

int ArchivoCategorias::generarNuevoID( )
{

    ArchivoCategorias archivo("Categorias.dat");
    Categoria obj;

    int numCategorias = archivo.contarCategorias();

    if (numCategorias == 0){
        return 1;
    }

    obj = archivo.obtenerCategoria(numCategorias-1);
    return obj.getId()+1;
}

int ArchivoCategorias::guardarCategoria(Categoria obj){

    FILE *p = fopen(_nombre,"ab");

    int guardado = fwrite(&obj, _tamCategoria, 1, p);

    fclose(p);
    return guardado;
}

int ArchivoCategorias::obtenerUbicacionCategoria(int id){

    Categoria obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    int pos=0;
    while(fread(&obj, _tamCategoria, 1, p) == 1)
    {
        if(obj.getId() == id)
        {
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

int ArchivoCategorias::obtenerUbicacionCategoria(const char* categoria){

    Categoria obj;
    FILE *p = fopen(_nombre,"rb");


    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    int pos=0;
    while(fread(&obj, _tamCategoria, 1, p) == 1)
    {
        if(strcmp(_nombre, categoria))
        {
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}


Categoria ArchivoCategorias::obtenerCategoria(int pos){


    Categoria obj;
    FILE *p=fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return obj;
    }

    fseek(p, pos*_tamCategoria, 0);
    fread(&obj, _tamCategoria, 1, p);

    fclose(p);
    return obj;

}

int ArchivoCategorias::modificarCategoria(Categoria obj, int pos){

    FILE *p=fopen(_nombre,"rb+");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    fseek(p, pos*_tamCategoria, 0);
    int modificado=fwrite(&obj, _tamCategoria, 1, p);

    fclose(p);
    return modificado;
}

bool ArchivoCategorias::listarCategorias(){

    Categoria obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&obj, _tamCategoria, 1, p) == 1)
    {
        if(obj.getEstado())
        {
            obj.mostrar();
        }
    }

    fclose(p);
    return true;
}

bool ArchivoCategorias::bajaCategoria(int id)
{
    Categoria obj;
    ArchivoCategorias archivo;

    int pos = archivo.obtenerUbicacionCategoria(id);

    if(pos == -1)
    {
        return false;
    }

    obj = archivo.obtenerCategoria(pos);
    obj.setEstado(false);

    return archivo.modificarCategoria(obj, pos);
}

bool ArchivoCategorias::borrar() {
    FILE* p = fopen(_nombre, "wb");
    if (p == NULL) return false;
    fclose(p);
    return true;
}
