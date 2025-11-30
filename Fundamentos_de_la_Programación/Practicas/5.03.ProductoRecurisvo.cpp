#include <iostream>
using namespace std;

void leerProducto(int& x, int& y)
{
    do
    {
        cout << "Introduzca una base seguida del exponente: ";
        cin >> x >> y;
    } while (x < 0 || y < 0);
}

int producto(int x, int y)
{
    int res;

    if (y == 0 || x == 0)
    {
        res = 0;
    }
    else
    {
        res = x + producto(x,y-1);
    }
    return res;
}

int main() {
    int x, y;
    int aux;

    leerProducto(x,y);
    if (x < y)          /// ESTE INTERCAMBIO ES POR EFICIENCIA
    {                   /// YA QUE NO ES LO MISMO SUMAR 22 3 VECES
        aux = x;        /// QUE SUMAR 3 22 VECES
        x = y;
        y = aux;
    }
    cout << x << " * " << y << " es: " << producto(x,y);
    return 0;
}
