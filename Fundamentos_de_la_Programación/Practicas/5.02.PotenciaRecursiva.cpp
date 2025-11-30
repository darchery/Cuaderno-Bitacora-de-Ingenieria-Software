#include <iostream>
using namespace std;

void leerPow(int& x, int& n)
{
    do
    {
        cout << "Introduzca una base seguida del exponente: ";
        cin >> x >> n;
    } while (x < 0 || n < 0);
}

int potencia(int x, int n)
{
    int res;

    if (n == 0)
    {
        res = 1;
    }
    else
    {
        res = x * potencia(x, n-1);

    }
    return res;
}

int main() {
    int x, n;

    leerPow(x,n);
    cout << x << " elevado a " << x << " es: " << potencia(x,n) << endl;
    return 0;
}
