#pragma once

class DetalleTransaccion{
 private:
    int _id;
    int _idTransaccion;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;
    bool _estado;
 public:

    DetalleTransaccion();
    DetalleTransaccion(int id, int idTransaccion, int idProducto, int cantidad, float precioUnitario);

    void setId(int);
    void setIdTransaccion(int);
    void setIdProducto(int);
    void setCantidad(int);
    void setPrecioUnitario(float);
    void setEstado(bool);

    int getId() const;
    int getIdTransaccion() const;
    int getIdProducto() const;
    int getCantidad() const;
    float getPrecioUnitario() const;
    bool getEstado() const;

};
