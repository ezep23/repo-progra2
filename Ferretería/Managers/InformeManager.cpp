#include <iostream>
using namespace std;

#include "InformeManager.h"

InformeManager::InformeManager(){

}

void InformeManager::recaudacionMensual(){
    int anio;

    cout << "Ingrese el anio: ";
    cin >> anio;

    _ventaManager.recaudacionMensual(anio);
}

void InformeManager::recaudacionAnual(){

    _ventaManager.recaudacionAnual();
}
