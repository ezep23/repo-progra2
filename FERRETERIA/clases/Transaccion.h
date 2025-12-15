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
    char _tipoFactura[4];
    bool _estado=true;
 public:

    Transaccion();
    Transaccion(int _id, int _idPersona, float _montoTotal, Hora _hora, Fecha _fecha, const char* _tipoFactura);

    /// VER ESTO
    void setIdTransaccion(int);
    void setIdPersona(int);
    void setMontoTotal(float);
    void setHoraEmision(Hora);
    void setFechaEmision(Fecha);
    void setTipoFactura(const char*);
    void setEstado(bool);

    int getIdTransaccion();
    int getIdPersona();
    float getMontoTotal();
    Hora getHoraTransaccion();
    Fecha getFechaTransaccion();
    void getTipoFactura();
    bool getEstado();

    void mostrar();
};


#endif // TRANSACCION_H_INCLUDED
