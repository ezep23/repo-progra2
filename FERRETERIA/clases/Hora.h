#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

class Hora {
  private:
    int _hora;
    int _minutos;
  public:

    Hora();
    Hora(int h, int m);

    void setHora(int);
    void setMinutos(int);

    int getHora( );
    int getMinutos();

    bool validarHora(int h, int m);

    void cargar();
    void mostrar();
};


#endif // HORA_H_INCLUDED
