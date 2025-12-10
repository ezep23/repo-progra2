#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

class Categoria {
 private:
     int  _idCategoria;
     char[50] _nombre;
 public:

    void  setNombre(const char*);

    int getIDCategoria();
    const char* getNombre();

    void cargar(int);
    void mostrar();
};

#endif // CATEGORIA_H_INCLUDED
