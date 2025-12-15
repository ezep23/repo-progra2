#include <iostream>
using namespace std;

#include "../../clases/Transaccion.h"
#include "../../clases/Almacen.h"
#include "../../clases/Fecha.h"
#include "../../clases/Hora.h"
#include "../../archivos/Ventas.h"
#include "../../archivos/DetalleVentas.h"
#include "../../archivos/Clientes.h"

void nuevaVenta(){
    ArchivoVentas ventas("Ventas.dat");
    ArchivoDetallesVenta detallesVenta("DetallesVentas.dat");
    ArchivoClientes clientes("Clientes.dat");
    Transaccion nuevaVenta;
    DetalleTransaccion detalleVenta;
    Hora hora;
    Fecha fecha;

    cout << "------- NUEVA VENTA -------" << endl;
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

        if(opcId <= 0){

            cout << "No puede ingresar ese ID.";
            system("pause");

            while(opcId <= 0){
                system("cls");
                clientes.listarClientes();

                cout << " Ingrese el ID del cliente: ";
                cin >> opcId;
            }

            while(!clientes.validarIdExiste(opcId) && opcId > 0){
                    system("cls");
                    cout << " Ese id no existe, ingrese uno existente: ";
                    cin >> opcId;
            }

            nuevaVenta.setIdPersona( opcId );

        } else {

            while(!clientes.validarIdExiste(opcId) && opcId > 0){
                    system("cls");
                    cout << " Ese id no existe, ingrese uno existente: ";
                    cin >> opcId;
            }

            nuevaVenta.setIdPersona( opcId );
        }
    }

    system("cls");
    cout << " ------------------------------------" << endl;
    cout << "         Detalles de la venta        " << endl;
    cout << " ------------------------------------" << endl;
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

    /// SE CARGA FECHA Y HORA DE EMISIÓN
    fecha.cargar();
    hora.cargar();

    /// SE TERMINA DE COMPLETAR LOS DATOS DE LA VENTA
    nuevaVenta.setMontoTotal( detallesVenta.obtenerMontoTotal( nuevaVenta.getIdTransaccion() ) );
    nuevaVenta.setFechaEmision(fecha);
    nuevaVenta.setHoraEmision(hora);

    if(ventas.guardarVenta(nuevaVenta)){
        cout << "ERROR NO SE PUDO GUARDAR LA VENTA" << endl;
    }

    /// CUANDO SE TERMINA DE TIPEAR SE MUESTRA
    nuevaVenta.mostrar();
    detallesVenta.listarDetallesDeVenta( nuevaVenta.getIdTransaccion() );

}

void modificarVenta(){
    system("cls");
    ArchivoVentas ventas("Ventas.dat");
    int opc;
    cout << "------ EDITAR VENTA -------" << endl;
    cout << " Ingrese el ID de la venta: ";
    cin >> opc;



}

void listarVentas(){
    system("cls");
    ArchivoVentas ventas("Ventas.dat");
    int opc;

    cout << " ---------------------------" << endl;
    cout << "           SUBMENU          " << endl;
    cout << " ---------------------------" << endl;
    cout << " 1. Listar ventas" << endl;
    cout << " 2. Listar venta por id" << endl;
    cout << " Opcion: ";
    cin >> opc;

    if(opc == 1){
        ventas.listarVentas();
        return;
    }

    if(opc == 2){
        int id;
        system("cls");
        cout << " Ingrese el ID de la venta: ";
        cin >> id;

        int pos = ventas.obtenerUbicacionVenta(id);
        Transaccion busqueda = ventas.obtenerVenta(pos);
        busqueda.mostrar();
        return;
    }

    cout << "OPCIÓN INVALIDA";
    system("pause");
    return;
}

void eliminarVenta(){
cout << "Listando ventas..." << endl;
}

void listarClientes(){
    system("cls");
    ArchivoClientes clientes("Clientes.dat");
    int opc;

    cout << " ---------------------------" << endl;
    cout << "           SUBMENU          " << endl;
    cout << " ---------------------------" << endl;
    cout << " 1. Listar clientes" << endl;
    cout << " 2. Listar cliente por id" << endl;
    cout << " Opcion: ";
    cin >> opc;

    if(opc == 1){
        clientes.listarClientes();
        return;
    }

    if(opc == 2){


    }

    cout << "OPCIÓN INVALIDA";
    system("pause");
    return;
}
void eliminarCliente(){
cout << "Listando ventas..." << endl;
}
