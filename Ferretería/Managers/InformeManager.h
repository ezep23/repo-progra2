#pragma once
#include "VentaManager.h"


class InformeManager{
  public:
    InformeManager();

    void recaudacionMensual();
    void recaudacionAnual();

  private:
    VentaManager _ventaManager;
};
