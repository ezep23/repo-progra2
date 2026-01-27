#pragma once
#include <string>

#include "Categoria.h"

class Producto{
 private:
     int _id;
     int _idProveedor;
     int _idCategoria;
     char _nombre[30];
     char _marca[30];
     float _precio;
     int _stock;
     bool _estado;
 public:

    Producto();
    Producto(int id, int idProveedor, int idCategoria, std::string nombre, std::string marca, float precio, int stock, bool estado);

    int getId() const;
    int getIdProveedor() const;
    int getIdCategoria() const;
    std::string getNombre() const;
    std::string getMarca() const;
    float getPrecio() const;
    int getStock() const;
    bool getEstado() const;

    void setId(int);
    void setIdProveedor(int);
    void setIdCategoria(int);
    void setNombre(std::string);
    void setMarca(std::string);
    void setPrecio(float);
    void setStock(int);
    void setEstado(bool);
};
