#include <iostream>
using namespace std;

#include "../menus/funciones-menus/funcionesMenuConfiguraciones.h"

#include "../archivos/Productos.h"
#include "../archivos/Ventas.h"
#include "../archivos/DetalleVentas.h"
#include "../archivos/Compras.h"
#include "../archivos/DetalleCompras.h"
#include "../archivos/Clientes.h"
#include "../archivos/Proveedores.h"
#include "../archivos/Empresas.h"
#include "../archivos/Categorias.h"

void backupProductos(){
    ArchivoProductos archivo("Productos.dat");
    Producto obj;

    FILE* p = fopen("./backups/Productos.bkp", "wb");

    if (p == NULL){
            return;
    }

    int cantidad = archivo.contarProductos();


    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerProducto(i);
        fwrite(&obj, sizeof obj, 1, p);
    }
    fclose(p);

    system("cls");
    cout << "# COPIA CREADA EXITOSAMENTE" << endl;
    system("pause");

}
void backupVentas(){
    ArchivoVentas archivo("Ventas.dat");
    Transaccion obj;

    FILE* p = fopen("./backups/Ventas.bkp", "wb");

    if (p == NULL){
            return;
    }

    int cantidad = archivo.contarVentas();


    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerVenta(i);
        fwrite(&obj, sizeof obj, 1, p);
    }
    fclose(p);

    system("cls");
    cout << "# COPIA CREADA EXITOSAMENTE" << endl;
    system("pause");


}
void backupDetalleVentas(){
    ArchivoDetallesVenta archivo("DetallesVentas.dat");
    DetalleTransaccion obj;

    FILE* p = fopen("./backups/DetallesVentas.bkp", "wb");

    if (p == NULL){
            return;
    }

    int cantidad = archivo.contarDetallesVentas();


    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerDetalleVenta(i);
        fwrite(&obj, sizeof obj, 1, p);
    }
    fclose(p);

    system("cls");
    cout << "# COPIA CREADA EXITOSAMENTE" << endl;
    system("pause");

}
void backupCompras(){
    ArchivoCompras archivo("Compras.dat");
    Transaccion obj;

    FILE* p = fopen("./backups/Compras.bkp", "wb");

    if (p == NULL){
            return;
    }

    int cantidad = archivo.contarCompras();


    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerCompra(i);
        fwrite(&obj, sizeof obj, 1, p);
    }
    fclose(p);

    system("cls");
    cout << "# COPIA CREADA EXITOSAMENTE" << endl;
    system("pause");
}
void backupDetalleCompras(){
    ArchivoDetallesCompra archivo("DetallesCompras.dat");
    DetalleTransaccion obj;

    FILE* p = fopen("./backups/DetallesCompras.bkp", "wb");

    if (p == NULL){
            return;
    }

    int cantidad = archivo.contarDetallesCompras();


    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerDetalleCompra(i);
        fwrite(&obj, sizeof obj, 1, p);
    }
    fclose(p);

    system("cls");
    cout << "# COPIA CREADA EXITOSAMENTE" << endl;
    system("pause");
}
void backupClientes(){
    ArchivoClientes archivo("Clientes.dat");
    Cliente obj;

    FILE* p = fopen("./backups/Clientes.bkp", "wb");

    if (p == NULL){
            return;
    }

    int cantidad = archivo.contarClientes();


    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerCliente(i);
        fwrite(&obj, sizeof obj, 1, p);
    }
    fclose(p);

    system("cls");
    cout << "# COPIA CREADA EXITOSAMENTE" << endl;
    system("pause");
}
void backupProveedores(){
    ArchivoProveedores archivo("Proveedores.dat");
    Proveedor obj;

    FILE* p = fopen("./backups/Proveedores.bkp", "wb");

    if (p == NULL){
            return;
    }

    int cantidad = archivo.contarProveedores();


    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerProveedor(i);
        fwrite(&obj, sizeof obj, 1, p);
    }
    fclose(p);

    system("cls");
    cout << "# COPIA CREADA EXITOSAMENTE" << endl;
    system("pause");
}
void backupEmpresas(){
    ArchivoEmpresas archivo("Empresas.dat");
    Empresa obj;

    FILE* p = fopen("./backups/Empresas.bkp", "wb");

    if (p == NULL){
            return;
    }

    int cantidad = archivo.contarEmpresas();


    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerEmpresa(i);
        fwrite(&obj, sizeof obj, 1, p);
    }
    fclose(p);

    system("cls");
    cout << "# COPIA CREADA EXITOSAMENTE" << endl;
    system("pause");

}
void backupCategorias(){
    ArchivoCategorias archivo("Categorias.dat");
    Categoria obj;

    FILE* p = fopen("./backups/Categorias.bkp", "wb");

    if (p == NULL){
            return;
    }

    int cantidad = archivo.contarCategorias();


    for (int i = 0; i < cantidad; i++) {
        obj = archivo.obtenerCategoria(i);
        fwrite(&obj, sizeof obj, 1, p);
    }
    fclose(p);

    system("cls");
    cout << "# COPIA CREADA EXITOSAMENTE" << endl;
    system("pause");

}

