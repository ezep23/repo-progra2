#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "./funciones-menus/funcionesMenuInformes.h"

void informes(){
    int opc;
    while (true){
        system("cls");

        cout << " ----------------------------" << endl;
        cout << endl;
        cout << "      SUBMENU INFORMES     " << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << endl;


        cout << "   0. Volver al menu principal " << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << " # Seleccione opcion: ";
        cin >> opc;
        system("cls");

        if (opc == 0) break;

        switch (opc){
            case 1:
                listarRecaudacionMensual();
                system("pause");
                break;
            case 2:
                //listarProductos();
                system("pause");
                break;
            case 3:
                //editarProducto();
                system("pause");
                break;
            case 4:
                //eliminarProducto();
                system("pause");
                break;
            default:
                cout << "LA OPCION INGRESADA NO ES CORRECTA" << endl;
                system("pause");
                break;
            }
        }
}

#endif // INFORMES_H_INCLUDED
