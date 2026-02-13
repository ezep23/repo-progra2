#pragma once

#include "Fecha.h"
#include "Hora.h"

class Transaccion{
 private:
    int _id;
    int _idPersona;
    int _idEmpleado;
    float _montoTotal;
    Hora _hora;
    Fecha _fecha;
    char _tipoFactura;
    bool _estado;
 public:

    Transaccion();
    Transaccion(int _id, int _idPersona, int _idEmpleado, float _montoTotal, Hora _hora, Fecha _fecha, char _tipoFactura);

    /// VER ESTO
    void setIdTransaccion(int);
    void setIdPersona(int);
    void setIdEmpleado(int);
    void setMontoTotal(float);
    void setHoraEmision(Hora);
    void setFechaEmision(Fecha);
    void setTipoFactura(char);
    void setEstado(bool);

    int getIdTransaccion() const;
    int getIdPersona() const;
    int getIdEmpleado() const;
    float getMontoTotal() const;
    Hora getHoraTransaccion() const;
    Fecha getFechaTransaccion() const;
    char getTipoFactura() const;
    bool getEstado() const;
};
