#include "Compras.h"
#include "../clases/Transaccion.h"

#include <iostream>
using namespace std;

int ArchivoCompras::contarCompras(){
    FILE *p = fopen("Ventas.dat", "rb");

    if (p == NULL) {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Transaccion);
}

int ArchivoCompras::generarNuevoID(){

   int numCompras = contarCompras();

   if (numCompras == 0) {
        return 1;
   }

   Transaccion compra = obtenerCompra(numCompras - 1);
   return compra.getIdTransaccion() + 1;
}

bool ArchivoCompras::guardarCompra(Transaccion compra){

    FILE *p=fopen(_nombre, "ab");

    if(p==nullptr){
        return -1;
    }

    bool guardado=fwrite(&compra, _tamCompra, 1, p);
    fclose(p);

    return guardado;
}

bool ArchivoCompras::editarCompra(Transaccion compra, int pos){
    FILE *p=fopen(_nombre, "rb+");
    if(p==NULL){
        return false;
    }

    fseek(p, pos*sizeof compra,0);
    bool escribio=fwrite(&compra, sizeof compra, 1, p);
    fclose(p);
    return escribio;
}

Transaccion ArchivoCompras::obtenerCompra(int pos){

    Transaccion compra;
    FILE *p = fopen(_nombre, "rb");

    compra.setMontoTotal(-1);

    if(p==nullptr){
        return compra;
    }

    fseek(p, pos * _tamCompra, 0);
    fread(&compra, _tamCompra, 1 ,p);

    fclose(p);
    return compra;
}

 int ArchivoCompras::obtenerUbicacionCompra(int id){

    Transaccion compra;
    FILE *p=fopen("Compras.dat","rb");

    int pos=0;

    if(p == NULL){
        return -1;
    }

    while(fread(&compra, sizeof compra, 1, p) ==1 ){
                if(compra.getIdTransaccion() == id){
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

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
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

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&compra, _tamCompra , 1, p)==1){
        if(!compra.getEstado()){
            compra.mostrar();
        }
    }

    fclose(p);
    return true;

}

bool ArchivoCompras::bajaCompra(int id){

    Transaccion compra;
    ArchivoCompras archivo;

    int pos=archivo.obtenerUbicacionCompra(id);

    if(pos==-1) return false;

    compra=archivo.obtenerCompra(pos); ///en reg tengo el registro a borrar
    compra.setEstado(false);
    return archivo.editarCompra(compra, pos);

}

bool ArchivoCompras::altaCompra(int id){

    Transaccion compra;
    ArchivoCompras archivo;

    int pos=archivo.obtenerUbicacionCompra(id);

    if(pos==-1) return false;

    compra=archivo.obtenerCompra(pos); ///en reg tengo el registro a dar de alta
    compra.setEstado(true);
    return archivo.editarCompra(compra, pos);

}
