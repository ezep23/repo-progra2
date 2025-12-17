#include <iostream>
using namespace std;

#include "string.h"

#include "../../archivos/Productos.h"
#include "../../archivos/Categorias.h"
#include "../../archivos/Proveedores.h"
#include "../../clases/Proveedor.h"
#include "../../clases/Producto.h"
#include "../../clases/Almacen.h"

void busquedaProfunda();

void nuevoProducto()
{
    ArchivoProductos productos("Productos.dat");
    ArchivoProveedores proveedores("Proveedores.dat");
    Producto nuevoProducto;

    char opcProveedor;
    cout << " El producto va a tener un proveedor nuevo? - Si 'S', No 'N'"<< endl;
    cout << " Opcion:";
    cin >> opcProveedor;

    if(opcProveedor == 'S' || opcProveedor == 's')
    {
        Proveedor nuevoProveedor;
        nuevoProveedor.cargar();

        int newID = proveedores.generarNuevoID();

        if( newID <= 0 )
        {
            cout << "Error al crear nuevo id" << endl;
            return;
        }

        nuevoProveedor.setId(newID);
        proveedores.guardarProveedor(nuevoProveedor);

        system("cls");
        nuevoProveedor.mostrar();

        system("pause");
        system("cls");

        cout << " # CREACION DEL NUEVO PRODUCTO ASIGNADO AL PROVEEDOR" << endl;

        nuevoProducto.setMarca( nuevoProveedor.getNombreEmpresa() );
        nuevoProducto.cargar( nuevoProveedor.getId() );
        system("cls");
        nuevoProducto.mostrar();

        productos.guardarProducto(nuevoProducto);
    }
    else
    {

        int opcId = 0;
        while(opcId <= 0)
        {

            system("cls");
            cout << " - SUB SUB SUB MENU -" << endl;
            cout << " # Ingrese el ID del proveedor, Presione '0' - 'CERO' para listar proveedores" << endl;
            cout << " Opcion:";
            cin >> opcId;

            if(opcId == 0)
            {
                system("cls");
                cout << endl;
                cout << " ### PROVEEDORES ###" << endl;
                proveedores.listarProveedores();
                system("pause");
            }

        }

        while(!proveedores.validarIdExiste(opcId))
        {
            system("cls");

            cout << "# Ingrese un id valido:";
            cin >> opcId;
        }

        system("cls");
        cout << endl;
        cout << "CREANDO NUEVO PRODUCTO ASOCIADO AL PROVEEDOR!" << endl;
        nuevoProducto.cargar(opcId);

    }
}

void listarProductos()
{
    ArchivoCategorias categorias("Categorias.dat");
    ArchivoProductos productos("Productos.dat");
    Producto producto;
    Almacen almacen;

    system("cls");
    int opc = -1;
    while(opc != 0)
    {
        opc = -1;
        cout << " ------------------------------" << endl;
        cout << "            SUBMENU            " << endl;
        cout << " ------------------------------" << endl;
        cout << " 1. Mostrar productos sin filtro " << endl;
        cout << " 2. Ingresar categoria " << endl;
        cout << " 3. Ingresar nombre del producto " << endl;
        cout << " 4. Ingresar marca" << endl;
        cout << " 0. Volver al menu de inventario" << endl;
        cout << " ------------------------------" << endl;
        cout << " Opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
            system("cls");
            productos.listarProductos();
            system("pause");
            system("cls");
            break;
        case 2:
            busquedaProfunda();
            break;

        case 3:
            char nombre[30];
            system("cls");
            cout << " # Ingrese el nombre del producto: ";
            cin.ignore();
            cin.getline(nombre, 30);

            if(productos.validarNombre(nombre)){
                almacen.consultarProductosMismoNombre(nombre);
                system("pause");
                system("cls");
            }else{

                while(!productos.validarNombre(nombre)){
                    system("cls");
                    cout << " Ese nombre no existe" << endl;
                    cout << " Ingrese otra: ";
                    cin.getline(nombre, 30);

                }
                system("cls");
                almacen.consultarProductosMismoNombre(nombre);
                system("pause");
                system("cls");
            }
            break;
        case 4:
            char marca[30];
            system("cls");
            cout << " Ingrese la marca del producto: " << endl;
            cout << " Marca: ";
            cin.getline(marca, 30);


            if(productos.validarNombre(marca)){
                almacen.consultarProductoMismaMarca(marca);
                system("pause");
                system("cls");
            }else{

                while(!productos.validarMarca(marca)){
                    system("cls");
                    cout << " Esa marca no existe" << endl;
                    cout << " Ingrese otra: ";
                    cin.getline(marca, 30);

                }
                system("cls");
                almacen.consultarProductoMismaMarca(marca);
                system("pause");
                system("cls");
            }
            break;
        }

    }
}

