#pragma once
#include "VentaManager.h"
#include "AlmacenManager.h"
#include "CategoriaManager.h"
#include "CompraManager.h"

class InformeManager{
  public:
    InformeManager();

    void recaudacionMensual();
    void recaudacionMensualCategoria();
    void numeroVentasMensualCategoria();
    void recaudacionAnual();
    void recaudacionAnualCategoria();
    void numeroVentasAnualCategoria();
    void numeroProductosVendidosCategoria();
    void numeroProductosProveeedor();
    void ventasPorEmpleado();
    void comprasPorEmpleado();
    void listarBajoStock();

  private:
    VentaManager _ventaManager;
    CompraManager _compraManager;
    AlmacenManager _almacenManager;
    CategoriaManager _categoriaManager;
};
