#include <iostream>
using namespace std;

#include "string.h"

#include "../clases/Almacen.h"
#include "Productos.h"


int ArchivoProductos::contarProductos(){

    FILE *p=fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int tamTotal=ftell(p);

    fclose(p);
    int numProductos;

    numProductos=tamTotal/_tamProducto;
    return numProductos;
}

bool ArchivoProductos::validarNombre(const char* nombre ) {
    Producto obj;

    FILE *p;
    p = fopen("Productos.dat", "rb");

    if (p == NULL){
        return false;
    }

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        if (strcmp(obj.getNombre(), nombre) == 0 ) {
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}

bool ArchivoProductos::validarDisponibilidad(int id){
    Producto obj;
    FILE *p;
    p = fopen("Productos.dat", "rb");

    if (p == NULL){
        return false;
    }

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        if (obj.getId() == id && obj.getEstado() && obj.getStock() >= 0) {
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}

int ArchivoProductos::generarNuevoID(){

    ArchivoProductos archivo("Productos.dat");
    Producto obj;

    int numProductos = archivo.contarProductos();

    if (numProductos == 0){
        return 0;
    }

    obj = archivo.obtenerProducto(numProductos-1);
    return obj.getId()+1;

}

int ArchivoProductos::obtenerUbicacionProducto(int id){
    Producto obj;
    FILE *pProductos;

    pProductos=fopen(_nombre,"rb");

    if(pProductos==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, _tamProducto , 1, pProductos) == 1){
       if(obj.getId() == id){
            return pos;
       }
       pos++;
    }

    fclose(pProductos);
    return -1;
}

Producto ArchivoProductos::obtenerProducto(int pos){

    Producto obj;
    FILE *pProductos;

    pProductos = fopen(_nombre,"rb");
    obj.setId(-1);

    if(pProductos==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(pProductos, pos*_tamProducto, 0);
    fread(&obj, _tamProducto, 1, pProductos);
    //obj.Mostrar();

    fclose(pProductos);
    return obj;

}
