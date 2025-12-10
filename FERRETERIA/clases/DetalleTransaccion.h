#ifndef DETALLETRANSACCION_H_INCLUDED
#define DETALLETRANSACCION_H_INCLUDED

class DetalleTransaccion{
 private:
    int _id;
    int _idTransaccion;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;

    void setId(int);
    void setIdTransaccion(int);
    void setIdProducto(int);
    void setCantidad(int);
    void setPrecioUnitario(float);

    int getId();
    int getIdTransaccion();
    int getIdProducto();
    int getCantidad();
    float getPrecioUnitario();

    void cargar(int idTransaccion);
    void mostrar();
};


#endif // DETALLETRANSACCION_H_INCLUDED
