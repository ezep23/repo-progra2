#ifndef ALMACEN_H_INCLUDED
#define ALMACEN_H_INCLUDED

class Almacen{
 public:
     bool descontarStock(int id, int cantidad);
     bool reponerStock(int id, int cantidad);

     void listarProducto(int id);
     void listarProductosCategoria(int idCat);
     void listarProductosInactivos();
     void listarProductosInactivosCategoria(int idCat);

     void consultarStock(int id);
     void consultarProductosBajoStock();
     void consultarProductosBajoStock(int idCat);
     void consultarProductosProveedor(int id);
     void consultarProductosMismoNombre(const char* nombre);
     void consultarProductoMismaMarca(const char* marca);
};



#endif // ALMACEN_H_INCLUDED
