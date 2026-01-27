#include <iostream>
#include "utils.h"

std::string cargarCadena()
{
  std::string texto;

  if(std::cin.peek() == '\n')
  {
    std::cin.ignore();
  }

  std::getline(std::cin, texto);

  return texto;
}

bool validarDNI(std::string dni) {

    if (dni.length() > 8 || dni.length() == 0) {
        return false;
    }

    std::string numerosValidos = "0123456789";

    for (int i = 0; i < dni.length(); i++) {

        char caracterDni = dni[i];
        bool coincidencia = false;

        if (i == 0 && caracterDni == '0') {
            return false;
        }

        for (int j = 0; j < 10; j++) {
            if (caracterDni == numerosValidos[j]) {
                coincidencia = true;
                break;
            }
        }

        if (coincidencia == false) {
            return false;
        }
    }

    return true;
}
