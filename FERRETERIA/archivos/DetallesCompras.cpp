#include <iostream>
using namespace std;

#include "../clases/DetalleTransaccion.h"
#include "./DetalleCompras.h"


int ArchivoDetallesCompra::contarDetallesCompras(){
    FILE *p = fopen("DetallesCompras.dat", "rb");

    if (p == NULL) {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(DetalleTransaccion);
}

int ArchivoDetallesCompra::generarNuevoID(){
    int numDetalles = contarDetallesCompras();

   if (numDetalles == 0) {
        return 1;
   }

   DetalleTransaccion detalle = obtenerDetalleCompra(numDetalles - 1);
   return detalle.getId() + 1;
}

int ArchivoDetallesCompra::guardarDetalleCompra(DetalleTransaccion detalle){
    FILE *p=fopen(_nombre, "ab");

    if(p==nullptr){
        return -1;
    }

    bool guardado=fwrite(&detalle, _tamDetalleCompra, 1, p);
    fclose(p);

    return guardado;
}

bool ArchivoDetallesCompra::editarDetalleCompra(DetalleTransaccion detalle, int pos){
    FILE *p=fopen(_nombre, "rb+");
    if(p==NULL){
        return false;
    }

    fseek(p, pos*sizeof detalle,0);
    bool escribio=fwrite(&detalle, sizeof detalle, 1, p);
    fclose(p);
    return escribio;

}

int ArchivoDetallesCompra::obtenerUbicacionDetalleCompra(int id){
    DetalleTransaccion obj;
    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, _tamDetalleCompra , 1, p) == 1){
       if(obj.getId() == id){
            return pos;
       }
       pos++;
    }

    fclose(p);
    return -1;
}

float ArchivoDetallesCompra::obtenerMontoTotal(int idTransaccion){

    DetalleTransaccion obj;
    FILE *p=fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return 0;
    }

    float total = 0;

    while(fread(&obj, _tamDetalleCompra, 1, p)==1){
        if(obj.getIdTransaccion() == idTransaccion ){
            total += (obj.getCantidad() * obj.getPrecioUnitario());
        }
    }

    fclose(p);
    return total;

}


DetalleTransaccion ArchivoDetallesCompra::obtenerDetalleCompra(int pos){

    DetalleTransaccion obj;
    FILE *p = fopen(_nombre,"rb");
    obj.setId(-1);

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(p, pos*_tamDetalleCompra, 0);
    fread(&obj, _tamDetalleCompra, 1, p);

    fclose(p);
    return obj;

}

void ArchivoDetallesCompra::listarDetallesDeCompra(int idTransaccion){

    DetalleTransaccion obj;
    FILE *p=fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }


    while(fread(&obj, _tamDetalleCompra, 1, p)==1){
        if(obj.getIdTransaccion() == idTransaccion ){
            cout << " ----------------------------- " << endl;
            obj.mostrar();
            cout << " Estado: " << obj.getEstado() << endl;
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;
}

bool ArchivoDetallesCompra::listarDetallesTransaccion(){
    DetalleTransaccion obj;
    FILE *p=fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamDetalleCompra, 1, p)==1){
        if(obj.getEstado()){
            obj.mostrar();
        }
    }

    fclose(p);
    return true;
}

bool ArchivoDetallesCompra::listarDetallesTransaccionInactivas(){
    DetalleTransaccion obj;
    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&obj, _tamDetalleCompra , 1, p)==1){
        if(!obj.getEstado()){
            obj.mostrar();
        }
    }

    fclose(p);
    return true;
}

bool ArchivoDetallesCompra::bajaDetalleCompra(int id){
    DetalleTransaccion obj;
    ArchivoDetallesCompra archivo;

    int pos=archivo.obtenerUbicacionDetalleCompra(id);

    if(pos==-1) return false;

    obj=archivo.obtenerDetalleCompra(pos);
    obj.setEstado(false);
    return archivo.editarDetalleCompra(obj, pos);
}

bool ArchivoDetallesCompra::altaDetalleCompra(int id){
    DetalleTransaccion obj;
    ArchivoDetallesCompra archivo;

    int pos=archivo.obtenerUbicacionDetalleCompra(id);

    if(pos==-1) return false;

    obj=archivo.obtenerDetalleCompra(pos);
    obj.setEstado(true);
    return archivo.editarDetalleCompra(obj, pos);
}



