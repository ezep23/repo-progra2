#include <iostream>
using namespace std;

#include "string.h"

#include "../utiles.cpp"
#include "../clases/Almacen.h"
#include "Productos.h"


bool ArchivoProductos::validarIdExiste(int id){

    Producto obj;
    FILE *p = fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&obj, _tamProducto, 1, p) == 1){
        if(obj.getId() == id){
            return true;
        }
    }

    fclose(p);
    return false;
}

bool ArchivoProductos::guardarProducto(Producto obj){

    FILE *p = fopen(_nombre,"ab");

    int guardado = fwrite(&obj, _tamProducto, 1, p);

    fclose(p);
    return guardado;
}

bool ArchivoProductos::editarProducto(Producto obj, int pos){

    FILE *p=fopen(_nombre, "rb+");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    fseek(p, pos*sizeof obj,0);
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

void ArchivoProductos::listarProducto(int id){

    Producto obj;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1)
    {
        if(obj.getId() == id )
        {
            cout << " ----------------------------- " << endl;
            obj.mostrar();
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;
}

void ArchivoProductos::listarProductos(){

    Producto obj;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1)
    {
        if(obj.getEstado() )
        {
            cout << " ----------------------------- " << endl;
            cout << endl;
            obj.mostrar();
            cout << endl;
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;
}

void ArchivoProductos::listarProductosCategoria(int idCat){

    Producto obj;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1)
    {
        if(obj.getIdCategoria() == idCat && obj.getEstado() )
        {
            cout << " ----------------------------- " << endl;
            cout << endl;
            obj.mostrar();
            cout << endl;
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;
}

void ArchivoProductos::listarProductosInactivos(){

    Producto obj;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1)
    {
        if(!obj.getEstado() )
        {
            cout << endl;
            cout << " ----------------------------- " << endl;
            cout << " ID: " << obj.getId() << endl;
            cout << " NOMBRE: " << obj.getNombre() << endl;
            cout << " ----------------------------- " << endl;
            cout << endl;
        }
    }

    fclose(p);
    return;
}

void ArchivoProductos::listarProductoStock(int id){

    Producto obj;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1)
    {
        if(obj.getEstado() && obj.getId() == id )
        {
            cout << " ----------------------------- " << endl;
            cout << " ID: " << obj.getId() << endl;
            cout << " NOMBRE: " << obj.getNombre() << endl;
            cout << " CANTIDAD DISPONIBLE: " << obj.getStock() << endl;
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;

}

void ArchivoProductos::listarProductosProveedor(int idProv){
    Producto obj;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1){
        if(obj.getIdProveedor() == idProv ){
            cout << " ----------------------------- " << endl;
            cout << " ID: " << obj.getId() << endl;
            cout << " NOMBRE: " << obj.getNombre() << endl;
            cout << " CANTIDAD DISPONIBLE: " << obj.getStock() << endl;
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;
}

void ArchivoProductos::listarProductosBajoStock(){

    Producto obj;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1)
    {
        if(obj.getEstado() && obj.getStock() <= 5 )
        {
            cout << " ----------------------------- " << endl;
            cout << " ID: " << obj.getId() << endl;
            cout << " NOMBRE: " << obj.getNombre() << endl;
            cout << " CANTIDAD DISPONIBLE: " << obj.getStock() << endl;
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;

}
void ArchivoProductos::listarProductosBajoStock(int idCat){

    Producto obj;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1)
    {
        if( obj.getEstado() && obj.getIdCategoria() == idCat && obj.getStock() <= 5 )
        {
            cout << " ----------------------------- " << endl;
            cout << " ID: " << obj.getId() << endl;
            cout << " NOMBRE: " << obj.getNombre() << endl;
            cout << " CANTIDAD DISPONIBLE: " << obj.getStock() << endl;
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;
}

void ArchivoProductos::listarProductosInactivosCategoria(int idCat){

    Producto obj;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1)
    {
        if(obj.getIdCategoria() == idCat && !obj.getEstado() )
        {
            cout << " ----------------------------- " << endl;
            cout << " ID: " << obj.getId() << endl;
            cout << " NOMBRE: " << obj.getNombre() << endl;
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;
}

int ArchivoProductos::contarProductos(){

    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    fseek(p,0,2);
    int tamTotal=ftell(p);

    fclose(p);
    int numProductos;

    numProductos=tamTotal/_tamProducto;
    return numProductos;
}

bool ArchivoProductos::validarNombre(const char* nombre ){

    Producto obj;

    FILE *p;
    p = fopen("Productos.dat", "rb");

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

bool ArchivoProductos::validarDisponibilidad(int id){


    Producto obj;
    FILE *p;
    p = fopen("Productos.dat", "rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while (fread(&obj, sizeof obj, 1, p) == 1)
    {
        if (obj.getId() == id && obj.getEstado() && obj.getStock() >= 0)
        {
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}

int ArchivoProductos::generarNuevoID()
{

    ArchivoProductos archivo("Productos.dat");
    Producto obj;

    int numProductos = archivo.contarProductos();

    if (numProductos == 0){
        return 1;
    }

    obj = archivo.obtenerProducto(numProductos-1);
    return obj.getId()+1;

}

int ArchivoProductos::obtenerUbicacionProducto(int id){

    Producto obj;
    FILE *p=fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    int pos=0;
    while(fread(&obj, _tamProducto, 1, p) == 1)
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

Producto ArchivoProductos::obtenerProducto(const char* nombre){

    Producto obj;
    FILE *p;

    p= fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return obj;
    }

    while(fread(&obj, _tamProducto, 1, p) == 1)
    {
        if(strcmp(_nombre, nombre) == 0)
        {
            return obj;
        }
    }

    fclose(p);
    obj.setEstado(false);
    return obj;


}

Producto ArchivoProductos::obtenerProducto(int pos){

    Producto obj;
    FILE *p = fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return obj;
    }
    obj.setId(-1);

    fseek(p, pos*_tamProducto, 0);
    fread(&obj, _tamProducto, 1, p);

    fclose(p);
    return obj;

}

void ArchivoProductos::listarProductosMismoNombre(const char* nombre){
    Producto obj;
    FILE *p;

    p= fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamProducto, 1, p) == 1)
    {
        if(sonIguales(obj.getNombre(), nombre)){
            obj.mostrar();
        }
    }

    fclose(p);
    return;

}

void ArchivoProductos::listarProductosMismaMarca(const char* marca){
    Producto obj;
    FILE *p;

    p= fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamProducto, 1, p) == 1)
    {
        if( sonIguales(obj.getMarca(), marca) ){
            obj.mostrar();
        }
    }

    fclose(p);
    return;

}

bool ArchivoProductos::bajaProducto(int id)
{
    Producto obj;
    ArchivoProductos archivo;

    int pos=archivo.obtenerUbicacionProducto(id);

    if(pos==-1)
    {
        return false;
    }

    obj=archivo.obtenerProducto(pos);
    obj.setEstado(false);
    return archivo.editarProducto(obj, pos);
}

bool ArchivoProductos::altaProducto(int id)
{
    Producto obj;
    ArchivoProductos archivo;

    int pos=archivo.obtenerUbicacionProducto(id);

    if(pos==-1)
    {
        return false;
    }

    obj=archivo.obtenerProducto(pos);
    obj.setEstado(true);
    return archivo.editarProducto(obj, pos);
}

bool ArchivoProductos::borrar() {
    FILE* p = fopen(_nombre, "wb");
    if (p == NULL) return false;
    fclose(p);
    return true;
}
