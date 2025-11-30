#include <iostream>
using namespace std;

void leerN(int& n)
{
    do
    {
        cout << "Introduzca un numero(>0): ";
        cin >> n;
    } while (n <= 0);
}

int sumaNaturales(int n)
{
    int suma;

    if (n == 1)
    {
        suma = 1;
    }
    else
    {
        suma = n + sumaNaturales(n-1);
    }
    return suma;
}

int main() {
    int n;

    leerN(n);
    cout << "La suma desde el 1 hasta " << n << " es: " << sumaNaturales(n);
    return 0;
}
