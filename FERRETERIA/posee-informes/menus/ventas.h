#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include "./funciones-menus/funcionesMenuVentas.h"

void ventas(){

    int opc;
    while (true){
        system("cls");

        cout << " ----------------------------" << endl;
        cout << endl;
        cout << "       SUBMENU VENTAS" << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << endl;
        cout << "   1. Nueva venta" << endl;
        cout << "   2. Editar venta" << endl;
        cout << "   3. Listar ventas" << endl;
        cout << "   4. Eliminar venta" << endl;
        cout << "   5. Listar clientes" << endl;
        cout << "   6. Eliminar cliente" << endl;
        cout << "   0. Volver al menu principal " << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << " # Seleccione opcion: ";
        cin >> opc;
        system("cls");

        if (opc == 0) break;

        switch (opc){
            case 1:
                nuevaVenta();
                system("pause");
                break;
            case 2:
                modificarVenta();
                system("pause");
                break;
            case 3:
                listarVentas();
                system("pause");
                break;
            case 4:
                eliminarVenta();
                system("pause");
                break;
            case 5:
                listarClientes();
                system("pause");
                break;
            case 6:
                eliminarCliente();
                system("pause");
                break;
            default:
                cout << "LA OPCION INGRESADA NO ES CORRECTA" << endl;
                system("pause");
                break;
            }
        }
}









#endif // VENTAS_H_INCLUDED
