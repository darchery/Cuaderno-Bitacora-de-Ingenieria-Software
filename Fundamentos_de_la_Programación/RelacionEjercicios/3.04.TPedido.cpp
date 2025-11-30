#include <iostream>
#include <array>
#include <math.h>

using namespace std;

struct TFecha{
    int dia;
    int mes;
    int anyo;
};

struct TPedido{
    int codigo;
    string nombre;
    double precio;
    int cantidad;
    TFecha fecha;
};

void leerPedido(TPedido& pedido)
{
    cout << "Introduzca codigo del producto: ";
    cin >> pedido.codigo;

    cout << "Introduzca nombre del producto: ";
    cin >> pedido.nombre;

    cout << "Introduzca precio del producto: ";
    cin >> pedido.precio;

    cout << "Introduzca cantidad pedida: ";
    cin >> pedido.cantidad;

    cout << "Introduzca fecha del pedido: ";
    cin >> pedido.fecha.dia >> pedido.fecha.mes >> pedido.fecha.anyo;
}

void mostrarPedido(TPedido& pedido)
{
    cout << "Codigo del producto: " << pedido.codigo << endl;
    cout << "Nombre del producto: " << pedido.nombre << endl;
    cout << "Precio del producto: " << pedido.precio << endl;
    cout << "Cantidad pedida: " << pedido.cantidad << endl;
    cout << "Fecha del pedido: " << pedido.fecha.dia << ", " << pedido.fecha.mes << ", " << pedido.fecha.anyo << endl;
    cout << "El precio total del pedido es: " << pedido.precio * pedido.cantidad << endl;
}

int main(){
    TPedido pedido1;

    leerPedido(pedido1);
    cout << endl;
    mostrarPedido(pedido1);

    return 0;
}
