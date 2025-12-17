#include <iostream>
using namespace std;

#include <cstdio>
#include <direct.h>

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
#include "../clases/Fecha.h"

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
void backupGeneral(){
    Fecha actual;
    system("cls");
    cout << " - Bienvenido, ingrese la fecha de hoy para generar el backup." << endl;
    actual.cargar();

    char nombreCarpeta[50];
    char rutaProductos[100];
    char rutaVentas[100];
    char rutaDetallesVentas[100];
    char rutaCompras[100];
    char rutaDetallesCompras[100];
    char rutaClientes[100];
    char rutaProveedores[100];
    char rutaEmpresas[100];
    char rutaCategorias[100];

    sprintf(nombreCarpeta, "./backups/backup-%d%d%d", actual.getDia(), actual.getMes(), actual.getAnio());

    _mkdir("./backups");
    _mkdir(nombreCarpeta);

    sprintf(rutaProductos, "%s/Productos.bkp", nombreCarpeta);
    sprintf(rutaVentas, "%s/Ventas.bkp", nombreCarpeta);
    sprintf(rutaDetallesVentas, "%s/DetallesVentas.bkp", nombreCarpeta);
    sprintf(rutaCompras, "%s/Compras.bkp", nombreCarpeta);
    sprintf(rutaDetallesCompras, "%s/DetallesCompras.bkp", nombreCarpeta);
    sprintf(rutaClientes, "%s/Clientes.bkp", nombreCarpeta);
    sprintf(rutaProveedores, "%s/Proveedores.bkp", nombreCarpeta);
    sprintf(rutaEmpresas, "%s/Empresas.bkp", nombreCarpeta);
    sprintf(rutaCategorias, "%s/Categorias.bkp", nombreCarpeta);

    system("cls");
    cout << " # GENERANDO BACKUP EN: " << nombreCarpeta << endl;

    /// PRODUCTOS
    ArchivoProductos productos("Productos.dat");
    Producto prod;
    FILE* p = fopen(rutaProductos, "wb");
    if (p == NULL){
        cout << "Error al crear archivo de Productos." << endl;
        return;
    }
    int cantProd = productos.contarProductos();
    for (int i = 0; i < cantProd; i++) {
        prod = productos.obtenerProducto(i);
        fwrite(&prod, sizeof prod, 1, p);
    }
    fclose(p);

    /// VENTAS
    ArchivoVentas ventas("Ventas.dat");
    Transaccion venta;
    FILE* v = fopen(rutaVentas, "wb");
    if (v != NULL){
        int cantVent = ventas.contarVentas();
        for (int i = 0; i < cantVent; i++) {
            venta = ventas.obtenerVenta(i);
            fwrite(&venta, sizeof venta, 1, v);
        }
        fclose(v);
    }

    /// DETALLE VENTAS
    ArchivoDetallesVenta detVentas("DetallesVentas.dat");
    DetalleTransaccion detV;
    FILE* dV = fopen(rutaDetallesVentas, "wb");
    if (dV != NULL){
        int cantDv = detVentas.contarDetallesVentas();
        for (int i = 0; i < cantDv; i++) {
            detV = detVentas.obtenerDetalleVenta(i);
            fwrite(&detV, sizeof detV, 1, dV);
        }
        fclose(dV);
    }

    /// COMPRAS
    ArchivoCompras compras("Compras.dat");
    Transaccion com;
    FILE* c = fopen(rutaCompras, "wb");
    if (c != NULL){
        int cantCom = compras.contarCompras();
        for (int i = 0; i < cantCom; i++) {
            com = compras.obtenerCompra(i);
            fwrite(&com, sizeof com, 1, c);
        }
        fclose(c);
    }

    /// DETALLE COMPRAS
    ArchivoDetallesCompra detCompras("DetallesCompras.dat");
    DetalleTransaccion detC;
    FILE* dC = fopen(rutaDetallesCompras, "wb");
    if (dC != NULL){
        int cantDc = detCompras.contarDetallesCompras();
        for (int i = 0; i < cantDc; i++) {
            detC = detCompras.obtenerDetalleCompra(i);
            fwrite(&detC, sizeof detC, 1, dC);
        }
        fclose(dC);
    }

    /// CLIENTES
    ArchivoClientes clientes("Clientes.dat");
    Cliente cliente;
    FILE* cC = fopen(rutaClientes, "wb");
    if (cC != NULL){
        int cantC = clientes.contarClientes();
        for (int i = 0; i < cantC; i++) {
            cliente = clientes.obtenerCliente(i);
            fwrite(&cliente, sizeof cliente, 1, cC);
        }
        fclose(cC);
    }

    /// PROVEEDORES
    ArchivoProveedores proveedores("Proveedores.dat");
    Proveedor prov;
    FILE* pP = fopen(rutaProveedores, "wb");
    if (pP != NULL){
        int cantP = proveedores.contarProveedores();
        for (int i = 0; i < cantP; i++) {
            prov = proveedores.obtenerProveedor(i);
            fwrite(&prov, sizeof prov, 1, pP);
        }
        fclose(pP);
    }

    /// EMPRESAS
    ArchivoEmpresas empresas("Empresas.dat");
    Empresa empr;
    FILE* e = fopen(rutaEmpresas, "wb");
    if (e != NULL){
        int cantE = empresas.contarEmpresas();
        for (int i = 0; i < cantE; i++) {
            empr = empresas.obtenerEmpresa(i);
            fwrite(&empr, sizeof empr, 1, e);
        }
        fclose(e);
    }

    /// CATEGORIAS
    ArchivoCategorias categorias("Categorias.dat");
    Categoria categ;
    FILE* cat = fopen(rutaCategorias, "wb");
    if (cat != NULL){
        int cantCat = categorias.contarCategorias();
        for (int i = 0; i < cantCat; i++) {
            categ = categorias.obtenerCategoria(i);
            fwrite(&categ, sizeof categ, 1, cat);
        }
        fclose(cat);
    }

    cout << endl << "# BACKUP GENERAL COMPLETADO EN LA CARPETA: " << nombreCarpeta << endl;
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
    system("pause");
}
void restaurarBackupGeneral(){
    system("cls");
    cout << "=== RESTAURAR COPIA DE SEGURIDAD COMPLETA ===" << endl << endl;

    // 1. Listar las carpetas disponibles usando el comando del sistema
    // /AD: Solo directorios (Attribute Directory)
    // /B: Formato simple (Bare format, solo nombres)
    cout << "Copias disponibles en su sistema:" << endl;
    cout << "---------------------------------" << endl;
    system("dir /AD /B \".\\backups\"");
    cout << "---------------------------------" << endl << endl;

    // 2. Pedir al usuario que seleccione
    cout << "Ingrese el nombre EXACTO de la carpeta que desea restaurar" << endl;
    cout << "(Ejemplo: backup-16122025): ";

    char nombreCarpeta[50];
    cin >> nombreCarpeta;

    // 3. Confirmación de seguridad
    cout << endl << "ADVERTENCIA: Esta accion BORRARA TODOS LOS DATOS ACTUALES" << endl;
    cout << "y los reemplazara por los de la copia de seguridad." << endl;
    cout << "Esta seguro de continuar? (S/N): ";
    char confirma;
    cin >> confirma;

    if (confirma != 's' && confirma != 'S') {
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }

    cout << endl << "Iniciando restauracion..." << endl;

    char rutaArchivo[150]; // Buffer para construir las rutas de lectura

    /// --- 1. PRODUCTOS ---
    sprintf(rutaArchivo, "./backups/%s/Productos.bkp", nombreCarpeta);
    FILE* pProd = fopen(rutaArchivo, "rb");
    if (pProd != NULL) {
        ArchivoProductos archivo("Productos.dat");
        archivo.borrar(); // Borramos el actual
        Producto obj;
        while (fread(&obj, sizeof(obj), 1, pProd) == 1) {
            archivo.guardarProducto(obj);
        }
        fclose(pProd);
        cout << "[OK] Productos restaurados." << endl;
    } else {
        cout << "[X] No se encontro respaldo de Productos." << endl;
    }

    /// --- 2. VENTAS ---
    sprintf(rutaArchivo, "./backups/%s/Ventas.bkp", nombreCarpeta);
    FILE* pVent = fopen(rutaArchivo, "rb");
    if (pVent != NULL) {
        ArchivoVentas archivo("Ventas.dat");
        archivo.borrar();
        Transaccion obj;
        while (fread(&obj, sizeof(obj), 1, pVent) == 1) {
            archivo.guardarVenta(obj);
        }
        fclose(pVent);
        cout << "[OK] Ventas restauradas." << endl;
    } else {
        cout << "[X] No se encontro respaldo de Ventas." << endl;
    }

    /// --- 3. DETALLE VENTAS ---
    sprintf(rutaArchivo, "./backups/%s/DetallesVentas.bkp", nombreCarpeta);
    FILE* pDetV = fopen(rutaArchivo, "rb");
    if (pDetV != NULL) {
        ArchivoDetallesVenta archivo("DetallesVentas.dat");
        archivo.borrar();
        DetalleTransaccion obj;
        while (fread(&obj, sizeof(obj), 1, pDetV) == 1) {
            archivo.guardarDetalleVenta(obj);
        }
        fclose(pDetV);
        cout << "[OK] Detalles de Ventas restaurados." << endl;
    } else {
        cout << "[X] No se encontro respaldo de Detalles Ventas." << endl;
    }

    /// --- 4. COMPRAS ---
    sprintf(rutaArchivo, "./backups/%s/Compras.bkp", nombreCarpeta);
    FILE* pComp = fopen(rutaArchivo, "rb");
    if (pComp != NULL) {
        ArchivoCompras archivo("Compras.dat");
        archivo.borrar();
        Transaccion obj;
        while (fread(&obj, sizeof(obj), 1, pComp) == 1) {
            archivo.guardarCompra(obj);
        }
        fclose(pComp);
        cout << "[OK] Compras restauradas." << endl;
    } else {
        cout << "[X] No se encontro respaldo de Compras." << endl;
    }

    /// --- 5. DETALLE COMPRAS ---
    sprintf(rutaArchivo, "./backups/%s/DetallesCompras.bkp", nombreCarpeta);
    FILE* pDetC = fopen(rutaArchivo, "rb");
    if (pDetC != NULL) {
        ArchivoDetallesCompra archivo("DetallesCompras.dat");
        archivo.borrar();
        DetalleTransaccion obj;
        while (fread(&obj, sizeof(obj), 1, pDetC) == 1) {
            archivo.guardarDetalleCompra(obj);
        }
        fclose(pDetC);
        cout << "[OK] Detalles de Compras restaurados." << endl;
    } else {
        cout << "[X] No se encontro respaldo de Detalles Compras." << endl;
    }

    /// --- 6. CLIENTES ---
    sprintf(rutaArchivo, "./backups/%s/Clientes.bkp", nombreCarpeta);
    FILE* pCli = fopen(rutaArchivo, "rb");
    if (pCli != NULL) {
        ArchivoClientes archivo("Clientes.dat");
        archivo.borrar();
        Cliente obj;
        while (fread(&obj, sizeof(obj), 1, pCli) == 1) {
            archivo.guardarCliente(obj);
        }
        fclose(pCli);
        cout << "[OK] Clientes restaurados." << endl;
    } else {
        cout << "[X] No se encontro respaldo de Clientes." << endl;
    }

    /// --- 7. PROVEEDORES ---
    sprintf(rutaArchivo, "./backups/%s/Proveedores.bkp", nombreCarpeta);
    FILE* pProv = fopen(rutaArchivo, "rb");
    if (pProv != NULL) {
        ArchivoProveedores archivo("Proveedores.dat");
        archivo.borrar();
        Proveedor obj;
        while (fread(&obj, sizeof(obj), 1, pProv) == 1) {
            archivo.guardarProveedor(obj);
        }
        fclose(pProv);
        cout << "[OK] Proveedores restaurados." << endl;
    } else {
        cout << "[X] No se encontro respaldo de Proveedores." << endl;
    }

    /// --- 8. EMPRESAS ---
    sprintf(rutaArchivo, "./backups/%s/Empresas.bkp", nombreCarpeta);
    FILE* pEmp = fopen(rutaArchivo, "rb");
    if (pEmp != NULL) {
        ArchivoEmpresas archivo("Empresas.dat");
        archivo.borrar();
        Empresa obj;
        while (fread(&obj, sizeof(obj), 1, pEmp) == 1) {
            archivo.guardarEmpresa(obj);
        }
        fclose(pEmp);
        cout << "[OK] Empresas restauradas." << endl;
    } else {
        cout << "[X] No se encontro respaldo de Empresas." << endl;
    }

    /// --- 9. CATEGORIAS ---
    sprintf(rutaArchivo, "./backups/%s/Categorias.bkp", nombreCarpeta);
    FILE* pCat = fopen(rutaArchivo, "rb");
    if (pCat != NULL) {
        ArchivoCategorias archivo("Categorias.dat");
        archivo.borrar();
        Categoria obj;
        while (fread(&obj, sizeof(obj), 1, pCat) == 1) {
            archivo.guardarCategoria(obj);
        }
        fclose(pCat);
        cout << "[OK] Categorias restauradas." << endl;
    } else {
        cout << "[X] No se encontro respaldo de Categorias." << endl;
    }

    cout << endl << "Proceso finalizado." << endl;
    system("pause");
}
