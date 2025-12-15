# include "Proveedores.h"
# include "../clases/Proveedor.h"

# include<iostream>
# include<cstring>

using namespace std;

void ArchivoProveedores::validarArchivoExiste()
{
    FILE *p = fopen(_nombre, "rb");

    if (p == NULL)
    {

        system("cls");
        cout << " EL ARCHIVO NO EXISTE O AUN NO SE HA CREADO.";
        system("pause");

        return ;
    }
    fclose(p);

}



bool ArchivoProveedores::validarIdExiste(int id){

    validarArchivoExiste();

    Proveedor obj;
    FILE *p = fopen(_nombre,"rb");

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

    validarArchivoExiste();

    FILE *pProveedores;
    pProveedores = fopen(_nombre,"ab");

    int guardado = fwrite(&obj, _tamProveedor, 1, pProveedores);

    fclose(pProveedores);
    return guardado;
}

bool ArchivoProveedores::listarProveedores(){

    validarArchivoExiste();

    Proveedor obj;
    FILE *pProveedores;

    pProveedores = fopen(_nombre,"rb");

    while(fread(&obj, _tamProveedor, 1, pProveedores) == 1)
    {
        if(obj.getEstado())
        {
            obj.mostrar();
        }
    }

    fclose(pProveedores);
    return true;
}

bool ArchivoProveedores::listarProveedoresInactivos(){

    validarArchivoExiste();

    Proveedor obj;
    FILE *pProveedores;
    pProveedores = fopen(_nombre,"rb");

    while(fread(&obj, _tamProveedor, 1, pProveedores) == 1)
    {
        if(!obj.getEstado())
        {
            obj.mostrar();
        }
    }

    fclose(pProveedores);
    return true;
}

int ArchivoProveedores::obtenerUbicacionProveedor(int id)
{
    Proveedor obj;
    FILE *pProveedores;

    pProveedores=fopen(_nombre,"rb");

    if(pProveedores==nullptr){
        cout<<"ERROR DE ARCHIVO O TODAVÍA NO SE HA CREADO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, _tamProveedor, 1, pProveedores) == 1)
    {
        if(obj.getId() == id)
        {
            return pos;
        }
        pos++;
    }

    fclose(pProveedores);
    return -1;
}

Proveedor ArchivoProveedores::obtenerProveedor(int pos){

    validarArchivoExiste();

    Proveedor obj;
    FILE *pProveedores;

    pProveedores = fopen(_nombre,"rb");
    obj.setId(-1);

    fseek(pProveedores, pos*_tamProveedor, 0);
    fread(&obj, _tamProveedor, 1, pProveedores);
    //obj.Mostrar();

    fclose(pProveedores);
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

    validarArchivoExiste();

    FILE *pProveedores;
    pProveedores=fopen(_nombre,"rb");

    fseek(pProveedores, 0, 2);
    int tamTotal=ftell(pProveedores);

    fclose(pProveedores);
    int numProveedores;

    numProveedores = tamTotal/_tamProveedor;
    return numProveedores;
}

bool ArchivoProveedores::bajaProveedor(int dni)
{
    Proveedor obj;
    ArchivoProveedores archivo;

    int pos = archivo.obtenerUbicacionProveedor(dni);

    if(pos == -1)
    {
        return false;
    }

    obj = archivo.obtenerProveedor(pos);
    obj.setEstado(false);

    return archivo.modificarProveedor(obj, pos);
}

bool ArchivoProveedores::altaProveedor(int dni)
{
    Proveedor obj;
    ArchivoProveedores archivo;

    int pos = archivo.obtenerUbicacionProveedor(dni);

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
