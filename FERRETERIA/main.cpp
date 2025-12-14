#include <iostream>
using namespace std;

#include "./menus/ventas.h"

int main(){
    int opc;

    while(true){
        system("cls");
        cout << " ----------------------------" << endl;
        cout << endl;
        cout << "         Ferreteria" << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << endl;
        cout << "   1. Ventas" << endl;
        cout << "   2. Compras" << endl;
        cout << "   3. Inventario" << endl;
        cout << "   4. Informes" << endl;
        cout << "   5. Configuracion" << endl;
        cout << "   0. SALIR " << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << " # Seleccione opcion: ";
        cin >> opc;

        switch(opc){

        case 1:
            ventas();
            break;
        case 2:
            //compras();
            break;
        case 0:
            return 0;
        }

    }

    return 0;
}
