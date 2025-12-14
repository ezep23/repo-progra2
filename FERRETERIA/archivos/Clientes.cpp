# include "Clientes.h"
# include "../clases/Cliente.h"

# include<iostream>
# include<cstring>

using namespace std;

int ArchivoClientes::generarNuevoID(){

    ArchivoClientes archivo("Clientes.dat");
    Cliente obj;

    int numClientes = archivo.contarClientes();

    if (numClientes == 0){
        return 0;
    }

    obj = archivo.obtenerCliente(numClientes-1);
    return obj.getId()+1;

}

int ArchivoClientes::guardarCliente(Cliente obj){

    FILE *p = fopen(_nombre,"ab");

    if(p==nullptr){
        return -1;
    }

    int guardado = fwrite(&obj, _tamCliente, 1, p);

    fclose(p);
    return guardado;
}

bool ArchivoClientes::listarClientes(){

    Cliente obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamCliente, 1, p) == 1){
        if(obj.getEstado()){
            cout << "#" << obj.getId() << " - " << obj.getNombre() << " " << obj.getApellido() << endl;
        }
    }

    fclose(p);
    return true;
}

bool ArchivoClientes::listarClientesInactivos(){

    Cliente obj;
    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamCliente, 1, p) == 1){
        if(!obj.getEstado()){
            obj.mostrar();
        }
    }

    fclose(p);
    return true;
}

int ArchivoClientes::obtenerUbicacionCliente(int dni){
    Cliente obj;
    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, _tamCliente , 1, p) == 1){
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
    obj.setDni(-1);

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(p, pos*_tamCliente, 0);
    fread(&obj, _tamCliente, 1, p);

    fclose(p);
    return obj;

}

int ArchivoClientes::modificarCliente(Cliente obj, int pos){

    FILE *p=fopen(_nombre,"rb+");

    if(p==nullptr){
        return -1;
    }

    fseek(p, pos*_tamCliente, 0);
    int modificado=fwrite(&obj, _tamCliente, 1, p);

    fclose(p);
    return modificado;
}

int ArchivoClientes::contarClientes(){

    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    fseek(p,0,2);
    int tamTotal=ftell(p);

    fclose(p);
    int numClientes;

    numClientes=tamTotal/_tamCliente;
    return numClientes;
}

bool ArchivoClientes::bajaCliente(int dni){
    Cliente obj;
    ArchivoClientes archivo;

    int pos = archivo.obtenerUbicacionCliente(dni);

    if(pos == -1){
            return false;
    }

    obj = archivo.obtenerCliente(pos);
    obj.setEstado(false);

    return archivo.modificarCliente(obj, pos);
}

bool ArchivoClientes::altaCliente(int dni){
    Cliente obj;
    ArchivoClientes archivo;

    int pos = archivo.obtenerUbicacionCliente(dni);

    if(pos == -1){
            return false;
    }

    obj = archivo.obtenerCliente(pos);
    obj.setEstado(true);

    return archivo.modificarCliente(obj, pos);
}
