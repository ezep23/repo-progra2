#include <iostream>
using namespace std;

#include "../../archivos/Ventas.h"
#include "../../clases/Fecha.h"


float listarRecaudacionMensual(){
 /**
    char anio[4];
    cout << "Ingrese el año: ";
    cin.ignore();
    cin.getline(anio, 4);

    char mes[2];
    cout << "Ingrese el mes: ";
    cin.ignore();
    cin.getline(mes, 2);

    ArchivoVentas ventas("Ventas.dat");
    Transaccion obj;
    Fecha fecha;

    if(ventas == NULL){
        cout << "ERROR DE ARCHIVO";
        return 0;
    }

    float acumRecaudacionMes = 0;

    while(fread(&obj, sizeof obj, 1, ) == 1){
        fecha = obj.getFechaTransaccion();

        if(fecha.getAnio() == anio){

            if(fecha.getMes() == mes){
                acumRecaudacionMes += obj.getMontoTotal();
            }
        }

    }

    return acumRecaudacionMes;


*/
}


