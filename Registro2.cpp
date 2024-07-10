#include <iostream>
#include <string>

using namespace std;

struct Producto{
	
	string nombre;
	float precio;
	
};

struct Venta{
	
	int idVenta;
	string producto;
	int cantidad;
	float precioTotal;
		
};

const int Almacen = 1000;
const int Ventas = 1000;
Producto almacen[Almacen];
Venta ventas[Ventas];
int num_productos = 0;
int num_ventas = 0;

void RegProducto();
void ListProducto();
void BuscarProducto();
void ActualizarProducto();
void EliminarProducto();
void RegVenta();
void ListVent();
void CalcularVentas();

int main(){
	char letter;
	do{
	cout << "Inventario de productos y Ventas" << endl;
	cout << "______________________________________" << endl;
	cout << "a) Registrar un nuevo producto."<< endl;
	cout << "b) Listar los productos registrados." << endl;
	cout << "c) Buscar un producto por nombre." << endl;
	cout << "d) Actualizar los datos de un producto." << endl;
	cout << "e) Eliminar un producto." << endl;
	cout << "f) Registrar una venta." << endl;
	cout << "g) Listar las ventas realizadas." << endl;
	cout << "h) Calcular el total de ventas realizadas." << endl;
	cout << "i) Salir del programa." <<endl;	
	cin >> letter;
	cin.ignore();			
	switch(letter){
		case 'a':
			RegProducto();
			break;
		case 'b':	
			ListProducto();
			break;
		case 'c':	
			BuscarProducto();
			break;
		case 'd':
			ActualizarProducto();
			break;
		case 'e':
			EliminarProducto();
			break;
		case 'f':
			RegVenta();
			break;
		case 'g':
			ListVent();
			break;
		case 'h':
			CalcularVentas();
			break;
		default:	
			break;
		}
	}while(letter != 'i'); 
	
	return 0; 
}
void RegProducto(){
    if (num_productos < Almacen) {
        cout << "Agregando producto" << endl;
        cout << "..................." << endl;
        cout << "Escribe los siguientes datos: " << endl;
        cout << "Nombre Completo del Producto: ";
        getline(cin, almacen[num_productos].nombre);
        cout << "Precio del producto: ";
        cin >> almacen[num_productos].precio;
        num_productos++;
    } else {
        cout << "No se pueden agregar más productos. Límite (1000)." << endl;
    }
    cin.ignore(); 
}

void ListProducto(){
    if (num_productos > 0) {
        cout << "Listado de Productos:" << endl;
        cout << "--------------------" << endl;
        for (int i = 0; i < num_productos; ++i) {
            cout << "Nombre: " << almacen[i].nombre << ", Precio: " << almacen[i].precio << endl;
        }
    } else {
        cout << "No hay productos registrados." << endl;
    }
}
void BuscarProducto(){
    if (num_productos > 0) {
        string nombreBusqueda;
        cout << "Ingrese el nombre del producto a buscar: ";
        getline(cin, nombreBusqueda);
        bool encontrado = false;
        for (int i = 0; i < num_productos; ++i) {
            if (almacen[i].nombre == nombreBusqueda) {
                cout << "Producto encontrado:" << endl;
                cout << "Nombre: " << almacen[i].nombre << ", Precio: " << almacen[i].precio << endl;
                encontrado = true;
                break; 
            }
        }
        if (!encontrado) {
            cout << "No se encontró el producto con el nombre ingresado." << endl;
        }
    } else {
        cout << "No hay productos registrados." << endl;
    }	
}
void ActualizarProducto(){
	    if (num_productos > 0) {
        string nombreActualizar;
        cout << "Ingrese el nombre del producto a actualizar: ";
        getline(cin, nombreActualizar);
        bool encontrado = false;
        for (int i = 0; i < num_productos; ++i) {
            if (almacen[i].nombre == nombreActualizar) {
                cout << "Producto encontrado. Ingrese los nuevos datos:" << endl;
                cout << "Nuevo Nombre del Producto: ";
                getline(cin, almacen[i].nombre);
                cout << "Nuevo Precio del Producto: ";
                cin >> almacen[i].precio;
                encontrado = true;
                cin.ignore(); 
                break; 
            }
        }
        if (!encontrado) {
            cout << "No se encontró el producto con el nombre ingresado." << endl;
        }
    } else {
        cout << "No hay productos registrados." << endl;
    }
}
}
void EliminarProducto(){
    if (num_productos > 0) {
        string nombreEliminar;
        cout << "Ingrese el nombre del producto a eliminar: ";
        getline(cin, nombreEliminar);
        bool encontrado = false;
        for (int i = 0; i < num_productos; ++i) {
            if (almacen[i].nombre == nombreEliminar) {
                for (int j = i; j < num_productos - 1; ++j) {
                    almacen[j] = almacen[j + 1];
                }
                num_productos--;
                encontrado = true;
                cout << "Producto eliminado correctamente." << endl;
                break;
            }
        }
        if (!encontrado) {
            cout << "No se encontró el producto con el nombre ingresado." << endl;
        }
    } else {
        cout << "No hay productos registrados." << endl;
    }
		
}
void RegVenta(){
    if (num_productos > 0) {
        if (num_ventas < Ventas) {
            cout << "Registrando venta" << endl;
            cout << "..................." << endl;
            cout << "Escribe los siguientes datos: " << endl;
            ventas[num_ventas].idVenta = num_ventas + 1;
            cout << "Nombre del Producto vendido: ";
            getline(cin, ventas[num_ventas].producto);
            cout << "Cantidad vendida: ";
            cin >> ventas[num_ventas].cantidad;
            for (int i = 0; i < num_productos; ++i) {
                if (almacen[i].nombre == ventas[num_ventas].producto) {
                    ventas[num_ventas].precioTotal = almacen[i].precio * ventas[num_ventas].cantidad;
                    break;
                }
            }
            num_ventas++;
        } else {
            cout << "No se pueden registrar más ventas. Límite alcanzado (1000)." << endl;
        }
        cin.ignore();
    } else {
        cout << "No hay productos registrados para realizar ventas." << endl;
    }

}
void ListVent(){
    if (num_ventas > 0) {
        cout << "Listado de Ventas:" << endl;
        cout << "-----------------" << endl;
        for (int i = 0; i < num_ventas; ++i) {
            cout << "ID de Venta: " << ventas[i].idVenta << endl;
            cout << "Producto: " << ventas[i].producto << endl;
            cout << "Cantidad: " << ventas[i].cantidad << endl;
            cout << "Precio Total: " << ventas[i].precioTotal << endl;
            cout << "-----------------" << endl;
        }
    } else {
        cout << "No hay ventas registradas." << endl;
    }	
}
void CalcularVentas(){
    if (num_ventas > 0) {
        float totalVentas = 0.0;
        for (int i = 0; i < num_ventas; ++i) {
            totalVentas += ventas[i].precioTotal;
        }
        cout << "El total de ventas realizadas es: " << totalVentas << endl;
    } else {
        cout << "No hay ventas registradas." << endl;
    }
}
