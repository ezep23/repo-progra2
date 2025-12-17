#ifndef FUNCIONESMENUCONFIGURACIONES_H_INCLUDED
#define FUNCIONESMENUCONFIGURACIONES_H_INCLUDED

void exportarProductosCSV();
void exportarClientesCSV();
void exportarProveedoresCSV();
void exportarVentasCSV();
void exportarDetalleVentasCSV();
void exportarComprasCSV();
void exportarDetalleComprasCSV();
void exportarEmpresasCSV();
void exportarCategoriasCSV();
void exportarCSVGeneral();

void backupProductos();
void backupVentas();
void backupDetalleVentas();
void backupCompras() ;
void backupDetalleCompras();
void backupClientes();
void backupProveedores();
void backupEmpresas();
void backupCategorias();
void backupGeneral();

void restaurarBackupProductos();
void restaurarBackupVentas();
void restaurarBackupDetalleVentas();
void restaurarBackupCompras();
void restaurarBackupDetalleCompras();
void restaurarBackupClientes();
void restaurarBackupProveedores();
void restaurarBackupEmpresas();
void restaurarBackupCategorias();
void restaurarBackupGeneral();

#endif // FUNCIONESMENUCONFIGURACIONES_H_INCLUDED
