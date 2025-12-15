#include <iostream>
using namespace std;

#include "../clases/DetalleTransaccion.h"
#include "./DetalleCompras.h"

void ArchivoDetallesCompra::validarArchivoExiste()
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

int ArchivoDetallesCompra::contarDetallesCompras(){

    validarArchivoExiste();

    FILE *p = fopen("DetallesCompras.dat", "rb");

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(DetalleTransaccion);
}

int ArchivoDetallesCompra::generarNuevoID()
{
    int numDetalles = contarDetallesCompras();

    if (numDetalles == 0){
        return 1;
    }

    DetalleTransaccion detalle = obtenerDetalleCompra(numDetalles - 1);
    return detalle.getId() + 1;
}

int ArchivoDetallesCompra::guardarDetalleCompra(DetalleTransaccion detalle){

    validarArchivoExiste();

    FILE *p=fopen(_nombre, "ab");

    bool guardado=fwrite(&detalle, _tamDetalleCompra, 1, p);
    fclose(p);

    return guardado;
}

bool ArchivoDetallesCompra::editarDetalleCompra(DetalleTransaccion detalle, int pos){

    validarArchivoExiste();

    FILE *p=fopen(_nombre, "rb+");

    fseek(p, pos*sizeof detalle,0);
    bool escribio=fwrite(&detalle, sizeof detalle, 1, p);
    fclose(p);
    return escribio;

}

int ArchivoDetallesCompra::obtenerUbicacionDetalleCompra(int id){
    validarArchivoExiste();

    DetalleTransaccion obj;
    FILE *p = fopen(_nombre,"rb");

    int pos=0;
    while(fread(&obj, _tamDetalleCompra, 1, p) == 1)
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

float ArchivoDetallesCompra::obtenerMontoTotal(int idTransaccion){

    validarArchivoExiste();

    DetalleTransaccion obj;
    FILE *p=fopen(_nombre,"rb");

    float total = 0;

    while(fread(&obj, _tamDetalleCompra, 1, p)==1)
    {
        if(obj.getIdTransaccion() == idTransaccion )
        {
            total += (obj.getCantidad() * obj.getPrecioUnitario());
        }
    }

    fclose(p);
    return total;

}


DetalleTransaccion ArchivoDetallesCompra::obtenerDetalleCompra(int pos){

    validarArchivoExiste();

    DetalleTransaccion obj;
    FILE *p = fopen(_nombre,"rb");
    obj.setId(-1);

    fseek(p, pos*_tamDetalleCompra, 0);
    fread(&obj, _tamDetalleCompra, 1, p);

    fclose(p);
    return obj;

}

void ArchivoDetallesCompra::listarDetallesDeCompra(int idTransaccion){

    validarArchivoExiste();

    DetalleTransaccion obj;
    FILE *p=fopen(_nombre,"rb");

    while(fread(&obj, _tamDetalleCompra, 1, p)==1)
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

bool ArchivoDetallesCompra::listarDetallesTransaccion(){

    validarArchivoExiste();

    DetalleTransaccion obj;
    FILE *p=fopen(_nombre,"rb");

    while(fread(&obj, _tamDetalleCompra, 1, p)==1)
    {
        if(obj.getEstado())
        {
            obj.mostrar();
        }
    }

    fclose(p);
    return true;
}

bool ArchivoDetallesCompra::listarDetallesTransaccionInactivas(){

    validarArchivoExiste();

    DetalleTransaccion obj;
    FILE *p = fopen(_nombre,"rb");

    while(fread(&obj, _tamDetalleCompra, 1, p)==1)
    {
        if(!obj.getEstado())
        {
            obj.mostrar();
        }
    }

    fclose(p);
    return true;
}

bool ArchivoDetallesCompra::bajaDetalleCompra(int id)
{
    DetalleTransaccion obj;
    ArchivoDetallesCompra archivo;

    int pos=archivo.obtenerUbicacionDetalleCompra(id);

    if(pos==-1) return false;

    obj=archivo.obtenerDetalleCompra(pos);
    obj.setEstado(false);
    return archivo.editarDetalleCompra(obj, pos);
}

bool ArchivoDetallesCompra::altaDetalleCompra(int id)
{
    DetalleTransaccion obj;
    ArchivoDetallesCompra archivo;

    int pos=archivo.obtenerUbicacionDetalleCompra(id);

    if(pos==-1) return false;

    obj=archivo.obtenerDetalleCompra(pos);
    obj.setEstado(true);
    return archivo.editarDetalleCompra(obj, pos);
}

bool ArchivoDetallesCompra::borrar() {
    FILE* p = fopen(_nombre, "wb");
    if (p == NULL) return false;
    fclose(p);
    return true;
}


