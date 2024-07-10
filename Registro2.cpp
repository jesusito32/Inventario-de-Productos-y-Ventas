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
        cout << "No se pueden agregar m�s productos. L�mite (1000)." << endl;
    }
    cin.ignore(); 
}

void ListProducto(){
}
void BuscarProducto(){
}
void ActualizarProducto(){
}
void EliminarProducto(){
}
void RegVenta(){
}
void ListVent(){
}
void CalcularVentas(){
}