void restaurarBackupProductos(){
    ArchivoProductos archivo("Productos.dat");
    Producto obj;

    FILE* p = fopen("./backups/Productos.bkp", "rb");
    if (p == NULL) return;

    archivo.borrar();

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        archivo.guardarProducto(obj);
    }

    fclose(p);
    cout << " # COPIA DE SEGURIDAD RESTAURADA CON EXITO" << endl;
}
void restaurarBackupVentas(){
    ArchivoVentas archivo("Ventas.dat");
    Transaccion obj;

    FILE* p = fopen("./backups/Ventas.bkp", "rb");
    if (p == NULL) return;

    archivo.borrar();

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        archivo.guardarVenta(obj);
    }

    fclose(p);
    cout << " # COPIA DE SEGURIDAD RESTAURADA CON EXITO" << endl;
}
void restaurarBackupDetalleVentas(){
    ArchivoDetallesVenta archivo("DetallesVentas.dat");
    DetalleTransaccion obj;

    FILE* p = fopen("./backups/DetallesVentas.bkp", "rb");
    if (p == NULL) return;

    archivo.borrar();

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        archivo.guardarDetalleVenta(obj);
    }

    fclose(p);
    cout << " # COPIA DE SEGURIDAD RESTAURADA CON EXITO" << endl;
}
void restaurarBackupCompras(){
    ArchivoCompras archivo("Compras.dat");
    Transaccion obj;

    FILE* p = fopen("./backups/Compras.bkp", "rb");
    if (p == NULL) return;

    archivo.borrar();

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        archivo.guardarCompra(obj);
    }

    fclose(p);
    cout << " # COPIA DE SEGURIDAD RESTAURADA CON EXITO" << endl;

}
void restaurarBackupDetalleCompras(){
    ArchivoDetallesCompra archivo("DetallesCompras.dat");
    DetalleTransaccion obj;

    FILE* p = fopen("./backups/DetallesCompras.bkp", "rb");
    if (p == NULL) return;

    archivo.borrar();

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        archivo.guardarDetalleCompra(obj);
    }

    fclose(p);
    cout << " # COPIA DE SEGURIDAD RESTAURADA CON EXITO" << endl;

}
void restaurarBackupClientes(){
    ArchivoClientes archivo("Clientes.dat");
    Cliente obj;

    FILE* p = fopen("./backups/Clientes.bkp", "rb");
    if (p == NULL) return;

    archivo.borrar();

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        archivo.guardarCliente(obj);
    }

    fclose(p);
    cout << " # COPIA DE SEGURIDAD RESTAURADA CON EXITO" << endl;

}
void restaurarBackupProveedores(){
    ArchivoProveedores archivo("Proveedores.dat");
    Proveedor obj;

    FILE* p = fopen("./backups/Proveedores.bkp", "rb");
    if (p == NULL) return;

    archivo.borrar();

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        archivo.guardarProveedor(obj);
    }

    fclose(p);
    cout << " # COPIA DE SEGURIDAD RESTAURADA CON EXITO" << endl;

}
void restaurarBackupEmpresas(){
    ArchivoEmpresas archivo("Empresas.dat");
    Empresa obj;

    FILE* p = fopen("./backups/Empresas.bkp", "rb");
    if (p == NULL) return;

    archivo.borrar();

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        archivo.guardarEmpresa(obj);
    }

    fclose(p);
    cout << " # COPIA DE SEGURIDAD RESTAURADA CON EXITO" << endl;
}
void restaurarBackupCategorias(){
    ArchivoCategorias archivo("Categorias.dat");
    Categoria obj;

    FILE* p = fopen("./backups/Categorias.bkp", "rb");
    if (p == NULL) return;

    archivo.borrar();

    while (fread(&obj, sizeof obj, 1, p) == 1) {
        archivo.guardarCategoria(obj);
    }

    fclose(p);
    cout << " # COPIA DE SEGURIDAD RESTAURADA CON EXITO" << endl;
}
