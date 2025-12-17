#include <iostream>
#include <fstream>
#include <iomanip>
#include <direct.h>
#include <cstdio>

#include "funcionesMenuConfiguraciones.h"

#include "../../archivos/Productos.h"
#include "../../archivos/Clientes.h"
#include "../../archivos/Proveedores.h"
#include "../../archivos/Ventas.h"
#include "../../archivos/DetalleVentas.h"
#include "../../archivos/Compras.h"
#include "../../archivos/DetalleCompras.h"
#include "../../archivos/Empresas.h"
#include "../../archivos/Categorias.h"
#include "../../clases/Producto.h"
#include "../../clases/Cliente.h"
#include "../../clases/Proveedor.h"
#include "../../clases/Empresa.h"
#include "../../clases/Categoria.h"
#include "../../clases/Transaccion.h"
#include "../../clases/DetalleTransaccion.h"

using namespace std;

void asegurarCarpetaExportacion() {
    _mkdir("./exportados");
}

void exportarProductosCSV() {
    asegurarCarpetaExportacion();
    ArchivoProductos archivo("Productos.dat");
    ofstream salida("./exportados/Productos.csv");

    if (!salida.is_open()) {
        cout << "Error al crear Productos.csv" << endl;
        return;
    }

    salida << "ID,Nombre,Marca,Categoria,Precio,Stock,ID_Proveedor,Estado\n";

    int cantidad = archivo.contarProductos();
    Producto obj;

    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerProducto(i);

        salida << obj.getId() << ","
               << obj.getNombre() << ","
               << obj.getMarca() << ","
               << obj.getCategoria() << ","
               << fixed << setprecision(2) << obj.getPrecio() << ","
               << obj.getStock() << ","
               << obj.getIdProveedor() << ","
               << (obj.getEstado() ? "Activo" : "Inactivo") << "\n";
    }

    salida.close();
    cout << " [OK] Productos exportados." << endl;
}

void exportarClientesCSV() {
    asegurarCarpetaExportacion();
    ArchivoClientes archivo("Clientes.dat");
    ofstream salida("./exportados/Clientes.csv");

    if (!salida.is_open()) return;

    salida << "ID,DNI,Nombre,Apellido,Email,Telefono,Estado\n";

    int cantidad = archivo.contarClientes();
    Cliente obj;

    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerCliente(i);

        // Asumiendo herencia de Persona
        salida << obj.getId() << ","
               << obj.getDni() << ","
               << obj.getNombre() << ","
               << obj.getApellido() << ","
               << obj.getEmail() << ","
               << obj.getTelefono() << ","
               << (obj.getEstado() ? "Activo" : "Baja") << "\n";
    }

    salida.close();
    cout << " [OK] Clientes exportados." << endl;
}

void exportarProveedoresCSV() {
    asegurarCarpetaExportacion();
    ArchivoProveedores archivo("Proveedores.dat");
    ofstream salida("./exportados/Proveedores.csv");

    if (!salida.is_open()) return;

    salida << "ID,Nombre_Empresa,Razon_Social,Telefono,Email,ID_Empresa,Estado\n";

    int cantidad = archivo.contarProveedores();
    Proveedor obj;

    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerProveedor(i);

        salida << obj.getId() << ","
               << obj.getNombreEmpresa() << ","
               << obj.getRazonSocial() << ","
               << obj.getTelefono() << ","
               << obj.getEmail() << ","
               << obj.getIdEmpresa() << ","
               << (obj.getEstado() ? "Activo" : "Baja") << "\n";
    }

    salida.close();
    cout << " [OK] Proveedores exportados." << endl;
}

void exportarVentasCSV() {
    asegurarCarpetaExportacion();
    ArchivoVentas archivo("Ventas.dat");
    ofstream salida("./exportados/Ventas.csv");

    if (!salida.is_open()) return;

    salida << "ID_Venta,ID_Cliente,Fecha,Hora,Tipo,Monto_Total,Estado\n";

    int cantidad = archivo.contarVentas();
    Transaccion obj;

    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerVenta(i);

        Fecha f = obj.getFechaTransaccion();
        Hora h = obj.getHoraTransaccion();

        salida << obj.getIdTransaccion() << ","
               << obj.getIdPersona() << "," // En ventas es el Cliente
               << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << ","
               << h.getHora() << ":" << h.getMinutos() << ","
               << obj.getTipoFactura() << ","
               << fixed << setprecision(2) << obj.getMontoTotal() << ","
               << (obj.getEstado() ? "Confirmada" : "Anulada") << "\n";
    }

    salida.close();
    cout << " [OK] Ventas exportadas." << endl;
}

