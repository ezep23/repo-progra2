#include <iostream>
#include<string>
using namespace std;

#include "../archivos/Productos.h"
#include "../archivos/Categorias.h"
#include "Categoria.h"
#include "Producto.h"

Producto::Producto(){
    _id = 0;
    _idProveedor = 0;
    _idCategoria = 0;
    strcpy(_nombre, "");
    strcpy(_marca, "");
    _precio = 0;
    _stock = 0;
    _estado = true;
}

Producto::Producto(int id, int idProveedor, int idCategoria, const char* nombre, const char* marca, float precio, int stock, bool estado){
    _id = id;
    _idProveedor = idProveedor;
    _idCategoria = idCategoria;
    strcpy(_nombre, nombre);
    strcpy(_marca, marca);
    _precio = precio;
    _stock = stock;
    _estado = estado;
}

int Producto::getId(){
    return _id;
}

int Producto::getIdProveedor(){
    return _idProveedor;
}

int Producto::getIdCategoria(){
    return _idCategoria;
}

const char* Producto::getNombre(){
    return _nombre;
}

const char* Producto::getMarca(){
    return _marca;
}

float Producto::getPrecio(){
    return _precio;
}

int Producto::getStock(){
    return _stock;
}

bool Producto::getEstado(){
    return _estado;
}

void Producto::setId(int id){
    _id = id;
}

void Producto::setIdProveedor(int id){
    _idProveedor = id;
}

void Producto::setIdCategoria(int id){
    _idCategoria = id;
}

void Producto::setNombre(const char * n){
    strcpy(_nombre, n);
}

void Producto::setMarca(const char* m){
    strcpy(_marca, m);
}

void Producto::setPrecio(float p){
    _precio = p;
}

void Producto::setStock(int st){
    _stock = st;
}

void Producto::setEstado(bool e){
    _estado = e;
}

void Producto::cargar(int proveedor){
    ArchivoProductos archivo("Productos.dat");
    ArchivoCategorias categorias("Categorias.dat");
    Categoria cat;
    Producto obj;

    _idProveedor = proveedor;
    cout << " ID PROVEEDOR: " << _idProveedor << endl;

    _id = archivo.generarNuevoID();
    cout<<" ID ARTICULO: "<< _id <<endl;

    cout<<"NOMBRE: ";
    cin>>_nombre;

    while(archivo.validarNombre(_nombre)){
        cout<<"NOMBRE existente. ingrese nuevamente: ";
        cin>>_nombre;
    }

    cin.ignore();
    cout<<"PRECIO UNITARIO DE ARTICULO: ";
    cin>>_precio;

    cout<<"NOMBRE DE CATEGORIA: ";
    cin.ignore();
    cin.getline(_categoria, 50);

    if(categorias.validarCategoriaExiste(_categoria)){
        int ubi = categorias.obtenerUbicacionCategoria(_categoria);
        Categoria catnueva = categorias.obtenerCategoria(ubi);
        _idCategoria = catnueva.getId();
    }else{
        _idCategoria = categorias.generarNuevoID();

        cat.setId(_idCategoria);
        cat.setNombre(_categoria);
        categorias.guardarCategoria(cat);

    }


    cin.ignore();
    cout<<"STOCK: ";
    cin>>_stock;

    _estado=true;

}

void Producto::mostrar(){
cout<<" -------------------------------" << endl;
cout<<"  ID: "<< _id << endl;
cout<<"  ID PROVEEDOR: " << _idProveedor << endl;
cout<<"  ID CATEGORIA: "<<_idCategoria<<endl;
cout<<"  NOMBRE: "<< _nombre <<endl;
cout<<"  CATEGORIA: "<< _categoria << endl;
cout<<"  MARCA: "<<_marca<<endl;
cout<<"  PRECIO UNITARIO DE ARTICULO: "<< _precio <<endl;
cout<<"  STOCK: "<<_stock<<endl;
cout<<" -------------------------------" << endl;
}
