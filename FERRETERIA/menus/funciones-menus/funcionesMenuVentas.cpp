#include <iostream>
using namespace std;

#include "../../clases/Transaccion.h"
#include "../../clases/Almacen.h"
#include "../../archivos/Ventas.h"
#include "../../archivos/DetalleVentas.h"
#include "../../archivos/Clientes.h"

void nuevaVenta(){
    ArchivoVentas ventas("Ventas.dat");
    ArchivoDetallesVenta detallesVenta("DetallesVentas.dat");
    ArchivoClientes clientes("Clientes.dat");
    Transaccion nuevaVenta;
    DetalleTransaccion detalleVenta;

    cout << "----- NUEVA VENTA -----" << endl;
    nuevaVenta.setIdTransaccion( ventas.generarNuevoID() );

    char opcCliente;
    cout << " Es un cliente nuevo? - Si 'S', No 'N'"<< endl;
    cout << " Opcion:";
    cin >> opcCliente;

    if(opcCliente == 'S' || opcCliente == 's'){
        Cliente nuevoCliente;
        nuevoCliente.cargar();

        int newID = clientes.generarNuevoID();

        if( newID <= 0 ){
            cout << "Error al crear nuevo id" << endl;
        }

        nuevoCliente.setId(newID);

        clientes.guardarCliente(nuevoCliente);

        cout << "  Cliente creado ";
        nuevoCliente.mostrar();

    } else {
        int opcId;
        cout << " Ingrese el ID del cliente - Presione 0 para listar" << endl;
        cout << " Opcion:";
        cin >> opcId;

        if(opcId == 0){

            clientes.listarClientes();

            cout << " Ingrese el ID del cliente: ";
            cin >> opcId;

        } else {

            /// VALIDACIÓN PREVIA
            /// - NO SEA ID < 0
            /// - NO SE REPITA

            nuevaVenta.setIdPersona( opcId );
        }
    }

    system("cls");
    cout << " ------------------------------------" << endl;
    cout << "         Detalles de la venta        " << endl;
    system("pause");

    int opcDetalle=1;
    while(opcDetalle != 0){

        cout << " ------------------------------------" << endl;
        cout << "         Detalle de venta " << opcDetalle << endl;
        detalleVenta.cargar( nuevaVenta.getIdTransaccion() );
        cout << " -------------------------------------" << endl;
        system("cls");


        detallesVenta.guardarDetalleVenta(detalleVenta);
        system("pause");

        char opcSeguir;
        cout << " Desea agregar otro detalle de venta? - Si 'S' o No 'N'" << endl;
        cout << " Opcion: ";
        cin  >> opcSeguir;

        if(opcSeguir == 'N' || opcSeguir == 'n'){
            opcDetalle = 0;
        }else{
            opcDetalle++;
        }

    }

}

void listarVentas(){
cout << "Listando ventas..." << endl;
}
void eliminarVenta(){
cout << "Listando ventas..." << endl;
}
void listarCliente(){
cout << "Listando ventas..." << endl;
}
void eliminarCliente(){
cout << "Listando ventas..." << endl;
}
