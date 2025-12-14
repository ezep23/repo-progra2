#include <iostream>
using namespace std;

#include "../clases/DetalleTransaccion.h"
#include "./DetalleVentas.h"


int ArchivoDetallesVenta::contarDetallesVentas(){
    FILE *p = fopen("DetallesVentas.dat", "rb");

    if (p == NULL) {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(DetalleTransaccion);
}

int ArchivoDetallesVenta::generarNuevoID(){
    int numDetalles = contarDetallesVentas();

   if (numDetalles == 0) {
        return 1;
   }

   DetalleTransaccion detalle = obtenerDetalleVenta(numDetalles - 1);
   return detalle.getId() + 1;
}

int ArchivoDetallesVenta::guardarDetalleVenta(DetalleTransaccion detalle){
    FILE *p=fopen(_nombre, "ab");

    if(p==nullptr){
        return -1;
    }

    bool guardado=fwrite(&detalle, _tamDetalleVenta, 1, p);
    fclose(p);

    return guardado;
}

int ArchivoDetallesVenta::editarDetalleVenta(DetalleTransaccion detalle, int pos){
}

int ArchivoDetallesVenta::obtenerUbicacionDetalleVenta(int id){
    DetalleTransaccion obj;
    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, _tamDetalleVenta , 1, p) == 1){
       if(obj.getId() == id){
            return pos;
       }
       pos++;
    }

    fclose(p);
    return -1;
}

DetalleTransaccion ArchivoDetallesVenta::obtenerDetalleVenta(int pos){

    DetalleTransaccion obj;
    FILE *p = fopen(_nombre,"rb");
    obj.setId(-1);

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(p, pos*_tamDetalleVenta, 0);
    fread(&obj, _tamDetalleVenta, 1, p);

    fclose(p);
    return obj;

}

bool ArchivoDetallesVenta::listarDetallesDeVenta(int idTransaccion){

    DetalleTransaccion obj;
    FILE *p=fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamDetalleVenta, 1, p)==1){
        if(obj.getIdTransaccion() == idTransaccion ){
            obj.mostrar();
            cout << " - Estado: " << obj.getEstado() << endl;
        }
    }

    fclose(p);
    return true;
}

bool ArchivoDetallesVenta::listarDetallesTransaccion(){
    DetalleTransaccion obj;
    FILE *p=fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, _tamDetalleVenta, 1, p)==1){
        if(obj.getEstado()){
            obj.mostrar();
        }
    }

    fclose(p);
    return true;
}

bool ArchivoDetallesVenta::listarDetallesTransaccionInactivas(){
    DetalleTransaccion detalle;
    FILE *p = fopen(_nombre,"rb");

    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&detalle, _tamDetalleVenta , 1, p)==1){
        if(!detalle.getEstado()){
            detalle.mostrar();
        }
    }

    fclose(p);
    return true;
}

bool ArchivoDetallesVenta::bajaDetalleVenta(int id){
    DetalleTransaccion obj;
    ArchivoDetallesVenta archivo;

    int pos=archivo.obtenerUbicacionDetalleVenta(id);

    if(pos==-1) return false;

    obj=archivo.obtenerDetalleVenta(pos);
    obj.setEstado(false);
    return archivo.editarDetalleVenta(obj, pos);
}

bool ArchivoDetallesVenta::altaDetalleVenta(int id){
    DetalleTransaccion obj;
    ArchivoDetallesVenta archivo;

    int pos=archivo.obtenerUbicacionDetalleVenta(id);

    if(pos==-1) return false;

    obj=archivo.obtenerDetalleVenta(pos);
    obj.setEstado(true);
    return archivo.editarDetalleVenta(obj, pos);
}




