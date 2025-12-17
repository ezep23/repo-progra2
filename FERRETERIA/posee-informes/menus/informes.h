#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "./funciones-menus/funcionesMenuInformes.h"
//#include "../../

void listarRecaudacionMensual();
void listarRecaudacionAnual();
void listarProductosBajoStock();
void informeMasVendidos();

void informes()
{
    int opc;
    while (true)
    {
        system("cls");

        cout << " ----------------------------" << endl;
        cout << endl;
        cout << "      SUBMENU INFORMES     " << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << endl;
        cout << "   1. Recaudacion mensual por año" << endl;
        cout << "   2. Recaudacion por años" << endl;
        cout << "   3. Productos con bajo stock" << endl;
        cout << "   4. Procucto/s mas vendido/s" << endl;
        cout << "   5. Procucto/s menos vendido/s" << endl;
        cout << "   6. Cantidad de productos de cada proveedor" << endl;
        cout << "   7. Numero de ventas por proveedor" << endl;
        cout << "   8. Cantidad de ventas mensualmente por categoria" << endl;
        cout << "   9. Cantidad de ventas anualmente por categoria" << endl;
        cout << "   10. Cliente con mayor cantidad de productos comprados entre todad las ventas a ese cliente" << endl;
        cout << "   11. Cantidad total de productos vendida de una categoría que se ingresa por teclado" << endl;
        cout << "   0. Volver al menu principal " << endl;
        cout << endl;
        cout << " ----------------------------" << endl;
        cout << " # Seleccione opcion: ";
        cin >> opc;
        system("cls");

        if (opc == 0) break;

        switch (opc)
        {
        case 1:
            listarRecaudacionMensual();
            system("pause");
            break;
        case 2:
            listarRecaudacionAnual();
            system("pause");
            break;
        case 3:
            listarProductosBajoStock();
            system("pause");
            break;
        case 4:
            informeMasVendidos();
            system("pause");
            break;
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
        default:
            cout << "LA OPCION INGRESADA NO ES CORRECTA" << endl;
            system("pause");
            break;
        }
    }
}

#endif // INFORMES_H_INCLUDED
