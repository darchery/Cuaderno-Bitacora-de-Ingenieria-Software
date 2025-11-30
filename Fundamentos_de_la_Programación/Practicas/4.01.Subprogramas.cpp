#include <iostream>
using namespace std;

void leer (int& a, int& b)
{
    do
    {
        cout << "Introduzca 2 numeros: ";
        cin >> a >> b;
    } while (a <= 0 || b <= 0);
}

void ordenar(int& a, int& b)
{
    int aux;
    if (a > b)
    {
        aux = a;
        a = b;
        b = aux;
    }
}

double factorial(int n)
{
    double fact = 1;
    for (int i = 1;i <= n ;i++ )
    {
        fact *= i;
    }
    return fact;
}

double potencia(int base, int exp)
{
    int res = 1;
    for (int i = 0;i < exp ;i++ )
    {
        res *= base;
    }
    return res;
}

double termino(int a, int b)
{
    return potencia(b,a) / factorial(a);
}

void mostrar(double t)
{
    cout << "El resultado es: " << t << endl;
}

int main() {
    int a, b;
    double res;

    leer(a,b);
    ordenar(a,b);
    res = termino(a,b);
    mostrar(res);

    return 0;
}
