#include <iostream>
using namespace std;

//#include "../archivos/menus/funciones-menu/informes.h"
#include "../../archivos/Ventas.h"
#include "../../clases/Fecha.h"
#include "../../clases/Transaccion.h"
#include "../../clases/Producto.h"
#include "../../archivos/DetalleVentas.h"
#include "../../archivos/Productos.h"

void listarRecaudacionMensual()
{
    int anioBuscar;
    cout << "Ingrese el anio: ";
    cin >> anioBuscar;


    FILE *p = fopen("Ventas.dat", "rb");
    if(p == NULL)
    {
        cout << "ERROR: No se pudo abrir el archivo Ventas.dat" << endl;
        return;
    }

    Transaccion obj;

    float recaudacionPorMes[12] = {0};

    while(fread(&obj, sizeof(Transaccion), 1, p) == 1)
    {
        int anioVenta = obj.getFechaTransaccion().getAnio();
        int mesVenta = obj.getFechaTransaccion().getMes();

        if(anioVenta == anioBuscar)
        {
            if(mesVenta >= 1 && mesVenta <= 12)
            {
                recaudacionPorMes[mesVenta - 1] += obj.getMontoTotal();
            }
        }
    }
    fclose(p);

    system("cls");
    cout << "RECAUDACION MENSUAL DEL ANIO " << anioBuscar << endl;
    cout << "--------------------------------" << endl;

    const char *nombresMeses[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

    float recaudacionTotalAnual = 0;

    for(int i = 0; i < 12; i++)
    {
        cout << nombresMeses[i] << ": $ " << recaudacionPorMes[i] << endl;

        recaudacionTotalAnual += recaudacionPorMes[i];
    }

    cout << "--------------------------------" << endl;
    //cout << "TOTAL ANUAL: $ " << recaudacionTotalAnual << endl;
    system("pause");

    return ;//recaudacionTotalAnual;
}


void listarRecaudacionAnual()
{
    FILE *p = fopen("Ventas.dat", "rb");
    if (p == NULL)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }
    int anios[10];
    float recaudaciones[10];
    int cantidad = 0;

    for(int i=0; i<50; i++)
    {
        anios[i] = 0;
        recaudaciones[i] = 0;
    }

    Transaccion venta;
    while (fread(&venta, sizeof(Transaccion), 1, p) == 1)
    {

        int anioVuelta = venta.getFechaTransaccion().getAnio();
        float monto = venta.getMontoTotal();

        int pos = -1;
        for(int i = 0; i < cantidad; i++)
        {
            if(anios[i] == anioVuelta)
            {
                pos = i;
                break;
            }
        }

        if (pos != -1)
        {
            recaudaciones[pos] += monto;
        }
        else
        {
            if(cantidad < 50)
            {
                anios[cantidad] = anioVuelta;
                recaudaciones[cantidad] = monto;
                cantidad++;
            }
        }
    }
    fclose(p);
///Ordenamos
    for(int i = 0; i < cantidad - 1; i++)
    {
        for(int j = 0; j < cantidad - i - 1; j++)
        {
            if(anios[j] > anios[j+1])
            {

                int auxAnio = anios[j];
                anios[j] = anios[j+1];
                anios[j+1] = auxAnio;

                float auxRec = recaudaciones[j];
                recaudaciones[j] = recaudaciones[j+1];
                recaudaciones[j+1] = auxRec;
            }
        }
    }


    system("cls");
    cout << "RECAUDACION POR ANIO" << endl;
    cout << "--------------------" << endl;

    for(int i = 0; i < cantidad; i++)
    {
        cout << "Anio " << anios[i] << ": $ " << recaudaciones[i] << endl;
    }

    cout << "--------------------" << endl;
    system("pause");
}


void listarProductosBajoStock()
{

    FILE *p = fopen("Productos.dat", "rb");
    if(p == NULL)
    {
        cout << "No se pudo abrir el archivo de productos." << endl;
        return;
    }

    Producto prod;
    int contador = 0;

    system("cls");
    cout << "========================================" << endl;
    cout << "    PRODUCTOS CON BAJO STOCK     " << endl;
    cout << "========================================" << endl;

    while(fread(&prod, sizeof(Producto), 1, p) == 1)
    {
        if(prod.getStock() <= 10)
        {
            prod.mostrar();
            cout << " ID: " << prod.getId()<< " | " << prod.getNombre()<< " | Stock: " << prod.getStock() << endl;
            cout << "----------------------------------------" << endl;
            contador++;


        }
    }

    fclose(p);

    if(contador == 0)
    {
        cout << "No hay productos con bajo stock" << endl;
    }/*
else
{
    cout << "Total de productos con bajo stock: " << contador << endl;
}
*/
    system("pause");
}


void informeMasVendidos()
{
    system("cls");
    cout << "========================================" << endl;
    cout << "         PRODUCTOS MAS VENDIDOS            " << endl;
    cout << "========================================" << endl;

    FILE *p = fopen("DetallesVentas.dat", "rb");
    if(p == NULL)
    {
        cout << "No hay ventas registradas." << endl;
        system("pause");
        return;
    }

    int ids[100]= {0}, cantidades[100]= {0}, contador = 0;

    DetalleTransaccion reg;

    while(fread(&reg, sizeof(DetalleTransaccion), 1, p) == 1)
    {

        int idLeido = reg.getIdProducto();
        int cantLeida = reg.getCantidad();

        int pos = -1;
        for(int i=0; i < contador; i++)
        {
            if(ids[i] == idLeido)
            {
                pos = i;
                break;
            }
        }

        if(pos != -1)
        {
            cantidades[pos] += cantLeida;
        }
        else
        {
            if(contador < 100)
            {
                ids[contador] = idLeido;
                cantidades[contador] = cantLeida;
                contador++;
            }
        }
    }
    fclose(p);
    // Ordenamos
    for(int i=0; i < contador - 1; i++)
    {
        for(int j=0; j < contador - i - 1; j++)
        {

            if(cantidades[j] < cantidades[j+1])
            {
                int auxCant = cantidades[j];
                cantidades[j] = cantidades[j+1];
                cantidades[j+1] = auxCant;

                int auxId = ids[j];
                ids[j] = ids[j+1];
                ids[j+1] = auxId;
            }
        }
    }
    ArchivoProductos archiProd("Productos.dat");
    int limite;
    for(int i=0; i < limite; i++)
    {
        if (contador < 3)
        {
            limite = contador;
        }
        else
        {
            limite = 3;
        }
        cout << "RANK \t CANT \t PRODUCTO" << endl;
        cout << "----------------------------------------" << endl;

        for(int i=0; i < limite; i++)
        {

            int posArch = archiProd.obtenerUbicacionProducto(ids[i]);

            cout << " Nro" << (i+1) << "\t  " << cantidades[i] << "\t ";

            if(posArch >= 0)
            {
                Producto prod = archiProd.obtenerProducto(posArch);
                cout << prod.getNombre();
            }
            else
            {
                cout << "ID: " << ids[i];
            }
            cout << endl;
        }

        cout << "----------------------------------------" << endl;
        system("pause");
    }
}


