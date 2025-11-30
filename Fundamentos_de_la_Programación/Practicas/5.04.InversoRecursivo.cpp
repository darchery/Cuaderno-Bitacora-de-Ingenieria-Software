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

void inverso (int n)
{
    if (n <  10)
    {
        cout << n;          /// SOLO TIENE UN DIGITO
    }
    else
    {
        cout << n%10;
        inverso(n/10);
    }
}

int main() {
    int n;

    leerN(n);
    cout << "El inverso de " << n << " es: ";
    inverso(n);
    return 0;
}
