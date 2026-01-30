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
  string apellido;
  string tel;
  string email;
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

  cout << "Ingrese apellido: ";
  apellido = cargarCadena();

  cout << "Ingrese telefono: ";
  tel = cargarCadena();

  cout << "Ingrese email: ";
  email = cargarCadena();

  if(_repo.guardar(Cliente(nombre, apellido, tel, email, dni, id))){
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
  cout << "Que desea eliminar?" << endl;
  cout << " 1 - NOMBRE" << endl;
  cout << " 2 - APELLIDO" << endl;
  cout << " 3 - TELEFONO" << endl;
  cout << " 4 - EMAIL" << endl;
  cout << " 5 - DNI" << endl;
  cout << " 6 - ESTADO" << endl;
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
        string apellido;
        apellido = cargarCadena();

        reg.setApellido(apellido);
        _repo.guardar(pos, reg);

        cout << "APELLIDO ACTUALIZADO" << endl;
        return;
     }
     case 3:{
        string tel;
        tel = cargarCadena();

        reg.setTelefono(tel);
        _repo.guardar(pos, reg);

        cout << "TELEFONO ACTUALIZADO" << endl;
        return;
     }
     case 4:{
        string email;
        email = cargarCadena();

        reg.setEmail(email);
        _repo.guardar(pos, reg);

        cout << "EMAIL ACTUALIZADO" << endl;
        return;
     }
     case 5:{
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
    case 6:{
        reg.setEstado(!reg.getEstado());
        _repo.guardar(pos, reg);

        system("cls");
        cout << "ESTADO ACTUALIZADO" << endl;
        return;
    }
 }

}

void ClienteManager::mostrarLista(const Cliente &reg){
  cout << "ID: " << reg.getId() << endl;
  cout << "DNI: " << reg.getDni() << endl;
  cout << "Nombre: "<< reg.getNombre() << endl;
  cout << "Apellido: " << reg.getApellido() << endl;
  cout << "Telefono: " << reg.getTelefono() << endl;
  cout << "Email: " << reg.getEmail() << endl;
  cout << "------------" <<endl;
}

