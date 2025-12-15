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
};



#endif // ALMACEN_H_INCLUDED
