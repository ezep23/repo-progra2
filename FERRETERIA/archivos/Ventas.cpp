#include "Ventas.h"
#include "../clases/Transaccion.h"

#include <iostream>
using namespace std;

int ArchivoVentas::contarVentas(){
    FILE *pVentas;
    pVentas=fopen(_nombre,"rb");

    if(pVentas==nullptr){
       system("cls");
       cout<<"ERROR DE ARCHIVO"<<endl;
       system("pause");
        return -1;
    }
    fseek(pVentas, 0, 2);
    int tam=ftell(pVentas);
    fclose(pVentas);

    int numVentas;
    numVentas=tam/_tamVenta;
    return numVentas;
};

int ArchivoVentas::generarNuevoID(){
}

bool ArchivoVentas::guardarVenta(Transaccion venta){

 FILE *pVentas;
 pVentas=fopen(_nombre,"ab");

 if(pVentas==nullptr){
    return -1;
 }

 bool guardado=fwrite(&venta, _tamVenta, 1, pVentas);

 fclose(pVentas);
 return bool;

};
int ArchivoVentas::editarVenta(Transaccion venta, int pos){

};
Transaccion ArchivoVentas::buscarVenta(int pos){

    Transaccion venta;
    FILE *pVentas;
    pVentas=fopen(_nombre,"rb");

    venta.setMontoTotal(-1);

    if(pPropietario==nullptr){
        return venta;
    }

    fseek(pVentas, pos * _tamVenta, 0);
    fread(&venta, _tamVenta, 1 ,pVentas);

    fclose(pVenta);
    return venta;
}
bool ArchivoVentas::listarVentas(){

    Transaccion venta;
    FILE *pVentas;
    pVentas=fopen(_nombre,"rb");

    if(pVentas==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&venta, _tamVenta, 1, pVentas)==1){
        if(venta.getEstado()){
            venta.Mostrar();
        }
    }

    fclose(pVentas);
    return true;

};
bool ArchivoVentas::listarVentasInactivas(){

    Transaccion venta;
    FILE *pVentas;
    pVentas = fopen(_nombre,"rb");

    if(pVentas==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&venta, _tamVenta , 1, pVentas)==1){
        if(!venta.getEstado()){ // si es false, pasa a true y se muestra
            venta.Mostrar();
        }
    }

    fclose(pVentas);
    return true;

};
bool ArchivoVentas::bajaVenta(int id){

    Transaccion venta;
    ArchivoVentas archivo;
    int pos=archivo.buscarVenta(id);

    if(pos==-1) return false;

    venta=archivo.buscarVenta(pos);///en reg tengo el registro a borrar
    venta.setEstado(false);
    return archivo.editarVenta(venta, pos);

};
bool ArchivoVentas::altaVenta(int id){

    Transaccion venta;
    ArchivoVentas archivo;
    int pos=archivo.buscarVenta(id);

    if(pos==-1) return false;

    venta=archivo.buscarVenta(pos);///en reg tengo el registro a borrar
    venta.setEstado(true);
    return archivo.editarVenta(venta, pos);

};
