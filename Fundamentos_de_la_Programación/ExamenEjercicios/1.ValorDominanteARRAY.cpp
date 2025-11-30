#include <iostream>
#include <array>
#include <math.h>

/*
El valor dominante de un array de naturales es el elemento que se repite un número de veces
mayor que la mitad del tamaño del array
*/

using namespace std;

const int MAX = 10;
typedef array<int, MAX> TArray;

void leerV(TArray& v)
{
    cout << "Introduzca una lista de " << MAX << " elementos: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cin >> v[i];
    }
}

int repeticiones(TArray& v, int num)
{
    int repes = 0;

    for (int i = 0;i < MAX ;i++ )
    {
        if (num == v[i])
        {
            repes++;
        }
    }
    return repes;
}

int valorDominante(TArray& v)
{
    int domVal = -1;

    for (int i = 0;i < MAX ;i++ )
    {
        if (repeticiones(v,domVal) < repeticiones(v, v[i]) && repeticiones(v, v[i]) > (MAX/2) )
        {
            domVal = v[i];
        }
    }
    return domVal;
}

int main(){
    TArray v1;

    leerV(v1);
    cout << "El valor dominante es: " << valorDominante(v1) << endl;
return 0;

}
