#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

class Cliente : protected Persona{
 private:
    int _idCliente;
    char _cuit_dni[15];
 public:

    /// AGREGAR CONSTRUCTORES

    void setId(int);
    void setCuitDni(const char*);

    int getId();
    char getCuitDni();

    void cargar();
    void mostrar();

};

#endif // CLIENTE_H_INCLUDED
