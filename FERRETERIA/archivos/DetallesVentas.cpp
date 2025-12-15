#include <iostream>
using namespace std;

#include "../clases/DetalleTransaccion.h"
#include "./DetalleVentas.h"


void ArchivoDetallesVenta::validarArchivoExiste()
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


int ArchivoDetallesVenta::contarDetallesVentas(){
    validarArchivoExiste();

    FILE *p = fopen("DetallesVentas.dat", "rb");
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(DetalleTransaccion);
}

int ArchivoDetallesVenta::generarNuevoID(){
    int numDetalles = contarDetallesVentas();

    if (numDetalles == 0){
        return 1;
    }

    DetalleTransaccion detalle = obtenerDetalleVenta(numDetalles - 1);
    return detalle.getId() + 1;
}

int ArchivoDetallesVenta::guardarDetalleVenta(DetalleTransaccion detalle){
    validarArchivoExiste();

    FILE *p=fopen(_nombre, "ab");
    bool guardado=fwrite(&detalle, _tamDetalleVenta, 1, p);
    fclose(p);

    return guardado;
}

bool ArchivoDetallesVenta::editarDetalleVenta(DetalleTransaccion detalle, int pos){
    validarArchivoExiste();

    FILE *p=fopen(_nombre, "rb+");
    fseek(p, pos*sizeof detalle,0);
    bool escribio=fwrite(&detalle, sizeof detalle, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoDetallesVenta::obtenerUbicacionDetalleVenta(int id){

    validarArchivoExiste();

    DetalleTransaccion obj;
    FILE *p = fopen(_nombre,"rb");

    int pos=0;
    while(fread(&obj, _tamDetalleVenta, 1, p) == 1)
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

float ArchivoDetallesVenta::obtenerMontoTotal(int idTransaccion){

    validarArchivoExiste();

    DetalleTransaccion obj;
    FILE *p=fopen(_nombre,"rb");

    float total = 0;

    while(fread(&obj, _tamDetalleVenta, 1, p)==1)
    {
        if(obj.getIdTransaccion() == idTransaccion )
        {
            total += (obj.getCantidad() * obj.getPrecioUnitario());
        }
    }

    fclose(p);
    return total;

}

DetalleTransaccion ArchivoDetallesVenta::obtenerDetalleVenta(int pos){

    validarArchivoExiste();

    DetalleTransaccion obj;
    FILE *p = fopen(_nombre,"rb");
    obj.setId(-1);

    fseek(p, pos*_tamDetalleVenta, 0);
    fread(&obj, _tamDetalleVenta, 1, p);

    fclose(p);
    return obj;

}

void ArchivoDetallesVenta::listarDetallesDeVenta(int idTransaccion){

    validarArchivoExiste();

    DetalleTransaccion obj;
    FILE *p=fopen(_nombre,"rb");

    while(fread(&obj, _tamDetalleVenta, 1, p)==1)
    {
        if(obj.getIdTransaccion() == idTransaccion )
        {
            cout << " ----------------------------- " << endl;
            obj.mostrar();
            cout << " Estado: " << obj.getEstado() << endl;
            cout << " ----------------------------- " << endl;
        }
    }

    fclose(p);
    return;
}

bool ArchivoDetallesVenta::listarDetallesTransaccion(){

    validarArchivoExiste();

    DetalleTransaccion obj;
    FILE *p=fopen(_nombre,"rb");

    while(fread(&obj, _tamDetalleVenta, 1, p)==1)
    {
        if(obj.getEstado())
        {
            obj.mostrar();
        }
    }

    fclose(p);
    return true;
}

bool ArchivoDetallesVenta::listarDetallesTransaccionInactivas(){

    validarArchivoExiste();

    DetalleTransaccion detalle;
    FILE *p = fopen(_nombre,"rb");

    while(fread(&detalle, _tamDetalleVenta, 1, p)==1)
    {
        if(!detalle.getEstado())
        {
            detalle.mostrar();
        }
    }

    fclose(p);
    return true;
}

bool ArchivoDetallesVenta::bajaDetalleVenta(int id)
{
    DetalleTransaccion obj;
    ArchivoDetallesVenta archivo;

    int pos=archivo.obtenerUbicacionDetalleVenta(id);

    if(pos==-1) return false;

    obj=archivo.obtenerDetalleVenta(pos);
    obj.setEstado(false);
    return archivo.editarDetalleVenta(obj, pos);
}

bool ArchivoDetallesVenta::bajaDetallesVentasCliente(int id){

}


bool ArchivoDetallesVenta::altaDetalleVenta(int id)
{
    DetalleTransaccion obj;
    ArchivoDetallesVenta archivo;

    int pos=archivo.obtenerUbicacionDetalleVenta(id);

    if(pos==-1) return false;

    obj=archivo.obtenerDetalleVenta(pos);
    obj.setEstado(true);
    return archivo.editarDetalleVenta(obj, pos);
}

bool ArchivoDetallesVenta::altaDetallesVentasCliente(int id){

}

bool ArchivoDetallesVenta::borrar() {
    FILE* p = fopen(_nombre, "wb");
    if (p == NULL) return false;
    fclose(p);
    return true;
}


