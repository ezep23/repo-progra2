# include "Clientes.h"
# include "../clases/Cliente.h"

# include<iostream>
# include<cstring>
#include "../utiles.cpp"

using namespace std;

void ArchivoClientes::validarArchivoExiste()
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


int ArchivoClientes::obtenerIdCliente(int dni){

    Cliente obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    while(fread(&obj, _tamCliente, 1, p) == 1){
        if(obj.getEstado() && obj.getId() == dni){
            return obj.getId();
        }
    }

    fclose(p);
    return true;

}

bool ArchivoClientes::validarIdExiste(int id){

    Cliente obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&obj, _tamCliente, 1, p) == 1)
    {
        if(obj.getId() == id)
        {
            return true;
        }
    }

    fclose(p);
    return false;

}

bool ArchivoClientes::validarDniExiste(int dni){

    Cliente obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&obj, _tamCliente, 1, p) == 1)
    {
        if(obj.getDni() == dni)
        {
            return true;
        }
    }

    fclose(p);
    return false;

}

int ArchivoClientes::generarNuevoID(){

    ArchivoClientes archivo("Clientes.dat");
    Cliente obj;

    int numClientes = archivo.contarClientes();
    obj = archivo.obtenerCliente(numClientes-1);
    return obj.getId()+1;

}

int ArchivoClientes::guardarCliente(Cliente obj){

    FILE *p = fopen(_nombre,"ab");

    int guardado = fwrite(&obj, _tamCliente, 1, p);

    fclose(p);
    return guardado;
}

void ArchivoClientes::listarClientesNombre(const char* nom){

    Cliente obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamCliente, 1, p) == 1){
        if(obj.getEstado() && sonIguales(obj.getNombre(), nom) ){
            obj.mostrar();
        }
    }

    fclose(p);
    return;

}

void ArchivoClientes::listarClientesApellido(const char* ape){

    Cliente obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }

    while(fread(&obj, _tamCliente, 1, p) == 1){

        if(obj.getEstado() && sonIguales(obj.getApellido(), ape) ){
            obj.mostrar();
        }
    }

    fclose(p);
    return;
}

bool ArchivoClientes::listarClientes(){

    Cliente obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&obj, _tamCliente, 1, p) == 1)
    {
        if(obj.getEstado())
        {
            cout << "#" << obj.getId() << " - " << obj.getNombre() << " " << obj.getApellido() << endl;
        }
    }

    fclose(p);
    return true;
}

bool ArchivoClientes::listarClientesInactivos(){

    Cliente obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    while(fread(&obj, _tamCliente, 1, p) == 1)
    {
        if(!obj.getEstado())
        {
            obj.mostrar();
        }
    }

    fclose(p);
    return true;
}

int ArchivoClientes::obtenerUbicacionCliente(int dni){

    Cliente obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    int pos=0;
    while(fread(&obj, _tamCliente, 1, p) == 1){
        if(obj.getDni() == dni){
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

Cliente ArchivoClientes::obtenerCliente(int pos){

    Cliente obj;
    FILE *p=fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return obj;
    }
    obj.setDni(-1);

    fseek(p, pos*_tamCliente, 0);
    fread(&obj, _tamCliente, 1, p);

    fclose(p);
    return obj;

}

int ArchivoClientes::modificarCliente(Cliente obj, int pos){

    FILE *p=fopen(_nombre,"rb+");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    fseek(p, pos*_tamCliente, 0);
    int modificado=fwrite(&obj, _tamCliente, 1, p);

    fclose(p);
    return modificado;
}

int ArchivoClientes::contarClientes(){


    FILE *p = fopen(_nombre,"rb");

    if(p == NULL){
        cout << "ERROR DE ARCHIVO";
        return false;
    }

    fseek(p,0,2);
    int tamTotal=ftell(p);

    fclose(p);

    int numClientes=tamTotal/_tamCliente;
    return numClientes;
}

bool ArchivoClientes::bajaCliente(int dni)
{
    Cliente obj;
    ArchivoClientes archivo;

    int pos = archivo.obtenerUbicacionCliente(dni);

    if(pos == -1)
    {
        return false;
    }

    obj = archivo.obtenerCliente(pos);
    obj.setEstado(false);

    return archivo.modificarCliente(obj, pos);
}

bool ArchivoClientes::altaCliente(int dni)
{
    Cliente obj;
    ArchivoClientes archivo;

    int pos = archivo.obtenerUbicacionCliente(dni);

    if(pos == -1)
    {
        return false;
    }

    obj = archivo.obtenerCliente(pos);
    obj.setEstado(true);

    return archivo.modificarCliente(obj, pos);
}

bool ArchivoClientes::borrar() {
    FILE* p = fopen(_nombre, "wb");
    if (p == NULL) return false;
    fclose(p);
    return true;
}
