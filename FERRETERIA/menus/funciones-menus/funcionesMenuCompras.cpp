#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "funcionesMenuCompras.h"
#include "../../clases/Transaccion.h"
#include "../../clases/DetalleTransaccion.h"
#include "../../clases/Almacen.h"
#include "../../clases/Fecha.h"
#include "../../clases/Hora.h"
#include "../../archivos/Compras.h"
#include "../../archivos/DetalleCompras.h"
#include "../../archivos/Proveedores.h"
#include "../../archivos/Productos.h"

using namespace std;


void nuevaCompra() {
    system("cls");
    ArchivoCompras compras("Compras.dat");
    ArchivoDetallesCompra detalles("DetallesCompras.dat");
    ArchivoProveedores proveedores("Proveedores.dat");
    ArchivoProductos productos("Productos.dat");
    Almacen almacen;

    cout << "------ NUEVA COMPRA ------" << endl;

    int idProveedor = -1;
    int opcionProv;

    cout << " Seleccione una opcion: " << endl;
    cout << " 1. Seleccionar proveedor existente" << endl;
    cout << " 2. Cargar nuevo proveedor" << endl;
    cout << " 0. Cancelar" << endl;
    cout << " Opcion: ";
    cin >> opcionProv;

    switch (opcionProv) {
        case 1: {
            system("cls");
            proveedores.listarProveedores();
            cout << " -----------------------------" << endl;
            cout << " Ingrese ID del Proveedor: ";
            cin >> idProveedor;

            while (!proveedores.validarIdExiste(idProveedor)) {
                cout << " ! El proveedor no existe. Intente nuevamente (0 para salir): ";
                cin >> idProveedor;
                if (idProveedor == 0) return;
            }
            break;
        }
        case 2: {
            system("cls");
            cout << " --- CARGAR NUEVO PROVEEDOR ---" << endl;
            Proveedor nuevoProv;

            int nuevoId = proveedores.generarNuevoID();
            nuevoProv.setId(nuevoId);
            nuevoProv.cargar();

            if (proveedores.guardarProveedor(nuevoProv)) {
                idProveedor = nuevoId;
                cout << " # Proveedor registrado con exito. ID: " << idProveedor << endl;
                system("pause");
            } else {
                cout << " Error al guardar el proveedor." << endl;
                return;
            }
            break;
        }
        default:
            return;
    }

    system("cls");
    cout << " --- DATOS DE LA FACTURA ---" << endl;

    Transaccion nuevaCompra;
    int idCompra = compras.generarNuevoID();

    nuevaCompra.setIdTransaccion(idCompra);
    nuevaCompra.setIdPersona(idProveedor);

    Fecha fechaHoy;
    fechaHoy.cargar();

    Hora horaActual;
    horaActual.cargar();

    nuevaCompra.setFechaEmision(fechaHoy);
    nuevaCompra.setHoraEmision(horaActual);

    nuevaCompra.setEstado(true);

    char tipoFactura;
    cout << " Tipo de Factura (A/B): ";
    cin >> tipoFactura;
    nuevaCompra.setTipoFactura(toupper(tipoFactura));


    bool continuar = true;
    while (continuar) {
        system("cls");
        cout << " --- AGREGANDO PRODUCTOS A LA COMPRA #" << idCompra << " ---" << endl;
        cout << " Proveedor ID: " << idProveedor << endl;
        cout << " -----------------------------------------" << endl;

        productos.listarProductos();

        int idProd;
        cout << "\n Ingrese ID Producto a comprar: ";
        cin >> idProd;

        if (productos.validarIdExiste(idProd)) {
            int cantidad;
            cout << " Cantidad comprada: ";
            cin >> cantidad;

            if (cantidad > 0) {
                DetalleTransaccion detalle;
                detalle.setIdTransaccion(idCompra);
                detalle.setIdProducto(idProd);
                detalle.setCantidad(cantidad);


                detalles.guardarDetalleCompra(detalle);
                almacen.reponerStock(idProd, cantidad);

                cout << " # Producto agregado y stock actualizado." << endl;
            } else {
                cout << " ! Cantidad invalida." << endl;
            }
        } else {
            cout << " ! Producto no encontrado." << endl;
        }

        cout << "\n Desea agregar otro producto? (1: Si / 0: No): ";
        cin >> continuar;
    }

    if (compras.guardarCompra(nuevaCompra)) {
        system("cls");
        cout << " -----------------------------------------" << endl;
        cout << "   COMPRA REGISTRADA CON EXITO " << endl;
        cout << "   ID OPERACION: " << idCompra << endl;
        cout << " -----------------------------------------" << endl;
    } else {
        cout << " ! Error al guardar la cabecera de la compra." << endl;
    }

    system("pause");
}

void listarCompras() {
    system("cls");
    ArchivoCompras compras("Compras.dat");
    cout << "------ LISTADO DE COMPRAS ------" << endl;
    compras.listarCompras();
    system("pause");
}

