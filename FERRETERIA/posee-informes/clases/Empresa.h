#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

class Empresa{
 private:
     int _id;
     char _nombre[50];
     bool _estado=true;
 public:

    Empresa();
    Empresa(int id, const char* nombre, bool estado);

    void setId(int);
    void setNombre(const char *);
    void setEstado(bool);

    int getId();
    const char * getNombre();
    bool getEstado();

    void mostrar();
};

#endif // EMPRESA_H_INCLUDED
