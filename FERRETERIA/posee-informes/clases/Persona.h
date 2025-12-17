#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{
protected:
   char _nombre[50];
   char _apellido[50];
   char _telefono[20];
   char _email[25];
public:

    Persona();
    Persona(const char* nombre, const char* apellido, const char* telefono, const char* email);

    void setNombre(const char*);
    void setApellido(const char*);
    void setTelefono(const char*);
    void setEmail(const char*);

    const char* getNombre();
    const char* getApellido();
    const char* getTelefono();
    const char* getEmail();
};


#endif // PERSONA_H_INCLUDED
