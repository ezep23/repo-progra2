#include <iostream>
using namespace std;

#include "string.h"

#include "../clases/Almacen.h"
#include "Productos.h"

bool ArchivoProductos::guardarProducto(Producto obj){
    FILE *p = fopen(_nombre,"ab");

    if(p==nullptr){
        return -1;
    }

    int guardado = fwrite(&obj, _tamProducto, 1, p);

    fclose(p);
    return guardado;
}

bool ArchivoProductos::editarProducto(Producto obj, int pos){
    FILE *p=fopen(_nombre, "rb+");
    if(p==NULL){
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

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1){
        if(obj.getId() == id ){
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

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1){
        if(obj.getEstado() ){
            cout << " ----------------------------- " << endl;
            obj.mostrar();
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;
}

void ArchivoProductos::listarProductosCategoria(int idCat){
    Producto obj;
    FILE *p=fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1){
        if(obj.getIdCategoria() == idCat && obj.getEstado() ){
            cout << " ----------------------------- " << endl;
            obj.mostrar();
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;
}

void ArchivoProductos::listarProductosInactivos(){
    Producto obj;
    FILE *p=fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1){
        if(!obj.getEstado() ){
            cout << " ----------------------------- " << endl;
            cout << " ID: " << obj.getId() << endl;
            cout << " NOMBRE: " << obj.getNombre() << endl;
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;
}

void ArchivoProductos::listarProductoStock(int id){
    Producto obj;
    FILE *p=fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1){
        if(obj.getEstado() && obj.getId() == id ){
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

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1){
        if(obj.getEstado() && obj.getStock() <= 5 ){
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

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1){
        if( obj.getEstado() && obj.getIdCategoria() == idCat && obj.getStock() <= 5 ){
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

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, _tamProducto, 1, p)==1){
        if(obj.getIdCategoria() == idCat && !obj.getEstado() ){
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

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int tamTotal=ftell(p);

    fclose(p);
    int numProductos;

    numProductos=tamTotal/_tamProducto;
    return numProductos;
}

bool ArchivoProductos::validarNombre(const char* nombre ) {
    Producto obj;

    FILE *p;
    p = fopen("Productos.dat", "rb");

    if (p == NULL){
        return false;
    }

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        if (strcmp(obj.getNombre(), nombre) == 0 ) {
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

    if (p == NULL){
        return false;
    }

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        if (obj.getId() == id && obj.getEstado() && obj.getStock() >= 0) {
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}

int ArchivoProductos::generarNuevoID(){

    ArchivoProductos archivo("Productos.dat");
    Producto obj;

    int numProductos = archivo.contarProductos();

    if (numProductos == 0){
        return 0;
    }

    obj = archivo.obtenerProducto(numProductos-1);
    return obj.getId()+1;

}

int ArchivoProductos::obtenerUbicacionProducto(int id){
    Producto obj;
    FILE *pProductos;

    pProductos=fopen(_nombre,"rb");

    if(pProductos==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, _tamProducto , 1, pProductos) == 1){
       if(obj.getId() == id){
            return pos;
       }
       pos++;
    }

    fclose(pProductos);
    return -1;
}

Producto ArchivoProductos::obtenerProducto(const char* nombre){
    Producto obj;
    FILE *pProductos;

    pProductos = fopen(_nombre,"rb");

    if(pProductos==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    while(fread(&obj, _tamProducto , 1, pProductos) == 1){
       if(strcmp(_nombre, nombre) == 0){
            return obj;
       }
    }

    fclose(pProductos);
    obj.setEstado(false);
    return obj;


}

Producto ArchivoProductos::obtenerProducto(int pos){

    Producto obj;
    FILE *pProductos;

    pProductos = fopen(_nombre,"rb");
    obj.setId(-1);

    if(pProductos==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(pProductos, pos*_tamProducto, 0);
    fread(&obj, _tamProducto, 1, pProductos);

    fclose(pProductos);
    return obj;

}

bool ArchivoProductos::bajaProducto(int id){
    Producto obj;
    ArchivoProductos archivo;

    int pos=archivo.obtenerUbicacionProducto(id);

    if(pos==-1){
            return false;
    }

    obj=archivo.obtenerProducto(pos);
    obj.setEstado(false);
    return archivo.editarProducto(obj, pos);
}

bool ArchivoProductos::altaProducto(int id){
    Producto obj;
    ArchivoProductos archivo;

    int pos=archivo.obtenerUbicacionProducto(id);

    if(pos==-1){
            return false;
    }

    obj=archivo.obtenerProducto(pos);
    obj.setEstado(true);
    return archivo.editarProducto(obj, pos);
}

