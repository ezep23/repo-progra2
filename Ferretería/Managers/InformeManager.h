#pragma once
#include "VentaManager.h"
#include "AlmacenManager.h"
#include "CategoriaManager.h"

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
    void listarBajoStock();

  private:
    VentaManager _ventaManager;
    AlmacenManager _almacenManager;
    CategoriaManager _categoriaManager;
};