void editarProducto(){
    ArchivoProductos productos("Productos.dat");
    Producto prod;

    system("cls");

    int id=1;
    while(id != 0){
        int id=0;
        cout << " ------ SUBMENU ------" << endl;
        cout << " 0. Volver al menu" << endl;
        cout << " # Ingrese el ID del producto a editar: ";
        cin >> id;

        if(productos.validarIdExiste(id)){
            int pos = productos.obtenerUbicacionProducto(id);
            prod = productos.obtenerProducto(pos);

            productos.listarProducto(id);
            system("pause");

            int opc = 0;
            cout << " ----------------------------" << endl;
            cout << " - Que desea editar?     " << endl;
            cout << " 0. Volver al menu" << endl;
            cout << " 1. Nombre" << endl;
            cout << " 2. Precio" << endl;
            cout << " 3. Stock" << endl;
            cout << " 4. Categoria" << endl;
            cin >> opc;

            while(opc < 0 || opc > 5){
                system("cls");
                cout << " ----------------------------" << endl;
                cout << "      ¿Que desea editar?     " << endl;
                cout << " 0. Volver al menu" << endl;
                cout << " 1. Nombre" << endl;
                cout << " 2. Precio" << endl;
                cout << " 3. Stock" << endl;
                cout << " 4. Categoria" << endl;
                cin >> opc;
            }

            if(opc == 0){
                return;
            }

           switch(opc){
                case 1:
                    system("cls");
                    char nombre[25];
                    cout << "Nombre: ";
                    cin.ignore();
                    cin.getline(nombre,25);

                    if(!productos.validarNombre(nombre)){
                        prod.setNombre(nombre);
                        int pos = productos.obtenerUbicacionProducto(prod.getId());

                        productos.editarProducto(prod, pos);
                        prod.mostrar();
                        system("pause");
                        system("cls");
                        return;
                    }

                    cout << " ERROR"<<endl;
                    system("pause");
                    system("cls");
                    break;
                case 2:{
                    system("cls");
                    float precio = 0;
                    cout << "Precio: ";
                    cin >> precio;

                    if(precio > 0){
                        prod.setPrecio(precio);
                        int pos = productos.obtenerUbicacionProducto(prod.getId());

                        productos.editarProducto(prod, pos);
                        prod.mostrar();
                        system("pause");
                        system("cls");
                        return;
                    }

                    cout << " ERROR"<<endl;
                    system("pause");
                    system("cls");

                    break;

                }
                case 3: {

                    system("cls");
                    float stock = 0;
                    cout << "Stock: ";
                    cin >> stock;

                    if(stock > 0){
                        prod.setStock(stock);
                        int pos = productos.obtenerUbicacionProducto(prod.getId());

                        productos.editarProducto(prod, pos);
                        prod.mostrar();
                        system("pause");
                        system("cls");
                        return;
                    }

                    cout << " ERROR"<<endl;
                    system("pause");
                    system("cls");

                    break;
                    }
                case 4:{

                    system("cls");
                    char categori[25];
                    cout << "Categoria: ";
                    cin.ignore();
                    cin.getline(categori,25);

                    ArchivoCategorias categorias("Categorias.dat");

                    if(categorias.validarCategoriaExiste(categori)){

                        int idCat = categorias.obtenerUbicacionCategoria(categori);

                        prod.setIdCategoria(idCat);
                        prod.setCategoria(categori);
                        int pos = productos.obtenerUbicacionProducto(prod.getId());

                        productos.editarProducto(prod, pos);
                        prod.mostrar();
                        system("pause");
                        system("cls");
                        return;
                    }

                    int idCat = categorias.generarNuevoID();

                    prod.setIdCategoria(idCat);
                    prod.setCategoria(categori);
                    int pos = productos.obtenerUbicacionProducto(prod.getId());

                    productos.editarProducto(prod, pos);
                    prod.mostrar();
                    system("pause");
                    system("cls");
                    break;
                    }
           }
        }

    }

}

