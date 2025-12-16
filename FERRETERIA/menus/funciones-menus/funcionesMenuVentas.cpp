#include <iostream>
using namespace std;

#include "../../clases/Transaccion.h"
#include "../../clases/Almacen.h"
#include "../../clases/Fecha.h"
#include "../../clases/Hora.h"
#include "../../clases/Cliente.h"
#include "../../archivos/Ventas.h"
#include "../../archivos/DetalleVentas.h"
#include "../../archivos/Clientes.h"
#include "../../archivos/Productos.h"

void nuevaVenta(){
    ArchivoProductos productos("Productos.dat");
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


            while(opcId <= 0){

                if(opcId < 0){
                     cout << "No puede ingresar ese ID.";
                    system("pause");
                }

                system("cls");

                if(opcId == 0){
                    system("cls");
                    clientes.listarClientes();
                }

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
    cout << endl;
    cout << " Productos disponibles actualmente:" << endl;
    productos.listarProductos();
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
    cout << " 0. Volver al menu" << endl;
    cout << " 1. Ingrese el ID de la venta" << endl;;
    cout << " 2. Listar ventas"<< endl;
    cout << " Opcion: ";
    cin >> opc;

    switch(opc){
        case 0: return;
        case 1: {
                system("cls");
                int id = 0;
                cout << " Ingrese el id: ";
                cin >> id;

                while( !ventas.validarIdExiste(id) ){
                    system("cls");
                    cout << " Ingrese el id: ";
                    cin >> id;
                }

                Transaccion venta;
                ArchivoDetallesVenta archivo;

                int pos = ventas.obtenerUbicacionVenta(id);
                venta = ventas.obtenerVenta(pos);


                venta.mostrar();
                archivo.listarDetallesDeVenta(id);
                system("pause");

                int opcEdit = 0;
                cout << " ----------------------" << endl;
                cout << "         VENTA         " << endl;
                cout << " ----------------------" << endl;
                cout << " 1. ID de Cliente" << endl;
                cout << " 2. Hora de emision" << endl;
                cout << " 3. Fecha de emision" << endl;
                cout << " 4. Tipo de factura" << endl;
                cout << " ----------------------" << endl;
                cout << "     DETALLE VENTA     " << endl;
                cout << " ----------------------" << endl;
                cout << " 5. ID de Producto" << endl;
                cout << " 6. Cantidad de Producto" << endl;
                cout << endl;
                cout << " # Opcion: ";
                cin >> opcEdit;

                switch(opcEdit){
                    case 1: break;
                    case 2: break;
                    case 3: break;
                    case 4: break;
                    case 5: break;
                    case 6: break;
                    default: break;
                }


            }
            break;
        case 2: {
            ventas.listarVentas();
            system("pause");
            system("cls");

            }
            break;
        default: return;
    }



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
    cout << " 3. Volver al menu" << endl;
    cout << " Opcion: ";
    cin >> opc;

    if(opc == 3){
        return;
    }

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
    ArchivoVentas ventas("Ventas.dat");
    ArchivoDetallesVenta detalles("DetallesVentas.dat");

    system("cls");
    int id;
    cout << "----------------------" << endl;
    cout << " 0. Volver al menú";
    cout << " Ingrese el ID: ";
    cin >> id;

    if(id == 0){
        return;
    }

    if(id < 0){
        while(!ventas.validarIdExiste(id) || id < 0){

        system("cls");

        cout << " Ingrese un ID real: ";
        cin >> id;
    }

    system("cls");

    if( detalles.bajaDetallesVentasCliente(id) ){
        cout << " # DETALLES DE VENTA ELIMINADOS " << endl;

        if( ventas.bajaVentasCliente(id)){
            cout << " # VENTAS ELIMINADAS";

            return;
        }

       cout << "NO SE PUDO ELIMINAR LAS VENTAS, PERO SI EL DETALLE";
    }

    cout << "NO SE PUDO ELIMINAR NI LA VENTA NI SUS DETALLES.";

    system("pause");
    return;
    }
}

void listarClientes(){
    system("cls");
    ArchivoClientes clientes("Clientes.dat");
    int opc;

    cout << " ---------------------------" << endl;
    cout << "           SUBMENU          " << endl;
    cout << " ---------------------------" << endl;
    cout << " 0. Volver al menu" << endl;
    cout << " 1. Listar clientes" << endl;
    cout << " 2. Listar cliente por DNI" << endl;
    cout << " 3. Listar clientes por NOMBRE" << endl;
    cout << " 4. Listar clientes por APELLIDO" << endl;
    cout << " Opcion: ";
    cin >> opc;

    if(opc == 0){
        return;
    }

    if(opc < 0 || opc > 6){
        system("cls");
        cout << "OPCION INCORRECTA";
        system("pause");
        return;
    }

    if(opc == 1){
        system("cls");
        clientes.listarClientes();
        return;
    }

    if(opc == 2){
        system("cls");
        int dni;
        cout << "Ingrese el DNI: ";
        cin >> dni;

        while(!clientes.validarDniExiste(dni)){
            system("cls");
            cout << "Ese DNI es incorrecto o no existe.";
            system("pause");
            cout << "Ingrese otro: ";
            cin >> dni;
        }

        int pos = clientes.obtenerUbicacionCliente(dni);
        Cliente busqueda = clientes.obtenerCliente(pos);
        busqueda.mostrar();
        return;
    }

    if(opc == 3){
        system("cls");

        cin.ignore();

        char nombre[25];
        cout << " Ingrese el nombre del cliente: ";
        cin.getline(nombre,25);

        system("cls");
        cout << " #BUSQUEDAS CON NOMBRE: " << nombre << endl;

        clientes.listarClientesNombre(nombre);
        system("pause");
    }

    if(opc == 4){
        system("cls");

        cin.ignore();

        char apellido[25];
        cout << " Ingrese el apellido del cliente: ";
        cin.getline(apellido,25);


        system("cls");
        cout << " #BUSQUEDAS CON APELLIDO: " << apellido << endl;

        clientes.listarClientesApellido(apellido);
        system("pause");

    }

    cout << "OPCIÓN INVALIDA";
    system("pause");
    return;
}

void eliminarCliente(){
    ArchivoClientes clientes("Clientes.dat");
    ArchivoVentas ventas("Ventas.dat");
    ArchivoDetallesVenta detalles("DetallesVentas.dat");

    system("cls");
    int dni = 0;

    cout << " === ELIMINAR CLIENTE ===" << endl;
    cout << " ---------------------" << endl;
    cout << " 0. Volver al menu" << endl;
    cout << " Ingrese el DNI del cliente a borrar: ";
    cin >> dni;

    if (dni == 0) return;

    while (!clientes.validarDniExiste(dni)) {
        cout << " [!] El DNI ingresado no existe en la base de datos." << endl;
        cout << " Ingrese el DNI nuevamente (0 para salir): ";
        cin >> dni;

        if (dni == 0) return;
    }

    system("cls");
    cout << " Buscando cliente con DNI: " << dni << "..." << endl;

    int id = clientes.obtenerIdCliente(dni);


    bool huboCambios = false;

    if( detalles.bajaDetallesVentasCliente(id) ){
        cout << " Detalles de ventas historicos eliminados." << endl;
        huboCambios = true;
    }

    if( ventas.bajaVentasCliente(id)){
        cout << " Historial de ventas eliminado." << endl;
        huboCambios = true;
    }

    if( clientes.bajaCliente(dni) ){
        cout << " CLIENTE ELIMINADO EXITOSAMENTE." << endl;
        huboCambios = true;
    }

    if (!huboCambios) {
        cout << " No se pudo eliminar el cliente o ya estaba dado de baja." << endl;
    }

    system("pause");
}
