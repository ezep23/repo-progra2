#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED

#include "./funciones-menus/funcionesMenuCompras.h"

void compras(){

    int opc = 1;
    while (opc != 0){
        system("cls");

        cout << " ----------------------------" << endl;
        cout << endl;
        cout << "       SUBMENU COMPRAS" << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << endl;
        cout << "   1. Nueva compra" << endl;
        cout << "   2. Editar compra" << endl;
        cout << "   3. Listar compras" << endl;
        cout << "   4. Eliminar compra" << endl;
        cout << "   5. Listar proveedores" << endl;
        cout << "   6. Eliminar proveedor" << endl;
        cout << "   0. Volver al menu principal " << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << " # Seleccione opcion: ";
        cin >> opc;
        system("cls");

        if (opc == 0) break;

        switch (opc){
            case 1:
                nuevaCompra();
                system("pause");
                break;
            case 2:
                modificarCompra();
                system("pause");
                break;
            case 3:
                listarCompra();
                system("pause");
                break;
            case 4:
                eliminarCompra();
                system("pause");
                break;
            case 5:
                listarProveedores();
                system("pause");
                break;
            case 6:
                eliminarProveedor();
                system("pause");
                break;
            default:
                cout << "LA OPCION INGRESADA NO ES CORRECTA" << endl;
                system("pause");
                break;
            }
        }
}





#endif // COMPRAS_H_INCLUDED