void listarCompra() {
    system("cls");
    ArchivoCompras compras("Compras.dat");
    ArchivoDetallesCompra detalles("DetallesCompras.dat");

    int id;
    cout << " Ingrese ID de Compra a buscar: ";
    cin >> id;

    if (compras.validarIdExiste(id)) {
        int pos = compras.obtenerUbicacionCompra(id);
        Transaccion compra = compras.obtenerCompra(pos);

        compra.mostrar();
        cout << " --- DETALLES ---" << endl;
        detalles.listarDetallesDeCompra(id);
    } else {
        cout << " Compra no encontrada." << endl;
    }
    system("pause");
}

void editarCompra() {

    system("cls");
    ArchivoCompras compras("Compras.dat");
    ArchivoDetallesCompra detalles("DetallesCompras.dat");
    Almacen almacen;

    int id;
    cout << " ID de Compra a modificar: ";
    cin >> id;

    if (!compras.validarIdExiste(id)) {
        cout << " ID no encontrado." << endl;
        system("pause");
        return;
    }

    cout << " [Para simplificar, implementacion de modificacion de cantidad]" << endl;

    detalles.listarDetallesDeCompra(id);
    int idDetalle;

    cout << " Ingrese ID de detalle (producto) a ajustar cantidad: ";
    cin >> idDetalle;

    int pos = detalles.obtenerUbicacionDetalleCompra(idDetalle);
    if (pos == -1) return;

    DetalleTransaccion detalle = detalles.obtenerDetalleCompra(pos);

    int nuevaCantidad;
    cout << " Cantidad actual: " << detalle.getCantidad() << endl;
    cout << " Nueva cantidad comprada: ";
    cin >> nuevaCantidad;

    int antiguaCantidad = detalle.getCantidad();
    int diferencia = nuevaCantidad - antiguaCantidad;

    if (diferencia > 0) {
        almacen.reponerStock(detalle.getIdProducto(), diferencia);
    } else if (diferencia < 0) {
        almacen.descontarStock(detalle.getIdProducto(), diferencia * -1);
    }

    detalle.setCantidad(nuevaCantidad);
    detalles.editarDetalleCompra(detalle, pos);

    cout << " Cantidad modificada y stock ajustado." << endl;
    system("pause");
}

void eliminarCompra() {
    ArchivoCompras compras("Compras.dat");
    ArchivoDetallesCompra detalles("DetallesCompras.dat");
    Almacen almacen;

    system("cls");
    int id;
    cout << "------ ANULAR COMPRA ------" << endl;
    cout << " Ingrese ID Compra: ";
    cin >> id;

    if (!compras.validarIdExiste(id)) {
        cout << " Compra no encontrada." << endl;
        system("pause");
        return;
    }

    cout << " ! ATENCION: Al anular la compra, asegurese de ajustar el stock fisico." << endl;

    bool detallesBorrados = detalles.bajaDetallesComprasProveedor(id);
    bool cabeceraBorrada = compras.bajaComprasProveedor(id);

    if (cabeceraBorrada) {
        cout << " Compra anulada correctamente." << endl;
    } else {
        cout << " Error al anular compra." << endl;
    }
    system("pause");
}

void listarProveedores() {
    system("cls");
    cout << "------ LISTA DE PROVEEDORES ------" << endl;

    ArchivoProveedores proveedores("Proveedores.dat");
    proveedores.listarProveedores();

    cout << endl;
    system("pause");
}

void eliminarProveedor() {
    system("cls");
    cout << "------ ELIMINAR PROVEEDOR ------" << endl;

    ArchivoProveedores proveedores("Proveedores.dat");
    ArchivoCompras compras("Compras.dat");

    int id;
    cout << " Ingrese el ID del proveedor a eliminar: ";
    cin >> id;

    if (id <= 0) return;

    if (!proveedores.validarIdExiste(id)) {
        cout << " ! El proveedor no existe." << endl;
        system("pause");
        return;
    }

    int cantidadCompras = compras.contarCompras();
    bool tieneHistorial = false;

    for (int i = 0; i < cantidadCompras; i++) {
        Transaccion compra = compras.obtenerCompra(i);

        if (compra.getIdPersona() == id && compra.getEstado() == true) {
            tieneHistorial = true;
            break;
        }
    }

    if (tieneHistorial) {
        cout << endl;
        cout << " ! ERROR CRITICO: No se puede eliminar este proveedor." << endl;
        cout << "   Motivo: Existen facturas de compra registradas a su nombre." << endl;
        cout << "   (Debe eliminar primero las compras asociadas si realmente desea borrarlo)." << endl;
        system("pause");
        return;
    }

    cout << endl;
    cout << " El proveedor no tiene compras asociadas." << endl;
    cout << " Esta seguro que desea eliminarlo? (1: Si / 0: No): ";
    int confirmacion;
    cin >> confirmacion;

    if (confirmacion == 1) {
        if (proveedores.bajaProveedor(id)) {
            cout << " # Proveedor eliminado correctamente." << endl;
        } else {
            cout << " ! Error al intentar borrar el registro." << endl;
        }
    } else {
        cout << " Operacion cancelada." << endl;
    }

    system("pause");
}
