#include <iostream>
using namespace std;

#include "DetalleTransaccion.h"

#include "../archivos/Productos.h"
#include "../archivos/DetallesVentas.h"

void DetalleTransaccion::setId(int id){
    _setId = id;
};

void DetalleTransaccion::setIdTransaccion(int id){
    _setIdTransaccion = id;
};

void DetalleTransaccion::setIdProducto(int id){
    _setIdProducto = id;
};

void DetalleTransaccion::setCantidad(int cant){
    _cantidad = cant;
};

void DetalleTransaccion::setPrecioUnitario(float prec){
    _precioUnitario = prec;
};

int DetalleTransaccion::getId(){
    return _id;
};

int DetalleTransaccion::getIdTransaccion(){
    return _idTransaccion;
};

int DetalleTransaccion::getIdProducto(){
    return _idProducto;
};

int DetalleTransaccion::getCantidad(){
    return _cantidad;
};

float DetalleTransaccion::getPrecioUnitario(){
    return _precioUnitario;
};

void DetalleTransaccion::cargar(int idTransaccion){

    if(idTransaccion <= 0){
        cout << "ERROR, FALTA ID DE TRANSACCIÓN" << endl;
        system("pause");
        return;
    }

    ArchivoProductos archivo("Productos.dat");
    Producto producto;

    /// ACÁ HAY QUE PONER EL ID DE DETALLE DE VENTA (ID a secas)
    /// archivoDetalles.generarNuevoID();

    producto.setIdTransaccion(idTransaccion);

    cout << "ID de producto: ";
    cin >> _idProducto;

    while(!archivo.validarExistencia(_idProducto)){
        cout << "Producto inexistente u agotado" << endl;
        cout << "Ingrese otro: ";
        cin >> _idProducto;
    }

    producto = archivo.asignarProducto(archivo.buscarRegistro(_idProducto));
    _precioUnitario = producto.getPrecioUnitario();
    cout << "PRECIO UNITARIO DEL PRODUCTO: " << _precioUnitario << endl;
    cout << "STOCK DISPONIBLE: " << producto.getCantidad() << endl;

    cout << "CANTIDAD DEL PRODUCTO: ";
    cin >> _cantidad;

    while (_cantidad <= 0 || _cantidad > producto.getCantidad()) {
    if (_cantidad <= 0) {
        cout << "La cantidad de producto no puede ser cero o negativa." << endl;
        } else if (_cantArticulo > articulo.getStock()) {
        cout << "Cantidad ingresada mayor al stock disponible." << endl;
        }
        cout << "CANTIDAD DE PRODUCTO: ";
        cin >> _cantArticulo;
    }
    archivo.actualizarStock(_idProducto, _cantidad);
}

void DetalleTransaccion::Mostrar(){
    cout << endl;
    cout << "-------------------" << endl;
    cout << "ID Detalle: " << _id; << endl;
    cout << "ID Articulo: " << _idProducto << endl;
    cout << "Precio unitario: " << _precioUnitario << endl;
    cout << "Cantidad: " _cantidad << endl;
    cout << "-------------------" << endl;
    cout << endl;
}
