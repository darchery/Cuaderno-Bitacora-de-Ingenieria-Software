#include <iostream>
using namespace std;

bool esPrimo(int N)
{
    bool primo = true;
    for (int div = 2;div < N ;div++ )
    {
        if (N % div == 0)
        {
            primo = false;
        }
    }
    return primo;
}

int main() {
    int N;
    int primo = 2;

    do
    {
        cout << "Introduzca un numero(>0): ";
        cin >> N;
    } while (N <= 0 );

    while (primo < N)
    {
        if (esPrimo(primo))
        {
            cout << primo << " ";
        }
        primo++;
    }

    return 0;
}
