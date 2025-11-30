#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 10;
typedef array<int, MAX> TArray;

void leerVec(TArray& v)
{
    cout << "Introduzca una lista de " << MAX << " elementos: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cin >> v[i];
    }
}

bool primo(int num)
{
    bool esPrimo = true;

    for (int i = 2;i < num && esPrimo;i++ )
    {
        if (num % i == 0)
        {
            esPrimo = false;
        }
    }
    return esPrimo;
}

int mayorPrimo(TArray& v)
{
    int mayorPrim = 1;


    for (int i = 0;i < MAX ;i++ )
    {
        if (mayorPrim < v[i] && primo(v[i]))
        {
            mayorPrim = v[i];
        }
    }
    return mayorPrim;
}

int main(){
    TArray v1;
    int primoMayor;

    leerVec(v1);
    primoMayor = mayorPrimo(v1);
    if (primoMayor == 1)
    {
        cout << "No hay ningun numero primo" << endl;
    }
    else
    {
        cout << "El mayor numero primo es: " << primoMayor << endl;
    }
return 0;

}
