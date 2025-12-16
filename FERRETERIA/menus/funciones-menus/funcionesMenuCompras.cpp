#include <iostream>
using namespace std;

#include "string.h"

#include "../../clases/Transaccion.h"
#include "../../clases/Almacen.h"
#include "../../clases/Fecha.h"
#include "../../clases/Hora.h"
#include "../../clases/Proveedor.h"
#include "../../archivos/Compras.h"
#include "../../archivos/DetalleCompras.h"
#include "../../archivos/Proveedores.h"
#include "../../archivos/Productos.h"

void nuevaCompra()
{
    ArchivoCompras compras("Comprass.dat");
    ArchivoDetallesCompra detallesCompras("DetallesCompras.dat");
    ArchivoProveedores proveedores("Proveedores.dat");
    ArchivoProductos productos("Productos.dat");
    Transaccion nuevaCompra;
    DetalleTransaccion detalleCompra;
    Hora hora;
    Fecha fecha;

    system("cls");
    cout << "------- NUEVA COMPRA -------" << endl;
    nuevaCompra.setIdTransaccion( compras.generarNuevoID() );

    /// VERIFICAR QUE QUIERE HACER EL USUARIO

    int opc = 0;
    cout << " 1. Listar productos" << endl;
    cout << " 2. Ingresar ID de producto" << endl;
    cout << " 3. Nuevo producto" << endl;
    cout << " 0. Volver al menu" << endl;
    cout << " Opcion:";
    cin >> opc;

    if(opc <= 0 || opc >3){
        return;
    }

    if(opc == 1){
        productos.listarProductos();
    }

    /// VERIFICAR SI ES UN PROVEEDOR NUEVO O NO

    if(opc == 3)
    {





    }

    /// DETALLES DE LA COMPRA

    system("cls");
    cout << " ------------------------------------" << endl;
    cout << "         Detalles de la compra       " << endl;
    cout << " ------------------------------------" << endl;
    system("pause");

    int opcDetalle=1;
    while(opcDetalle != 0)
    {

        cout << " ------------------------------------" << endl;
        cout << "         Detalle de compra " << opcDetalle << endl;
        detalleCompra.cargar( nuevaCompra.getIdTransaccion() );
        cout << " -------------------------------------" << endl;
        system("cls");


        detallesCompras.guardarDetalleCompra(detalleCompra);
        system("pause");

        char opcSeguir;
        cout << " Desea agregar otro detalle de venta? - Si 'S' o No 'N'" << endl;
        cout << " Opcion: ";
        cin  >> opcSeguir;

        if(opcSeguir == 'N' || opcSeguir == 'n')
        {
            opcDetalle = 0;
        }
        else
        {
            opcDetalle++;
        }

    }

    /// SE CARGA FECHA Y HORA DE EMISIÓN
    fecha.cargar();
    hora.cargar();

    /// SE TERMINA DE COMPLETAR LOS DATOS DE LA COMPRA
    nuevaCompra.setMontoTotal( detallesCompras.obtenerMontoTotal( nuevaCompra.getIdTransaccion() ) );
    nuevaCompra.setFechaEmision(fecha);
    nuevaCompra.setHoraEmision(hora);

    if(compras.guardarCompra(nuevaCompra))
    {
        cout << "ERROR NO SE PUDO GUARDAR LA COMPRA" << endl;
    }

    /// CUANDO SE TERMINA DE TIPEAR SE MUESTRA
    nuevaCompra.mostrar();
    detallesCompras.listarDetallesDeCompra( nuevaCompra.getIdTransaccion() );
}

void modificarCompra(){}
void listarCompra(){}
void eliminarCompra(){}
void listarProveedores(){}
void eliminarProveedor(){
    ArchivoProveedores proveedores("Proveedores.dat");
    ArchivoCompras compras("Ventas.dat");
    ArchivoDetallesCompra detalles("DetallesCompras.dat");

    system("cls");
    int id = 0;

    cout << " === ELIMINAR PROVEEDOR ===" << endl;
    cout << " ---------------------" << endl;
    cout << " 0. Volver al menu" << endl;
    cout << " Ingrese el ID del proveedor a borrar: ";
    cin >> id;

    if (id == 0) return;

    while (!proveedores.validarIdExiste(id)) {
        cout << " El ID ingresado no existe en la base de datos." << endl;
        cout << " Ingrese el ID nuevamente (0 para salir): ";
        cin >> id;

        if (id == 0) return;
    }

    system("cls");
    cout << " Buscando cliente con ID: " << id << "..." << endl;

    bool huboCambios = false;

    if( detalles.bajaDetallesComprasProveedor(id) ){
        cout << " Detalles de ventas historicos eliminados." << endl;
        huboCambios = true;
    }
    if( compras.bajaComprasProveedor(id)){
        cout << " Historial de ventas eliminado." << endl;
        huboCambios = true;
    }

    if( proveedores.bajaProveedor(id) ){
        cout << " CLIENTE ELIMINADO EXITOSAMENTE." << endl;
        huboCambios = true;
    }

    if (!huboCambios) {
        cout << " No se pudo eliminar el cliente o ya estaba dado de baja." << endl;
    }

    system("pause");
}
