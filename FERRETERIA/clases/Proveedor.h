#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

class Proveedor : protected Persona{
 private:
    int _idProveedor;
    int _idDeEmpresa;
    char _razonSocial[50];

 public:

    void setId(int);
    void setIdDeEmpresa(int);
    void setRazonSocial(const char*);

    int getId();
    int getIdDeEmpresa();
    char getRazonSocial();

    void cargar();
    void mostrar();

};

#endif // PROVEEDOR_H_INCLUDED
