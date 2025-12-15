#include <iostream>
using namespace std;

#include "string.h"

#include "../../archivos/Productos.h"
#include "../../archivos/Categorias.h"
#include "../../clases/Producto.h"

void busquedaProfunda();

void nuevaProducto(){
    ArchivoProductos productos("Productos.dat");
    Producto nuevoProducto;

    int id=0;
    nuevoProducto.cargar(id);

}

void listarProductos(){
    ArchivoCategorias categorias("Categorias.dat");
    ArchivoProductos productos("Productos.dat");
    Producto producto;

    system("cls");
    int opc = 0;
    while(opc != 5){
        cout << " ------------------------------" << endl;
        cout << "            SUBMENU            " << endl;
        cout << " ------------------------------" << endl;
        cout << " 1. Mostrar productos sin filtro " << endl;
        cout << " 2. Ingresar categoria " << endl;
        cout << " 3. Ingresar nombre del producto " << endl;
        cout << " 4. Ingresar marca" << endl;
        cout << " 5. Volver al menú inventario" << endl;
        cout << " ------------------------------" << endl;
        cout << " Opcion: ";
        cin >> opc;

        switch(opc){
            case 1: productos.listarProductos(); break;
            case 2: busquedaProfunda(); break;
        }


   }

 }

void eliminarProducto(){

}

 void busquedaProfunda(){
    ArchivoCategorias categorias("Categorias.dat");
    ArchivoProductos productos("Productos.dat");

    system("cls");

    char eleccion;
    cout << " Desea ver sola los productos de la categoria. - Si 'S' o No 'N' " << endl;
    cout << " Opcion: ";
    cin >> eleccion;

    if(eleccion == 'S' || eleccion == 's'){

        char opcion[25];

        system("cls");

        cout << " Ingrese el nombre de la categoria: ";
        cin.getline(opcion, 25);
        system("pause");

        if( categorias.validarCategoriaExiste(opcion) ){

            while(categorias.validarCategoriaExiste(opcion)){
                cout << "Ingrese un nombre correcto: ";
                cin.getline(opcion,25);
                system("pause");
            }

        }


        int pos = categorias.obtenerUbicacionCategoria(eleccion);
        Categoria obj = categorias.obtenerCategoria(pos);
        productos.listarProductosCategoria(obj.getId());

        return;
    }
    system("cls");

    char prod[25];
    cout << " Ingrese el nombre del producto: ";
    cin.getline(prod, 25);

    system("pause");

    while(true){

         if( productos.validarNombre(prod) ){
            Producto producto = productos.obtenerProducto(prod);

            if(producto.getEstado()){
                producto.mostrar();
            }else{
                cout << "HA OCURRIDO UN ERROR INESPARADO";
                system("pause");
            }

            return;
        }

        cout << " Ingrese el nombre del producto: ";
        cin.getline(prod, 25);
        system("pause");

    }



 }
