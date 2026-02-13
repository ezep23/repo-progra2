#include <iostream>

#include "ClienteManager.h"
#include "../Entidades/Cliente.h"

#include "../Utils.h"

using namespace std;



ClienteManager::ClienteManager(){

}

void ClienteManager::cargar(){
  int id;
  string nombre;
  string dni;

  id = _repo.getNuevoID();

  cout << "Cargar Nuevo Personal ----" << endl;
  cout << "ID: " << id << endl;

  cout << "Ingrese DNI: ";
  dni = cargarCadena();

  if(!validarDNI(dni)){
    do{
        cout << "Error, ingrese un dni correcto: ";

        dni = cargarCadena();
        validarDNI(dni);

    }while(validarDNI(dni));
  }

  cout << "Ingrese nombre: ";
  nombre = cargarCadena();

  if(_repo.guardar(Cliente(id, nombre, dni))){
    cout << "Se agrego correctamente" << endl;
  }
  else{
    cout << "Error al intentar guardar el personal." << endl;
  }

}

void ClienteManager::mostrar(){
  int cantidad = _repo.getCantidadRegistros();
  Cliente *vCliente = new Cliente[cantidad];

  if(vCliente == nullptr){
    cout << "No se pudo asignar memoria..." << endl;
    exit(-100);
  }

  _repo.leerTodos(vCliente, cantidad);

  cout << "CLIENTES: " << endl;

  for(int i=0; i<cantidad; i++){
    if(vCliente[i].getEstado()){
        mostrarLista(vCliente[i]);
    }
  }
    delete [] vCliente;
}

void ClienteManager::eliminar(){
  int id, pos;
  cout << "Ingrese el ID del cliente: ";
  cin >> id;

  pos = _repo.buscarID(id);
  if(_repo.eliminar(pos)){
    cout << "REGISTRO ELIMINADO" << endl;
    return;
  }

  cout << "NO SE PUDO ELIMINAR EL REGISTRO" << endl;
  return;
}

void ClienteManager::actualizar(){
  int id, pos, opc;
  cout << "Ingrese el ID del cliente: ";
  cin >> id;

  pos = _repo.buscarID(id);
  Cliente reg = _repo.leer(pos);

  system("cls");
  cout << "Que desea actualizar?" << endl;
  cout << " 1 - NOMBRE" << endl;
  cout << " 2 - DNI" << endl;
  cout << " Opcion: ";
  cin >> opc;

  switch(opc){
    case 0:{
        cout << "Error" << endl;
        system("pause");
        return;
     }
    case 1:{
        string nombre;
        nombre = cargarCadena();

        reg.setNombre(nombre);
        _repo.guardar(pos, reg);

        cout << "NOMBRE ACTUALIZADO" << endl;
        return;

     }
     case 2:{
        string dni;
        dni = cargarCadena();

        if(!validarDNI(dni)){
            do{
                cout << "Error, ingrese un dni correcto: ";

                dni = cargarCadena();
                validarDNI(dni);

            }while(validarDNI(dni));
        }

        reg.setDni(dni);
        _repo.guardar(pos, reg);

        cout << "DNI ACTUALIZADO" << endl;
        return;
     }
 }

}


bool ClienteManager::existeRegistro(int id){
   int pos = _repo.buscarID(id);

   if(pos){

        if(_repo.leer(pos).getEstado()){
            return true;
        }

        return false;
   }

   return false;
}

void ClienteManager::mostrar(int id){
    int pos = _repo.buscarID(id);
    cout << "Cliente asignado: " << _repo.leer(pos).getNombre() << " - " << _repo.leer(pos).getDni() << endl;
}

void ClienteManager::mostrarLista(const Cliente &reg){
  cout << "ID: " << reg.getId() << endl;
  cout << "DNI: " << reg.getDni() << endl;
  cout << "Nombre: "<< reg.getNombre() << endl;
  cout << "------------" <<endl;
}

