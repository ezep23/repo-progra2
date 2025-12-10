#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include "./funciones-menus/funcionesMenuVentas.h"

int ventas(){

    int opc;
    while (true){
        system("cls");
        cout << "=========================================";
        cout << "SUBMENU CLIENTES" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "1 - GENERAR VENTA" << endl;
        cout << "2 - LISTAR VENTAS" << endl;
        cout << "3 - ELIMINAR VENTA" << endl;
        cout << "4 - LISTAR CLIENTE" << endl;
        cout << "5 - ELIMINAR CLIENTE" << endl;
        cout << "0 - VOLVER AL MENU PRINCIPAL" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "INGRESE LA OPCION: ";
        cin >> opc;
        system("cls");

        if (opc == 0) break;

        switch (opc){
            case 0:
                break;
            case 1:
                crearVenta();
                system("pause");
                break;
            case 2:
                listarVentas();
                system("pause");
                break;
            case 3:
                eliminarVenta();
                system("pause");
                break;
            case 4:
                listarCliente();
                system("pause");
                break;
            case 5:
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
