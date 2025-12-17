#ifndef CONFIGURACIONES_H_INCLUDED
#define CONFIGURACIONES_H_INCLUDED


#include "./funciones-menus/funcionesMenuConfiguraciones.h"

void menuCSV();
void menuRealizarCopias();
void menuRestaurarCopias();

void configuraciones(){

    int opc = 1;
    while(opc !=0){

    system("cls");
    cout << " --------------------------" <<endl;
    cout << "       CONFIGURACIONES     " <<endl;
    cout << endl;
    cout << " 1. EXPORTAR DATOS A CSV" << endl;
    cout << " 2. REALIZAR COPIA DE SEGURIDAD" << endl;
    cout << " 3. RESTAURAR COPIA DE SEGURIDAD" << endl;
    cout << " 0. Volver al menu" << endl;
    cout << " --------------------------" <<endl;
    cout << " Opcion: ";
    cin >> opc;

        switch(opc){
            case 0: break;
            case 1: menuCSV(); break;
            case 2: menuRealizarCopias(); break;
            case 3: menuRestaurarCopias(); break;
            default: break;
        }

    }
    return;
}

void menuCSV(){
    int subopc = 0;
    while(true){

    system("cls");
    cout << " -----------------------------" <<endl;
    cout << "  SUB-SUB-MENU REALIZAR CSV " <<endl;
    cout << endl;
    cout << " 1. REALIZAR COPIA DE PRODUCTOS" << endl;
    cout << " 2. REALIZAR COPIA DE VENTAS" << endl;
    cout << " 3. REALIZAR COPIA DE DETALLE VENTAS" << endl;
    cout << " 4. REALIZAR COPIA DE COMPRAS" << endl;
    cout << " 5. REALIZAR COPIA DE DETALLE COMPRAS" << endl;
    cout << " 6. REALIZAR COPIA DE CLIENTES" << endl;
    cout << " 7. REALIZAR COPIA DE PROVEEDORES" << endl;
    cout << " 8. REALIZAR COPIA DE EMPRESAS" << endl;
    cout << " 9. REALIZAR COPIA DE CATEGORIAS" << endl;
    cout << " 10. REALIZAR CSVS GENERAL" << endl;
    cout << " 0. Volver al submenu de config." << endl;
    cout << " -----------------------------" <<endl;
    cout << " Opcion: ";
    cin >> subopc;

    switch(subopc){
        case 0: break;
        case 1: exportarProductosCSV(); break;
        case 2: exportarVentasCSV(); break;
        case 3: exportarDetalleVentasCSV(); break;
        case 4: exportarComprasCSV(); break;
        case 5: exportarDetalleComprasCSV(); break;
        case 6: exportarClientesCSV(); break;
        case 7: exportarProveedoresCSV(); break;
        case 8: exportarEmpresasCSV(); break;
        case 9: exportarCategoriasCSV(); break;
        case 10: exportarCSVGeneral(); break;
    }
  }
}


void menuRealizarCopias(){

    int subopc = 0;
    while(true){

    system("cls");
    cout << " -----------------------------" <<endl;
    cout << "  SUB-SUB-MENU REALIZAR COPIAS " <<endl;
    cout << endl;
    cout << " 1. REALIZAR COPIA DE PRODUCTOS" << endl;
    cout << " 2. REALIZAR COPIA DE VENTAS" << endl;
    cout << " 3. REALIZAR COPIA DE DETALLE VENTAS" << endl;
    cout << " 4. REALIZAR COPIA DE COMPRAS" << endl;
    cout << " 5. REALIZAR COPIA DE DETALLE COMPRAS" << endl;
    cout << " 6. REALIZAR COPIA DE CLIENTES" << endl;
    cout << " 7. REALIZAR COPIA DE PROVEEDORES" << endl;
    cout << " 8. REALIZAR COPIA DE EMPRESAS" << endl;
    cout << " 9. REALIZAR COPIA DE CATEGORIAS" << endl;
    cout << " 10. REALIZAR BACKUP GENERAL" << endl;
    cout << " 0. Volver al submenu de config." << endl;
    cout << " -----------------------------" <<endl;
    cout << " Opcion: ";
    cin >> subopc;

    switch(subopc){
        case 0: break;
        case 1: backupProductos(); break;
        case 2: backupVentas(); break;
        case 3: backupDetalleVentas(); break;
        case 4: backupCompras(); break;
        case 5: backupDetalleCompras(); break;
        case 6: backupClientes(); break;
        case 7: backupProveedores(); break;
        case 8: backupEmpresas(); break;
        case 9: backupCategorias(); break;
        case 10: backupGeneral(); break;
    }
  }
}
void menuRestaurarCopias(){

    int subopc = 1;
    while(subopc == 0){

    system("cls");
    cout << " ------------------------------" <<endl;
    cout << " SUB-SUB-MENU RESTAURAR COPIAS " <<endl;
    cout << endl;
    cout << " 1. RESTAURAR COPIA DE PRODUCTOS" << endl;
    cout << " 2. RESTAURAR COPIA DE VENTAS" << endl;
    cout << " 3. RESTAURAR COPIA DE DETALLE VENTAS" << endl;
    cout << " 4. RESTAURAR COPIA DE COMPRAS" << endl;
    cout << " 5. RESTAURAR COPIA DE DETALLE COMPRAS" << endl;
    cout << " 6. RESTAURAR COPIA DE CLIENTES" << endl;
    cout << " 7. RESTAURAR COPIA DE PROVEEDORES" << endl;
    cout << " 8. RESTAURAR COPIA DE EMPRESAS" << endl;
    cout << " 9. RESTAURAR COPIA DE CATEGORIAS" << endl;
    cout << " 10. RESTAURAR BACKUP GENERAL" << endl;
    cout << " 0. Volver al submenu de config." << endl;
    cout << " ------------------------------" <<endl;
    cout << " Opcion: ";
    cin >> subopc;

    switch(subopc){
        case 0: break;
        case 1: restaurarBackupProductos(); break;
        case 2: restaurarBackupVentas(); break;
        case 3: restaurarBackupDetalleVentas(); break;
        case 4: restaurarBackupCompras(); break;
        case 5: restaurarBackupDetalleCompras(); break;
        case 6: restaurarBackupClientes(); break;
        case 7: restaurarBackupProveedores(); break;
        case 8: restaurarBackupEmpresas(); break;
        case 9: restaurarBackupCategorias(); break;
        case 10: restaurarBackupGeneral(); break;
    }

  }

}


#endif // CONFIGURACIONES_H_INCLUDED
