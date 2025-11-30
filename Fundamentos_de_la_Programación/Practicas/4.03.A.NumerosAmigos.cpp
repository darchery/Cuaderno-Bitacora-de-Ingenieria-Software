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

bool sonAmigos(int a, int b)
{
    bool amigos = false;
    int divA = 1;
    int divB = 1;

    for (int div = 2;div < a ;div++ )
    {
        if (a % div == 0)
        {
            divA += div;
        }
    }
    for (int div = 2;div < b ;div++ )
    {
        if (b % div == 0)
        {
            divB += div;
        }
    }
    if (divA == b && divB == a)
    {
        amigos = true;
    }
    return amigos;
}

int main() {
    int a, b;

    leer(a,b);
    if (sonAmigos(a,b))
    {
        cout << a << " y " << b << " son amigos" << endl;
    }
    else
    {
        cout << a << " y " << b << " NO son amigos" << endl;
    }
    return 0;
}
