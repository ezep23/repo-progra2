#include <iostream>
using namespace std;

#include "../utils.h" // para cargar cadena (string)

#include "../Entidades/Cliente.h"
#include "../Entidades/Transaccion.h"

#include "VentaManager.h"

VentaManager::VentaManager(){

}

int VentaManager::obtenerNumeroRegistros(){
    return _repo.getCantidadRegistros();
}

bool VentaManager::guardar(int pos, Transaccion reg){
    if(_repo.guardar(pos, reg)){
        return true;
    }
}

int VentaManager::cargar() {
    int id;
    int idCliente;
    int posCliente = -1; // IMPORTANTE: Inicializar con valor inválido

    id = _repo.getNuevoID();

    cout << "--- NUEVA VENTA #" << id << " ----" << endl;

    do {
        cout << "Ingrese el ID de Cliente ('0' - para salir): ";
        cin >> idCliente;

        if (idCliente == 0) {
            return 0;
        }

        posCliente = _repoCliente.buscarID(idCliente);

        if (posCliente == -1) {
            cout << ">>> Error: El cliente no existe. Intente nuevamente." << endl;
        }

    } while (posCliente == -1);

    Cliente cliente = _repoCliente.leer(posCliente);

    if (!cliente.getEstado()) {
        cout << ">>> Error: El cliente seleccionado ha sido dado de baja." << endl;
        return 0;
    }

    cout << "Cliente asignado: " << cliente.getNombre() << " " << cliente.getApellido() << endl;
    system("pause");

    int d, m, a;
    Fecha fecha;
    do {
        system("cls");
        cout << "--- FECHA DE LA VENTA ---" << endl;
        cout << "Dia: "; cin >> d;
        cout << "Mes: "; cin >> m;
        cout << "Anio: "; cin >> a;
    } while (!fecha.validarFecha(d, m, a));

    fecha.setDia(d); fecha.setMes(m); fecha.setAnio(a);


    int h, minu;
    Hora hora;
    do {
        system("cls");
        cout << "--- HORA DE LA VENTA ---" << endl;
        cout << "Hora: "; cin >> h;
        cout << "Minutos: "; cin >> minu;
    } while (!hora.validarHora(h, minu));

    hora.setHora(h); hora.setMinutos(minu);

    char opcFactu;
    do {
        system("cls");
        cout << "--- TIPO DE FACTURA ---" << endl;
        cout << " 'A' - Responsable Inscripto (Empresa) " << endl;
        cout << " 'B' - Consumidor Final (Particular) " << endl;
        cout << "Opcion: ";
        cin >> opcFactu;
        opcFactu = toupper(opcFactu);
    } while (opcFactu != 'A' && opcFactu != 'B');
    cin.ignore();

    Transaccion nuevaVenta(id, idCliente, 0, hora, fecha, opcFactu);

    if (_repo.guardar(nuevaVenta)) {
        return id;
    } else {
        cout << "Error critico al guardar la cabecera de la venta." << endl;
        return 0;
    }
}

void VentaManager::mostrar(){
  cout << "------ Lista de ventas ------  "<<endl;;
  int cantidad = _repo.getCantidadRegistros();

  for(int i=0; i<cantidad; i++){
    if(_repo.leer(i).getEstado()){
        mostrarVentaCompleta(_repo.leer(i));
    }
  }
}

int VentaManager::buscarPosicion(int id){
    return _repo.buscarID(id);
}

Transaccion VentaManager::traerRegistro(int pos){
    return _repo.leer(pos);
}


void VentaManager::mostrar(int id){

    int pos = _repo.buscarID(id);

    if(_repo.leer(pos).getEstado()){
        cout << "-------------------------------" << endl;
        mostrarVentaCompleta(_repo.leer(pos));
        cout << "-------------------------------" << endl;
    }else{
        cout << "VENTA NO ENCONTRADA";
        return;
    }
}

