#pragma once
#include <string>

#include "Categoria.h"

class Producto{
 private:
     int _id;
     int _idProveedor;
     int _idCategoria;
     char _nombre[30];
     float _precio;
     int _stock;
     bool _estado;
 public:

    Producto();
    Producto(int id, int idProveedor, int idCategoria, std::string nombre, float precio, int stock);

    int getId() const;
    int getIdProveedor() const;
    int getIdCategoria() const;
    std::string getNombre() const;
    float getPrecio() const;
    int getStock() const;
    bool getEstado() const;

    void setId(int);
    void setIdProveedor(int);
    void setIdCategoria(int);
    void setNombre(std::string);
    void setPrecio(float);
    void setStock(int);
    void setEstado(bool);
};
