#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool esCuadradoPerfecto(int num);
int mayorCuadradoPerfecto(int num);

int main(){
    int n;

    cout << "Introduzca una secuencia acabada en cero: ";
    cin >> n;

    int res = mayorCuadradoPerfecto(n);

    if (res == 0)
    {
        cout << "No hay cuadrado perfecto en la secuencia" << endl;
    }
    else
    {
        cout << "El mayor cuadrado perfecto de la secuencia es: " << res << endl;
    }

return 0;

}

int mayorCuadradoPerfecto(int num)
{
    int mayor = 0;
    while (num != 0)
    {
        if (num > mayor && esCuadradoPerfecto(num))
        {
            mayor = num;
        }
        cin >> num;
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

bool esCuadradoPerfecto(int num)
{
    int sumDiv = 0;
    for (int divisores = 1;num > divisores ;divisores++ )
    {
        if (num % divisores == 0)
        {
            sumDiv += divisores;
        }
    }

    if (num == sumDiv)
    {
        return true;
    }
    else
    {
        return false;
    }
}
