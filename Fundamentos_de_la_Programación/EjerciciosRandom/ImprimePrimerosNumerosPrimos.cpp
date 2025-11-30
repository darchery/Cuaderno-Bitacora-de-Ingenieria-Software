#include <iostream>
#include <array>
#include <math.h>

void primerosNumerosPrimos(int num);
bool esPrimo(int n);

using namespace std;

int main(){
    int n;

    cout << "Introduzca un numero(>0): ";
    cin >> n;

    if (n <= 0)
    {
        cout << "ERROR: numero menor o igual que cero introducido" << endl;
    }
    else
    {
        cout << "Los primeros " << n << " primos son ";
        primerosNumerosPrimos(n);
    }
return 0;

}

void primerosNumerosPrimos(int num)
{
    int numeroPrimo = 2;
    while (num > 0)
    {
        if (esPrimo(numeroPrimo))
        {
            cout << numeroPrimo <<" ";
            num--;
        }
        numeroPrimo++;
    }
    cout << ".";
}

bool esPrimo(int n)
{
    int cnt = 0;
    bool primo = false;
    for (int div = 1;div <= n ;div++ )
    {
        if (n % div == 0)
        {
            cnt++;
        }
    }
    if (cnt == 2)
    {
        primo = true;
    }
    return primo;
}
