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
    int res;

    if (k == 1)
    {
        cout << "Es una sucesion alicuota" << endl;
    }
    else if (sumaDivisores(k) == k)
    {
        cout << "Es una sucecion alicuota infinita" << endl;
    }
    else
    {
        res = sumaDivisores(k);
        cout << res << " ";
        sucesionAlicuota(res);
    }
}

int main(){
    int k;

    leerK(k);
    sucesionAlicuota(k);
return 0;

}
