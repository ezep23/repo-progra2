#include <iostream>
#include <cstring>
using namespace std;

#include "Categoria.h"
#include "Producto.h"

Producto::Producto(){
    setId(0);
    setIdProveedor(0);
    setIdCategoria(0);
    setNombre("");
    setMarca("");
    setPrecio(0);
    setStock(0);
    setEstado(false);
}

Producto::Producto(int id, int idProveedor, int idCategoria, string nombre, string marca, float precio, int stock, bool estado){
    setId(id);
    setIdProveedor(idProveedor);
    setIdCategoria(idCategoria);
    setNombre(nombre);
    setMarca(marca);
    setPrecio(precio);
    setStock(stock);
    setEstado(true);
}
int Producto::getId() const{
    return _id;
}

int Producto::getIdProveedor() const{
    return _idProveedor;
}

int Producto::getIdCategoria() const{
    return _idCategoria;
}

string Producto::getNombre() const{
    return string(_nombre);
}

string Producto::getMarca() const{
    return string(_marca);
}

float Producto::getPrecio() const{
    return _precio;
}

int Producto::getStock() const{
    return _stock;
}

bool Producto::getEstado() const{
    return _estado;
}

void Producto::setId(int id ){
    _id = id;
}

void Producto::setIdProveedor(int id){
    _idProveedor = id;
}

void Producto::setIdCategoria(int id){
    _idCategoria = id;
}

void Producto::setNombre(string n){
    strncpy(_nombre, n.c_str(), 29);
}

void Producto::setMarca(string m){
    strncpy(_marca, m.c_str(), 29);
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
