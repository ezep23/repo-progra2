#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

class Categoria {
 private:
     int  _id;
     char _nombre[25];
     bool _estado;
 public:

    void setId(int);
    void setNombre(const char*);
    void setEstado(bool);

    int getId();
    const char* getNombre();
    bool getEstado();

    void cargar(int);
    void mostrar();
};

#endif // CATEGORIA_H_INCLUDED
