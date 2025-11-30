#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool esPrimo(int num)
{
    bool primo = true;

    if (num != 2)
    {
        for (int i = 2;i < num && primo;i++ )
        {
            if (num % i == 0)
            {
                primo = false;
            }
        }
    }
    return primo;
}

int mayorPrimo(int sec)
{
    int mayor = 1;

    while (sec != 0)
    {
        if (esPrimo(sec) && mayor < sec)
        {
            mayor = sec;
        }
        cin >> sec;
    }
    return mayor;
}

int main(){
    int sec;
    int mayor;

    cout << "Introduzca una secuencia de enteros positivos acabada en 0: ";
    cin >> sec;
    mayor = mayorPrimo(sec);

    if (mayor == 1)
    {
        cout << "No hay primo en la secuencia" << endl;
    }
    else
    {
        cout << "El mayor primo de la secuencia es: " << mayor << endl;
    }
return 0;

}
