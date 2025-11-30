#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool esPrimo(int num);
int mayorPrimo(int num);

int main(){
    int n;

    cout << "Introduzca una secuencia: ";
    cin >> n;

    int res = mayorPrimo(n);

    if (res != 0)
    {
        cout << "El mayor primo de la secuencia es: " << res << endl;

    }
    else
    {
        cout <<"No hay ningun primo en la secuecia" << endl;
    }
return 0;

}

int mayorPrimo(int num)
{
    int mayor = 0;
    if (num == 0)
    {
        cout << "Secuencia vacia" << endl;
    }
    else
    {
        while (num != 0)
        {
            if (num > mayor && esPrimo(num))
            {
                mayor = num;
            }
            cin >> num;
        }
    }
    if (mayor == 0)
    {
        return 0;
    }
    else
    {
        return mayor;
    }

}

bool esPrimo(int num)
{
    int cnt = 0;

    for (int divisores = 2;divisores <= num ;divisores++)
    {
        if (num % divisores == 0)
        {
            cnt++;
        }
    }

    if (cnt == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


