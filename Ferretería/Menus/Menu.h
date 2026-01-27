#pragma once

class Menu{
  public:
    Menu();
    void mostrar();

  protected:
    virtual void mostrarOpciones();
    virtual void ejecutarOpcion(int opcion);
    int seleccionarOpciones();

    int _cantidadOpciones;
  private:
};
