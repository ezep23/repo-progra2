#include <iostream>
using namespace std;

#include "Empresas.h"
#include "string.h"

int ArchivoEmpresas::generarNuevoID(){

    ArchivoEmpresas archivo("Empresas.dat");
    Empresa obj;

    int numEmpresas = archivo.contarEmpresas();

    if (numEmpresas == 0){
        return 1;
    }

    obj = archivo.obtenerEmpresa(numEmpresas-1);
    return obj.getId()+1;

}

bool ArchivoEmpresas::validarIdExiste(int id){
    Empresa obj;
    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamEmpresa, 1, p) == 1){
        if(obj.getId() == id){
            return true;
        }
    }

    fclose(p);
    return false;
}

bool ArchivoEmpresas::validarEmpresaExiste(const char * nombre){
    Empresa obj;
    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamEmpresa, 1, p) == 1){
        if(strcmp(_nombre, nombre) == 0){
            return true;
        }
    }

    fclose(p);
    return false;
}


int ArchivoEmpresas::contarEmpresas(){
     FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    fseek(p,0,2);
    int tamTotal=ftell(p);

    fclose(p);

    int numEmpresas = tamTotal/_tamEmpresa;
    return numEmpresas;
}

bool ArchivoEmpresas::guardarEmpresa(Empresa obj){
    FILE *p = fopen(_nombre,"ab");

    if(p==nullptr){
        return false;
    }

    bool guardado = fwrite(&obj, _tamEmpresa, 1, p);

    fclose(p);
    return guardado;
}

bool ArchivoEmpresas::listarEmpresas(){
    Empresa obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamEmpresa, 1, p) == 1){
        if(obj.getEstado()){
            cout << " # ID:" << obj.getId() << " - " << obj.getNombre() << endl;
        }
    }

    fclose(p);
    return true;
}

bool ArchivoEmpresas::listarEmpresasInactivas(){
    Empresa obj;
    FILE *p = fopen(_nombre,"rb");

    if(p == nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamEmpresa, 1, p) == 1){
        if(!obj.getEstado()){
            cout << " # ID:" << obj.getId() << " - " << obj.getNombre() << endl;
        }
    }

    fclose(p);
    return true;
}

int ArchivoEmpresas::obtenerUbicacionEmpresa(int id){
    Empresa obj;
    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, _tamEmpresa, 1, p) == 1){
       if(obj.getId() == id){
            return pos;
       }
       pos++;
    }

    fclose(p);
    return -1;
}

Empresa ArchivoEmpresas::obtenerEmpresa(int pos){
    Empresa obj;
    FILE *p=fopen(_nombre,"rb");
    obj.setId(-1);

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(p, pos*_tamEmpresa, 0);
    fread(&obj, _tamEmpresa, 1, p);

    fclose(p);
    return obj;
}

bool ArchivoEmpresas::modificarEmpresa(Empresa obj, int pos){
    FILE *p=fopen(_nombre,"rb+");

    if(p==nullptr){
        return false;
    }

    fseek(p, pos*_tamEmpresa, 0);
    bool modificado=fwrite(&obj, _tamEmpresa, 1, p);

    fclose(p);
    return modificado;
}


bool ArchivoEmpresas::bajaEmpresa(int id){
    Empresa obj;
    ArchivoEmpresas archivo;

    int pos = archivo.obtenerUbicacionEmpresa(id);

    if(pos == -1){
            return false;
    }

    obj = archivo.obtenerEmpresa(pos);
    obj.setEstado(false);

    return archivo.modificarEmpresa(obj, pos);
}

bool ArchivoEmpresas::altaEmpresa(int id){
    Empresa obj;
    ArchivoEmpresas archivo;

    int pos = archivo.obtenerUbicacionEmpresa(id);

    if(pos == -1){
            return false;
    }

    obj = archivo.obtenerEmpresa(pos);
    obj.setEstado(true);

    return archivo.modificarEmpresa(obj, pos);
}

