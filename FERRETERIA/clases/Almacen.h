#ifndef ALMACEN_H_INCLUDED
#define ALMACEN_H_INCLUDED

class Almacen{
 public:
     bool descontarStock(int id, int cantidad);
     bool reponerStock(int id, int cantidad);
     void consultarStock();
     void consultarProductosBajoStock();
};

#endif // ALMACEN_H_INCLUDED
