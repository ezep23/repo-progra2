#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{
 private:
     int _id;
     int _idProveedor;
     int _idCategoria;
     char _nombre[50];
     char _marca[50];
     char _categoria[50];
     float _precio;
     int _stock;
     bool _estado;
 public:

    Producto();
    Producto(int id, int idProveedor, int idCategoria, const char* nombre, const char* marca, const char* categoria, float precio, int stock, bool estado);

    int getId();
    int getIdProveedor();
    int getIdCategoria();
    const char* getNombre();
    const char* getMarca();
    const char* getCategoria();
    float getPrecio();
    int getStock();
    bool getEstado();

    void setId(int);
    void setIdProveedor(int);
    void setIdCategoria(int);
    void setNombre(const char *);
    void setMarca(const char*);
    void setCategoria(const char*);
    void setPrecio(float);
    void setStock(int);
    void setEstado(bool);

    void cargar(int idProveedor);
    void mostrar();
};

#endif // PRODUCTO_H_INCLUDED
