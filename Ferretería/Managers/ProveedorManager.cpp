#include <iostream>

#include "ProveedorManager.h"
#include "../Entidades/Proveedor.h"

#include "../Utils.h"

using namespace std;


ProveedorManager::ProveedorManager(){

}

void ProveedorManager::cargar(){
  int id;
  int idE;
  string nombre;
  string apellido;
  string tel;
  string email;
  string dni;

  id = _repo.getNuevoID();

  cout << "CARGAR NUEVO PROVEEDOR ----" << endl;
  cout << "ID EMPRESA: (0 - Salir)";
  cin >> idE;

  if(idE <= 0){
    return;
  }

  int pos = _repo.buscarID(idE);
  Proveedor prov = _repo.leer(pos);

  if(!prov.getEstado()){
    cout << "NO SE HA ENCONTRADO ESE PROVEEDOR" << endl;
    return;
  }
  cout << "ID PROVEEDOR: " << id << endl;

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

  if(_repo.guardar(Proveedor(nombre, apellido, tel, email, dni, id, idE))){
    cout << "Se agrego correctamente" << endl;
  }
  else{
    cout << "Error al intentar guardar el personal." << endl;
  }

}

void ProveedorManager::mostrar(){
  int cantidad = _repo.getCantidadRegistros();
  Proveedor *vProveedor = new Proveedor[cantidad];

  if(vProveedor == nullptr){
    cout << "No se pudo asignar memoria..." << endl;
    exit(-100);
  }

  _repo.leerTodos(vProveedor, cantidad);

  cout << "CLIENTES: " << endl;

  for(int i=0; i<cantidad; i++){
    if(vProveedor[i].getEstado()){
        mostrarLista(vProveedor[i]);
    }
  }
    delete [] vProveedor;
}

void ProveedorManager::eliminar(){
  int id, pos;
  cout << "Ingrese el ID del proveedor: ";
  cin >> id;

  pos = _repo.buscarID(id);
  Proveedor reg = _repo.leer(pos);

  reg.setEstado(false);
  cout << "CLIENTE ELIMINADO" << endl;
}

void ProveedorManager::actualizar(){
  int id, pos, opc;
  cout << "Ingrese el ID del proveedor: ";
  cin >> id;

  pos = _repo.buscarID(id);
  Proveedor reg = _repo.leer(pos);

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

void ProveedorManager::mostrarLista(const Proveedor &reg){
  cout << "ID: " << reg.getId() << endl;
  cout << "ID Empresa: " << reg.getIdEmpresa() << endl;
  cout << "DNI: " << reg.getDni() << endl;
  cout << "Nombre: "<< reg.getNombre() << endl;
  cout << "Apellido: " << reg.getApellido() << endl;
  cout << "Telefono: " << reg.getTelefono() << endl;
  cout << "Email: " << reg.getEmail() << endl;
  cout << "------------" <<endl;
}

