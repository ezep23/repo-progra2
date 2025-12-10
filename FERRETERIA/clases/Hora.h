#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

Habría que encontrar una forma de setear la hora actual.

class Hora {
  private:
    int _hora;
    int _minutos;
    int _segundos;
  public:

    Hora();
    Hora();

    void setHora(int);
    void setMinutos(int);
    void setSegundos(int);

    int getHora( );
    int getMinutos();
    int getSegundos();

    void setHoraActual();
    void Mostrar();

}


#endif // HORA_H_INCLUDED
