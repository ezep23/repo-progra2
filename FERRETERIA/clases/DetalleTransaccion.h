#ifndef DETALLETRANSACCION_H_INCLUDED
#define DETALLETRANSACCION_H_INCLUDED

class DetalleTransaccion{
 private:
    int _id;
    int _idTransaccion;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;
    bool _estado;
 public:
    void setId(int);
    void setIdTransaccion(int);
    void setIdProducto(int);
    void setCantidad(int);
    void setPrecioUnitario(float);
    void setEstado(bool);

    int getId();
    int getIdTransaccion();
    int getIdProducto();
    int getCantidad();
    float getPrecioUnitario();
    bool getEstado();

    void cargar(int idTransaccion);
    void mostrar();
};


#endif // DETALLETRANSACCION_H_INCLUDED
