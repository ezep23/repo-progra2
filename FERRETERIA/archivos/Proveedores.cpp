# include "Proveedores.h"
# include "../clases/Proveedor.h"

# include<iostream>
# include<cstring>

using namespace std;

bool ArchivoProveedores::validarIdExiste(int id){
    Proveedor obj;
    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamProveedor, 1, p) == 1){
        if(obj.getId() == id){
            return true;
        }
    }

    fclose(p);
    return false;
}

int ArchivoProveedores::guardarProveedor(Proveedor obj){

    FILE *pProveedores;
    pProveedores = fopen(_nombre,"ab");

    if(pProveedores==nullptr){
        return -1;
    }

    int guardado = fwrite(&obj, _tamProveedor, 1, pProveedores);

    fclose(pProveedores);
    return guardado;
}

bool ArchivoProveedores::listarProveedores(){

    Proveedor obj;
    FILE *pProveedores;

    pProveedores = fopen(_nombre,"rb");

    if(pProveedores == nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamProveedor, 1, pProveedores) == 1){
        if(obj.getEstado()){
            obj.mostrar();
        }
    }

    fclose(pProveedores);
    return true;
}

bool ArchivoProveedores::listarProveedoresInactivos(){

    Proveedor obj;
    FILE *pProveedores;
    pProveedores = fopen(_nombre,"rb");

    if(pProveedores==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamProveedor, 1, pProveedores) == 1){
        if(!obj.getEstado()){
            obj.mostrar();
        }
    }

    fclose(pProveedores);
    return true;
}

int ArchivoProveedores::obtenerUbicacionProveedor(int id){
    Proveedor obj;
    FILE *pProveedores;

    pProveedores=fopen(_nombre,"rb");

    if(pProveedores==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, _tamProveedor , 1, pProveedores) == 1){
       if(obj.getId() == id){
            return pos;
       }
       pos++;
    }

    fclose(pProveedores);
    return -1;
}

Proveedor ArchivoProveedores::obtenerProveedor(int pos){

    Proveedor obj;
    FILE *pProveedores;

    pProveedores = fopen(_nombre,"rb");
    obj.setId(-1);

    if(pProveedores==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(pProveedores, pos*_tamProveedor, 0);
    fread(&obj, _tamProveedor, 1, pProveedores);
    //obj.Mostrar();

    fclose(pProveedores);
    return obj;

}

bool ArchivoProveedores::modificarProveedor(Proveedor obj, int pos){

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

    FILE *pProveedores;
    pProveedores=fopen(_nombre,"rb");

    if(pProveedores==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    fseek(pProveedores, 0, 2);
    int tamTotal=ftell(pProveedores);

    fclose(pProveedores);
    int numProveedores;

    numProveedores = tamTotal/_tamProveedor;
    return numProveedores;
}

bool ArchivoProveedores::bajaProveedor(int dni){
    Proveedor obj;
    ArchivoProveedores archivo;

    int pos = archivo.obtenerUbicacionProveedor(dni);

    if(pos == -1){
            return false;
    }

    obj = archivo.obtenerProveedor(pos);
    obj.setEstado(false);

    return archivo.modificarProveedor(obj, pos);
}

bool ArchivoProveedores::altaProveedor(int dni){
    Proveedor obj;
    ArchivoProveedores archivo;

    int pos = archivo.obtenerUbicacionProveedor(dni);

    if(pos == -1){
            return false;
    }

    obj = archivo.obtenerProveedor(pos);
    obj.setEstado(true);

    return archivo.modificarProveedor(obj, pos);
}