void VentaManager::modificar(){
  int id, pos, opc;
  cout << "Ingrese el ID de la venta: ";
  cin >> id;

  pos = _repo.buscarID(id);

  if(pos == -1){
    cout << "ESE REGISTRO NO EXISTE" << endl;
    return;
  }

  Transaccion reg = _repo.leer(pos);

  system("cls");
  cout << "Que desea modificar?" << endl;
  cout << " 1 - ID CLIENTE" << endl;
  cout << " 2 - FECHA" << endl;
  cout << " 3 - HORA" << endl;
  cout << " 4 - TIPO DE FACTURA" << endl;
  cout << " Opcion: ";
  cin >> opc;

  switch(opc){
    case 0:{
        cout << "Error" << endl;
        return;
     }
    case 1:{

        if(reg.getEstado()){

            int posCliente = _repoCliente.buscarID(reg.getIdPersona());
            Cliente cli = _repoCliente.leer(posCliente);
            cout << " ID CLIENTE: " << cli.getId() << endl;
            cout << " NOMBRE Y APELLIDO: " << cli.getNombre() << " " << cli.getApellido() << endl;

            int opc;

            cout << " Ingrese el ID del cliente (0 - salir)" << endl;
            cin >> opc;

            if(opc <= 0){
                return;
            }

            if(opc > 0 ){

                posCliente = _repoCliente.buscarID(opc);
                Cliente cli = _repoCliente.leer(posCliente);

                if(cli.getEstado()){
                    reg.setIdPersona(opc);

                    if(_repo.guardar(pos, reg)){
                        cout << "SE GUARDO EL REGISTRO" << endl;
                        return;
                    }

                    cout << "NO SE PUDO GUARDAR EL REGISTRO" << endl;
                    return;
                }

                cout << "NO SE ENCONTRÓ ESE CLIENTE" << endl;
                return;
            }

            cout << "NO SE PUDO MODIFICAR LA VENTA" << endl;
            return;
        }

        cout << "NO EXISTE ESE CLIENTE" << endl;
        return;
    }
    case 2:{

        int dia, mes, anio;
        Fecha fecha;
        do{
            system("cls");
            cout << "Ingrese el dia de hoy: ";
            cin >> dia;

            cout << "Ingrese el mes actual: ";
            cin >> mes;

            cout << "Ingrese el anio actual: ";
            cin >> anio;
        }while(!fecha.validarFecha(dia, mes, anio));

        reg.setFechaEmision(fecha);

        if(_repo.guardar(pos, reg)){
            cout << "FECHA ACTUALIZADA CORRECTAMENTE";
        }

     }
    case 3:{

     }
     case 4:{

        cout << "TIPO DE FACTURA ACTUAL: " << reg.getTipoFactura() <<endl;
        system("cls");

        cout << "---- NUEVO TIPO DE FACTURA ---- "<< endl;
        cout << " 0 - SALIR " << endl;
        cout << " 1 - TIPO 'A' " << endl;
        cout << " 2 - TIPO 'B' " << endl;
        int opc;
        cout << "Opcion: ";
        cin >> opc;

        if(opc == 0){
            return;
        }

        if(opc == 1){
            reg.setTipoFactura('A');
            _repo.guardar(pos, reg);
            cout << "TIPO DE FACTURA MODIFICADO" << endl;
            return;
        }

        if(opc == 2){
            reg.setTipoFactura('B');
            _repo.guardar(pos, reg);
            cout << "TIPO DE FACTURA MODIFICADO" << endl;
            return;
        }

        cout << "ERROR" << endl;
        return;

     }
 }
}

void VentaManager::eliminar(){
    int id, pos;
    Transaccion venta;
    char respuesta;

    cout << "---- Eliminar venta ----"<<endl;
    cout << "Ingrese ID de la venta: ";
    cin >> id;

    pos = _repo.buscarID(id);

    if(pos != -1){
        venta = _repo.leer(pos);

        if(venta.getEstado() == false){
            cout << "ESTA VENTA YA HA SIDO ELIMINADA" << endl;
            return;
        }

        cout << "Tarea a eliminar: "<<endl;
        mostrarVentaCompleta(venta);

        cout << "Esta segudro de que lo quiere eliminar ? (S/N):";
        cin >> respuesta;

        if(respuesta == 'S' || respuesta == 's'){

            if(_repo.eliminar(pos)){
                cout << "La tarea fue eliminada con exito!" << endl;
            }else{
                cout << "Ocurrio un error al intentar actualizar la tarea." <<endl;
            }
        }

    }else{
        cout << "La tarea no existe en el archivo" << endl;
    }
}

void VentaManager::mostrarVentaCompleta(const Transaccion &reg){
    cout << "-----------------------------------" << endl;
    cout << " ID: " << reg.getIdTransaccion() << endl;
    cout << " ID Cliente: " << reg.getIdPersona() << endl;
    cout << " Monto total: " << reg.getMontoTotal() << endl;


    Fecha f = reg.getFechaTransaccion();
    cout << " Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio();

    cout << " - ";

    cout << "Hora: ";
    Hora h = reg.getHoraTransaccion();

    if(h.getHora() < 10){
        cout << "0";
    }
    cout << h.getHora() << ":";

    if(h.getMinutos() < 10){
        cout << "0";
    }
    cout << h.getMinutos()<< endl;


    cout << " Tipo factura: " << reg.getTipoFactura() << endl;
    cout << "-----------------------------------" << endl;
}