void exportarDetalleVentasCSV() {
    asegurarCarpetaExportacion();
    ArchivoDetallesVenta archivo("DetallesVentas.dat");
    ofstream salida("./exportados/DetallesVentas.csv");

    if (!salida.is_open()) return;

    salida << "ID_Detalle,ID_Venta,ID_Producto,Cantidad,Precio_Unitario,Estado\n";

    int cantidad = archivo.contarDetallesVentas();
    DetalleTransaccion obj;

    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerDetalleVenta(i);

        salida << obj.getId() << ","
               << obj.getIdTransaccion() << ","
               << obj.getIdProducto() << ","
               << obj.getCantidad() << ","
               << fixed << setprecision(2) << obj.getPrecioUnitario() << ","
               << (obj.getEstado() ? "Activo" : "Baja") << "\n";
    }

    salida.close();
    cout << " [OK] Detalle de Ventas exportado." << endl;
}

void exportarComprasCSV() {
    asegurarCarpetaExportacion();
    ArchivoCompras archivo("Compras.dat");
    ofstream salida("./exportados/Compras.csv");

    if (!salida.is_open()) return;

    salida << "ID_Compra,ID_Proveedor,Fecha,Hora,Tipo,Monto_Total,Estado\n";

    int cantidad = archivo.contarCompras(); // Asegúrate de tener este método en ArchivoCompras
    Transaccion obj;

    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerCompra(i); // Asegúrate de tener este método

        Fecha f = obj.getFechaTransaccion();
        Hora h = obj.getHoraTransaccion();

        salida << obj.getIdTransaccion() << ","
               << obj.getIdPersona() << "," // En compras es el Proveedor
               << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << ","
               << h.getHora() << ":" << h.getMinutos() << ","
               << obj.getTipoFactura() << ","
               << fixed << setprecision(2) << obj.getMontoTotal() << ","
               << (obj.getEstado() ? "Confirmada" : "Anulada") << "\n";
    }

    salida.close();
    cout << " [OK] Compras exportadas." << endl;
}

void exportarDetalleComprasCSV() {
    asegurarCarpetaExportacion();
    ArchivoDetallesCompra archivo("DetallesCompras.dat");
    ofstream salida("./exportados/DetallesCompras.csv");

    if (!salida.is_open()) return;

    salida << "ID_Detalle,ID_Compra,ID_Producto,Cantidad,Precio_Unitario,Estado\n";

    int cantidad = archivo.contarDetallesCompras(); // Asegúrate de tener este método
    DetalleTransaccion obj;

    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerDetalleCompra(i);

        salida << obj.getId() << ","
               << obj.getIdTransaccion() << ","
               << obj.getIdProducto() << ","
               << obj.getCantidad() << ","
               << fixed << setprecision(2) << obj.getPrecioUnitario() << ","
               << (obj.getEstado() ? "Activo" : "Baja") << "\n";
    }

    salida.close();
    cout << " [OK] Detalle de Compras exportado." << endl;
}

void exportarEmpresasCSV() {
    asegurarCarpetaExportacion();
    ArchivoEmpresas archivo("Empresas.dat");
    ofstream salida("./exportados/Empresas.csv");

    if (!salida.is_open()) return;

    salida << "ID,Nombre,Estado\n";

    int cantidad = archivo.contarEmpresas();
    Empresa obj;

    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerEmpresa(i);

        salida << obj.getId() << ","
               << obj.getNombre() << ","
               << (obj.getEstado() ? "Activa" : "Inactiva") << "\n";
    }

    salida.close();
    cout << " [OK] Empresas exportadas." << endl;
}

void exportarCategoriasCSV() {
    asegurarCarpetaExportacion();
    ArchivoCategorias archivo("Categorias.dat");
    ofstream salida("./exportados/Categorias.csv");

    if (!salida.is_open()) return;

    salida << "ID,Nombre,Estado\n";

    int cantidad = archivo.contarCategorias();
    Categoria obj;

    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerCategoria(i);

        salida << obj.getId() << ","
               << obj.getNombre() << ","
               << (obj.getEstado() ? "Activa" : "Inactiva") << "\n";
    }

    salida.close();
    cout << " [OK] Categorias exportadas." << endl;
}

void exportarCSVGeneral() {
    system("cls");
    cout << "============================================" << endl;
    cout << "      EXPORTANDO BASE DE DATOS A CSV        " << endl;
    cout << "============================================" << endl << endl;

    exportarProductosCSV();
    exportarClientesCSV();
    exportarProveedoresCSV();
    exportarVentasCSV();
    exportarDetalleVentasCSV();
    exportarComprasCSV();
    exportarDetalleComprasCSV();
    exportarEmpresasCSV();
    exportarCategoriasCSV();

    cout << endl;
    cout << "============================================" << endl;
    cout << " PROCESO FINALIZADO. REVISE LA CARPETA 'exportados'" << endl;
    cout << "============================================" << endl;
    system("pause");
}
