
#include "Ventas.h"
#include "../clases/Transaccion.h"

#include <iostream>
using namespace std;

int ArchivoVentas::contarVentas(){
    FILE *p = fopen("Ventas.dat", "rb");

    if (p == NULL) {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Transaccion);
}

int ArchivoVentas::generarNuevoID(){

   int numVentas = contarVentas();

   if (numVentas == 0) {
        return 1;
   }

   Transaccion venta = obtenerVenta(numVentas - 1);
   return venta.getIdTransaccion() + 1;
}

bool ArchivoVentas::guardarVenta(Transaccion venta){

    FILE *p=fopen(_nombre, "ab");

    if(p==nullptr){
        return -1;
    }

    bool guardado=fwrite(&venta, _tamVenta, 1, p);
    fclose(p);

    return guardado;
}

int ArchivoVentas::editarVenta(Transaccion venta, int pos){
    FILE *p=fopen(_nombre, "rb+");
    if(p==NULL){
        return false;
    }

    fseek(p, pos*sizeof venta,0);
    bool escribio=fwrite(&venta, sizeof venta, 1, p);
    fclose(p);
    return escribio;
}


Transaccion ArchivoVentas::obtenerVenta(int pos){

    Transaccion venta;
    FILE *p = fopen(_nombre, "rb");

    venta.setMontoTotal(-1);

    if(p==nullptr){
        return venta;
    }

    fseek(p, pos * _tamVenta, 0);
    fread(&venta, _tamVenta, 1 ,p);

    fclose(p);
    return venta;
}

 int ArchivoVentas::obtenerUbicacionVenta(int id){

    Transaccion venta;
    FILE *p=fopen("Ventas.dat","rb");

    int pos=0;

    if(p == NULL){
        return -1;
    }

    while(fread(&venta, sizeof venta, 1, p) ==1 ){
                if(venta.getIdTransaccion() == id){
                    fclose(p);
                    return pos;
                }
                pos++;
    }
    fclose(p);
    return -2;
}

bool ArchivoVentas::listarVentas(){

    Transaccion venta;
    FILE *p=fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&venta, _tamVenta, 1, p)==1){
        if(venta.getEstado()){
            venta.mostrar();
        }
    }

    fclose(p);
    return true;

}

bool ArchivoVentas::listarVentasInactivas(){

    Transaccion venta;
    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&venta, _tamVenta , 1, p)==1){
        if(!venta.getEstado()){
            venta.mostrar();
        }
    }

    fclose(p);
    return true;

}

bool ArchivoVentas::bajaVenta(int id){

    Transaccion venta;
    ArchivoVentas archivo;

    int pos=archivo.obtenerUbicacionVenta(id);

    if(pos==-1) return false;

    venta=archivo.obtenerVenta(pos); ///en reg tengo el registro a borrar
    venta.setEstado(false);
    return archivo.editarVenta(venta, pos);

}

bool ArchivoVentas::altaVenta(int id){

    Transaccion venta;
    ArchivoVentas archivo;

    int pos=archivo.obtenerUbicacionVenta(id);

    if(pos==-1) return false;

    venta=archivo.obtenerVenta(pos); ///en reg tengo el registro a dar de alta
    venta.setEstado(true);
    return archivo.editarVenta(venta, pos);

}
