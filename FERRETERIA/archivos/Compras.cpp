#include "Compras.h"
#include "../clases/Transaccion.h"

#include <iostream>
using namespace std;

bool ArchivoCompras::validarIdExiste(int id){
    Transaccion obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&obj, _tamCompra, 1, p) == 1){

        if(obj.getIdTransaccion() == id){
            return true;
        }
    }

    fclose(p);
    return false;

}

int ArchivoCompras::contarCompras(){

    FILE *p = fopen("Ventas.dat", "rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Transaccion);
}

int ArchivoCompras::generarNuevoID(){

    ArchivoCompras archivo("Compras.dat");
    Transaccion obj;

    int numCompras = archivo.contarCompras();
    obj = archivo.obtenerCompra(numCompras-1);
    return obj.getIdTransaccion()+1;
}

bool ArchivoCompras::guardarCompra(Transaccion compra){

    FILE *p=fopen(_nombre, "ab");
    bool guardado=fwrite(&compra, _tamCompra, 1, p);
    fclose(p);

    return guardado;
}

bool ArchivoCompras::editarCompra(Transaccion compra, int pos){

    FILE *p=fopen(_nombre, "rb+");
     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    fseek(p, pos*sizeof compra,0);
    bool escribio=fwrite(&compra, sizeof compra, 1, p);
    fclose(p);
    return escribio;
}

Transaccion ArchivoCompras::obtenerCompra(int pos){

    Transaccion compra;
    FILE *p = fopen(_nombre, "rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return compra;
    }

    compra.setMontoTotal(-1);

    fseek(p, pos * _tamCompra, 0);
    fread(&compra, _tamCompra, 1,p);

    fclose(p);
    return compra;
}

int ArchivoCompras::obtenerUbicacionCompra(int id){

    Transaccion compra;
    FILE *p=fopen("Compras.dat","rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    int pos=0;

    while(fread(&compra, sizeof compra, 1, p) ==1 )
    {
        if(compra.getIdTransaccion() == id)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -2;
}

bool ArchivoCompras::listarCompras(){

    Transaccion compra;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&compra, _tamCompra, 1, p)==1){

        if(compra.getEstado()){
            compra.mostrar();
        }
    }

    fclose(p);
    return true;

}

bool ArchivoCompras::listarComprasInactivas(){

    Transaccion compra;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&compra, _tamCompra, 1, p)==1){

        if(!compra.getEstado()){
            compra.mostrar();
        }

    }

    fclose(p);
    return true;

}

bool ArchivoCompras::bajaCompra(int id)
{

    Transaccion compra;
    ArchivoCompras archivo;

    int pos=archivo.obtenerUbicacionCompra(id);

    if(pos==-1) return false;

    compra=archivo.obtenerCompra(pos); ///en reg tengo el registro a borrar
    compra.setEstado(false);
    return archivo.editarCompra(compra, pos);

}

bool ArchivoCompras::altaCompra(int id)
{

    Transaccion compra;
    ArchivoCompras archivo;

    int pos=archivo.obtenerUbicacionCompra(id);

    if(pos==-1) return false;

    compra=archivo.obtenerCompra(pos); ///en reg tengo el registro a dar de alta
    compra.setEstado(true);
    return archivo.editarCompra(compra, pos);

}

bool ArchivoCompras::borrar() {
    FILE* p = fopen(_nombre, "wb");
    if (p == NULL) return false;
    fclose(p);
    return true;
}

bool ArchivoCompras::altaComprasProveedor(int id){

    Transaccion compra;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&compra, _tamCompra, 1, p)==1){

        if(compra.getEstado() && compra.getIdPersona() == id){
            compra.setEstado(false);
        }
    }

    fclose(p);
    return true;

}

bool ArchivoCompras::bajaComprasProveedor(int id){

    Transaccion compra;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&compra, _tamCompra, 1, p)==1){

        if(!compra.getEstado() && compra.getIdPersona() == id){
            compra.setEstado(true);
        }
    }

    fclose(p);
    return true;

}

