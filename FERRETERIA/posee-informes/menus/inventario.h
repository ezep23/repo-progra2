#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED

#include "./funciones-menus/funcionesMenuInventario.h"

void inventario(){
    int opc;
    while (true){
        system("cls");

        cout << " ----------------------------" << endl;
        cout << endl;
        cout << "      SUBMENU INVENTARIO     " << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << endl;
        cout << "   1. Agregar producto" << endl;
        cout << "   2. Listar productos" << endl;
        cout << "   3. Editar producto" << endl;
        cout << "   4. Eliminar producto" << endl;
        cout << "   0. Volver al menu principal " << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << " # Seleccione opcion: ";
        cin >> opc;
        system("cls");

        if (opc == 0) break;

        switch (opc){
            case 1:
                nuevoProducto();
                system("pause");
                break;
            case 2:
                listarProductos();
                system("pause");
                break;
            case 3:
                editarProducto();
                system("pause");
                break;
            case 4:
                eliminarProducto();
                system("pause");
                break;
            default:
                cout << "LA OPCION INGRESADA NO ES CORRECTA" << endl;
                system("pause");
                break;
            }
        }
}

#endif // INVENTARIO_H_INCLUDED
