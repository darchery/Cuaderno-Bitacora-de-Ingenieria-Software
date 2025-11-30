#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 10;

void leerK(int& k)
{
    do
    {
        cout << "Introduzca un termino k mayor que 0: ";
        cin >> k;
    } while (k <= 0);
}

int sumaDivisores(int num)
{
    int suma = 0;

    for (int i = 1;i < num ;i++ )
    {
        if (num % i == 0)
        {
            suma += i;
        }
    }
    return suma;
}

void sucesionAlicuota(int& k)
{
    int ciclos = 0;

    if (sumaDivisores(k) == k)
    {
        cout << "La secuencia alicuota es infinita" << endl;
    }
    else
    {
        cout << "La secuencia alicuota es: ";
        while (ciclos < MAX && k != 1)
        {
            cout << sumaDivisores(k) << " ";
            k = sumaDivisores(k);
            ciclos++;
        }
        if (ciclos == MAX)
        {
            cout << "La secuencia alicuota es infinita" << endl;
        }
    }
}

int main(){
    int k;

    leerK(k);
    sucesionAlicuota(k);
return 0;

}
