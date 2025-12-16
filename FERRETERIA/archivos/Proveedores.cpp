# include "Proveedores.h"
# include "../clases/Proveedor.h"

# include<iostream>
# include<cstring>

using namespace std;

int ArchivoProveedores::generarNuevoID(){
    ArchivoProveedores archivo("Proveedores.dat");
    Proveedor obj;

    int numProveedores = archivo.contarProveedores();
    obj = archivo.obtenerProveedor(numProveedores-1);
    return obj.getId()+1;
}

bool ArchivoProveedores::validarIdExiste(int id){

    Proveedor obj;
    FILE *p = fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&obj, _tamProveedor, 1, p) == 1)
    {
        if(obj.getId() == id)
        {
            return true;
        }
    }

    fclose(p);
    return false;
}

int ArchivoProveedores::guardarProveedor(Proveedor obj){

    FILE *p;
    p = fopen(_nombre,"ab");

    int guardado = fwrite(&obj, _tamProveedor, 1, p);

    fclose(p);
    return guardado;
}

bool ArchivoProveedores::listarProveedores(){

    Proveedor obj;
    FILE *p;

    p = fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&obj, _tamProveedor, 1, p) == 1)
    {
        if(obj.getEstado())
        {
            obj.mostrar();
        }
    }

    fclose(p);
    return true;
}

bool ArchivoProveedores::listarProveedoresInactivos(){

    Proveedor obj;
    FILE *p = fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&obj, _tamProveedor, 1, p) == 1)
    {
        if(!obj.getEstado())
        {
            obj.mostrar();
        }
    }

    fclose(p);
    return true;
}

int ArchivoProveedores::obtenerUbicacionProveedor(int id)
{
    Proveedor obj;
    FILE *p;

    p=fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO O TODAVÍA NO SE HA CREADO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, _tamProveedor, 1, p) == 1)
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

Proveedor ArchivoProveedores::obtenerProveedor(int pos){

    Proveedor obj;
    FILE *p;

    p = fopen(_nombre,"rb");

     if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        obj.setId(0);
        return obj;
    }
    obj.setId(-1);

    fseek(p, pos*_tamProveedor, 0);
    fread(&obj, _tamProveedor, 1, p);
    //obj.Mostrar();

    fclose(p);
    return obj;

}

bool ArchivoProveedores::modificarProveedor(Proveedor obj, int pos)
{

    FILE *pProveedores;
    pProveedores=fopen(_nombre,"rb+");

    if(pProveedores==nullptr){
        return false;
    }

    fseek(pProveedores, pos*_tamProveedor, 0);
    bool modificado=fwrite(&obj, _tamProveedor, 1, pProveedores);

    fclose(pProveedores);
    return modificado;
}

int ArchivoProveedores::contarProveedores(){

    FILE *p=fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    fseek(p, 0, 2);
    int tamTotal=ftell(p);

    fclose(p);
    int numProveedores;

    numProveedores = tamTotal/_tamProveedor;
    return numProveedores;
}

bool ArchivoProveedores::bajaProveedor(int id)
{
    Proveedor obj;
    ArchivoProveedores archivo;

    int pos = archivo.obtenerUbicacionProveedor(id);

    if(pos == -1)
    {
        return false;
    }

    obj = archivo.obtenerProveedor(pos);
    obj.setEstado(false);

    return archivo.modificarProveedor(obj, pos);
}

bool ArchivoProveedores::altaProveedor(int id)
{
    Proveedor obj;
    ArchivoProveedores archivo;

    int pos = archivo.obtenerUbicacionProveedor(id);

    if(pos == -1)
    {
        return false;
    }

    obj = archivo.obtenerProveedor(pos);
    obj.setEstado(true);

    return archivo.modificarProveedor(obj, pos);
}

bool ArchivoProveedores::borrar() {
    FILE* p = fopen(_nombre, "wb");
    if (p == NULL) return false;
    fclose(p);
    return true;
}
