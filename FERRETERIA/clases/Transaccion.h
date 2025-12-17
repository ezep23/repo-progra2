#ifndef TRANSACCION_H_INCLUDED
#define TRANSACCION_H_INCLUDED

#include "Fecha.h"
#include "Hora.h"

class Transaccion{
 private:
    int _id;
    int _idPersona;
    float _montoTotal;
    Hora _hora;
    Fecha _fecha;
    char _tipoFactura;
    bool _estado=true;
 public:

    Transaccion();
    Transaccion(int _id, int _idPersona, float _montoTotal, Hora _hora, Fecha _fecha, char _tipoFactura);

    /// VER ESTO
    void setIdTransaccion(int);
    void setIdPersona(int);
    void setMontoTotal(float);
    void setHoraEmision(Hora);
    void setFechaEmision(Fecha);
    void setTipoFactura(char);
    void setEstado(bool);

    int getIdTransaccion();
    int getIdPersona();
    float getMontoTotal();
    Hora getHoraTransaccion();
    Fecha getFechaTransaccion();
    char getTipoFactura();
    bool getEstado();

    void mostrar();
};


#endif // TRANSACCION_H_INCLUDED