void eliminarProducto()
{
    system("cls");
    ArchivoProductos productos("Productos.dat");
    ArchivoCategorias categorias("Categorias.dat");
    Almacen almacen;

    int opc = 0;
    cout << " ------ SUBMENU ------" << endl;
    cout << " 1. Ingresar el ID a eliminar" << endl;
    cout << " 2. Consultar productos " << endl;
    cout << " 0. Volver " << endl;
    cout << " Opcion: " << endl;
    cin >> opc;

    if(opc == 0)
    {
        return;
    }

    while(true){

        if(opc == 1){

            int id=0;
            system("cls");
            cout << " Ingrese el ID: ";
            cin >> id;

            while(!productos.validarIdExiste(id)){
                cout << " Ingrese un ID que exista: " << endl;
                cin >> id;
            }

            if(productos.bajaProducto(id)){
                system("cls");
                cout << "# PRODUCTO ELIMINADO CORRECTAMENTE"<< endl;
                return;
            }

            system("cls");
            cout << " # NO SE PUDO BORRAR EL PRODUCTO " << endl;
            system("pause");
        }

        if(opc == 2){
            busquedaProfunda();
        }

    }

}

void busquedaProfunda()
{
    ArchivoCategorias categorias("Categorias.dat");
    ArchivoProductos productos("Productos.dat");
    Almacen almacen;

    system("cls");

    char eleccion;
    cout << " Desea ver solo los productos de la categoria. - Si 'S' o No 'N' " << endl;
    cout << " Opcion: ";
    cin >> eleccion;

    if(eleccion == 'S' || eleccion == 's')
    {

        char opcion[25];

        system("cls");

        cout << " Ingrese el nombre de la categoria: ";
        cin.ignore();
        cin.getline(opcion, 25);

        if( !categorias.validarCategoriaExiste(opcion) )
        {

            while(!categorias.validarCategoriaExiste(opcion))
            {
                cout << "Ingrese un nombre correcto: ";
                cin.getline(opcion,25);
            }

        }


        int pos = categorias.obtenerUbicacionCategoria(eleccion);
        Categoria obj = categorias.obtenerCategoria(pos);
        productos.listarProductosCategoria(obj.getId());
        system("pause");
        system("cls");

        return;
    }
    system("cls");

    char prod[25];
    cout << " Ingrese el nombre del producto: ";
    cin.ignore();
    cin.getline(prod, 25);

    while(true){

        if( productos.validarNombre(prod) ){

           almacen.consultarProductosMismoNombre(prod);
           system("pause");
           system("cls");
           return;
        }

        cout << " Ese nombre no esta registrado, ingrese otro: ";
        cin.getline(prod, 25);

    }

}

/**
system("cls");
        cout << " # PRODUCTOS DEL PROVEEDOR" << endl;

        Almacen almacen;
        almacen.consultarProductosProveedor(opcId);

        if(opcId < 0){
            cout << "No puede ingresar ese ID.";
            system("pause");

            while(opcId <= 0){
                system("cls");
                proveedores.listarProveedores();

                cout << " Ingrese el ID del proveedor: ";
                cin >> opcId;
            }

            while(!proveedores.validarIdExiste(opcId) && opcId > 0){
                system("cls");
                cout << " Ese id no existe, ingrese uno existente: ";
                cin >> opcId;
            }

           system("cls");
           cout << " # PRODUCTOS DEL PROVEEDOR" << endl;
           almacen.consultarProductosProveedor(opcId);

        }else{

            while(!proveedores.validarIdExiste(opcId) && opcId > 0){
                system("cls");
                cout << " Ese id no existe, ingrese uno existente: ";
                cin >> opcId;
            }

            system("cls");
            cout << " # PRODUCTOS DEL PROVEEDOR" << endl;
            almacen.consultarProductosProveedor(opcId);

        }
    }
    return;

*/

