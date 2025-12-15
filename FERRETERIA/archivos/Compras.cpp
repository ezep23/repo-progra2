#include "Compras.h"
#include "../clases/Transaccion.h"

#include <iostream>
using namespace std;


void ArchivoCompras::validarArchivoExiste()
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

int ArchivoCompras::contarCompras(){
    validarArchivoExiste();

    FILE *p = fopen("Ventas.dat", "rb");

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Transaccion);
}

int ArchivoCompras::generarNuevoID(){

    validarArchivoExiste();

    int numCompras = contarCompras();
    Transaccion compra = obtenerCompra(numCompras - 1);
    return compra.getIdTransaccion() + 1;
}

bool ArchivoCompras::guardarCompra(Transaccion compra){

    validarArchivoExiste();

    FILE *p=fopen(_nombre, "ab");
    bool guardado=fwrite(&compra, _tamCompra, 1, p);
    fclose(p);

    return guardado;
}

bool ArchivoCompras::editarCompra(Transaccion compra, int pos){
    validarArchivoExiste();

    FILE *p=fopen(_nombre, "rb+");
    fseek(p, pos*sizeof compra,0);
    bool escribio=fwrite(&compra, sizeof compra, 1, p);
    fclose(p);
    return escribio;
}

Transaccion ArchivoCompras::obtenerCompra(int pos){

    validarArchivoExiste();

    Transaccion compra;
    FILE *p = fopen(_nombre, "rb");

    compra.setMontoTotal(-1);

    fseek(p, pos * _tamCompra, 0);
    fread(&compra, _tamCompra, 1,p);

    fclose(p);
    return compra;
}

int ArchivoCompras::obtenerUbicacionCompra(int id){

    validarArchivoExiste();

    Transaccion compra;
    FILE *p=fopen("Compras.dat","rb");

    int pos=0;

    while(fread(&compra, sizeof compra, 1, p) ==1 )
    {
        if(compra.getIdTransaccion() == id)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -2;
}

bool ArchivoCompras::listarCompras(){

    validarArchivoExiste();

    Transaccion compra;
    FILE *p=fopen(_nombre,"rb");

    while(fread(&compra, _tamCompra, 1, p)==1){

        if(compra.getEstado()){
            compra.mostrar();
        }
    }

    fclose(p);
    return true;

}

bool ArchivoCompras::listarComprasInactivas(){

    validarArchivoExiste();

    Transaccion compra;
    FILE *p = fopen(_nombre,"rb");

    while(fread(&compra, _tamCompra, 1, p)==1){

        if(!compra.getEstado()){
            compra.mostrar();
        }

    }

    fclose(p);
    return true;

}

bool ArchivoCompras::bajaCompra(int id)
{

    Transaccion compra;
    ArchivoCompras archivo;

    int pos=archivo.obtenerUbicacionCompra(id);

    if(pos==-1) return false;

    compra=archivo.obtenerCompra(pos); ///en reg tengo el registro a borrar
    compra.setEstado(false);
    return archivo.editarCompra(compra, pos);

}

bool ArchivoCompras::altaCompra(int id)
{

    Transaccion compra;
    ArchivoCompras archivo;

    int pos=archivo.obtenerUbicacionCompra(id);

    if(pos==-1) return false;

    compra=archivo.obtenerCompra(pos); ///en reg tengo el registro a dar de alta
    compra.setEstado(true);
    return archivo.editarCompra(compra, pos);

}

bool ArchivoCompras::borrar() {
    FILE* p = fopen(_nombre, "wb");
    if (p == NULL) return false;
    fclose(p);
    return true;
}
