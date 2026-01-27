#include <iostream>
using namespace std;

#include "../utils.h" // para cargar cadena (string)

#include "../Entidades/Cliente.h"
#include "../Entidades/Transaccion.h"

#include "VentaManager.h"

VentaManager::VentaManager(){

}

void VentaManager::cargarVenta(){
    int id;
    int idCliente;
    int posCliente;
    Transaccion venta;

    id = _repo.getNuevoID();

    cout << "--- NUEVA VENTA #" << id << " ----" << endl;

    cout << "Ingrese el ID de Cliente ('0' - para salir): ";
    cin >> idCliente;

    if(idCliente == 0){
        return;
    }

    do{
        cout << "ID de Cliente ('0' - para salir): ";
        cin >> idCliente;

        if(idCliente == 0){
            return;
        }

        if(idCliente != 0){
            posCliente = _repoCliente.buscarID(idCliente);

            if(posCliente == -1){
                cout << "El numero no es valido!" << endl;
            }
        }
    } while(posCliente == -1 && idCliente != 0);

    Cliente reg;
    reg =_repoCliente.leer(posCliente);

    if(reg.getEstado()){
        cout << "El cliente asignado es: " << reg.getNombre() << endl;

        if(_repo.guardar(Transaccion(id, idCliente, )))
    }else{
        cout << "Ese cliente no existe" << endl;
        return;
    }

}

void VentaManager::mostrarVentas(){
  cout << "------ Lista de ventas ------  "<<endl;;
  int cantidad = _repo.getCantidadRegistros();

  for(int i=0; i<cantidad; i++){
    if(_repo.leer(i).getEstado()){
        mostrarVentaCompleta(_repo.leer(i));
    }
  }
}

void VentaManager::modificarVenta(){
  int id, pos, opc;
  cout << "Ingrese el ID de la venta: ";
  cin >> id;

  pos = _repo.buscarID(id);
  Transaccion reg = _repo.leer(pos);

  system("cls");
  cout << "Que desea eliminar?" << endl;
  cout << " 1 - ID PERSONA" << endl;
  cout << " 2 - HORA" << endl;
  cout << " 3 - FECHA" << endl;
  cout << " 4 - TIPO DE FACTURA" << endl;
  cout << " 5 - ESTADO" << endl;
  cout << " Opcion: ";
  cin >> opc;

  switch(opc){
    case 0:{
        cout << "Error" << endl;
        return;
     }
    case 1:{
        int idCliente;
        cout << "ID cliente: ";
        cin >> idCliente;

        Cliente cli = _repoCliente.buscarID(id);

        if(cli.getEstado()){
            reg.setIdPersona(cli.getId());

            if(_repo.guardar(pos, reg)){
                cout << "SE MODIFICO LA VENTA" << endl;
                return;
            }

            cout << "NO SE PUDO MODIFICAR LA VENTA" << endl;
            return;
        }

        cout << "NO EXISTE ESE CLIENTE" << endl;
        return;
    }
    case 2:{
        string nombre;
        nombre = cargarCadena();

        reg.setNombre(nombre);
        _repo.guardar(pos, reg);

        cout << "NOMBRE ACTUALIZADO" << endl;
        return;

     }
    case 3:{
        string apellido;
        apellido = cargarCadena();

        reg.setApellido(apellido);
        _repo.guardar(pos, reg);

        cout << "APELLIDO ACTUALIZADO" << endl;
        return;
     }
     case 4:{
        string tel;
        tel = cargarCadena();

        reg.setTelefono(tel);
        _repo.guardar(pos, reg);

        cout << "TELEFONO ACTUALIZADO" << endl;
        return;
     }
     case 5:{
        string email;
        email = cargarCadena();

        reg.setEmail(email);
        _repo.guardar(pos, reg);

        cout << "EMAIL ACTUALIZADO" << endl;
        return;
     }
    case 6:{
        reg.setEstado(!reg.getEstado());
        _repo.guardar(pos, reg);

        system("cls");
        cout << "ESTADO ACTUALIZADO" << endl;
        return;
    }
 }
}

void VentaManager::eliminarVenta(){
  int id, pos;
  Transaccion venta;
  char respuesta;

  cout << "---- Eliminar venta ----"<<endl;
  cout << "Ingrese ID de la venta: ";
  cin >> id;

  pos = _repo.buscarID(id);

  if(pos != -1){
    venta = _repo.leer(pos);

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
    cout << " Hora: " << reg.getHoraTransaccion() << endl;
    cout << " Fecha: " << reg.getFechaTransaccion() << endl;
    cout << " Tipo factura: " << reg.getTipoFactura() << endl;
    cout << "-----------------------------------" << endl;
}
