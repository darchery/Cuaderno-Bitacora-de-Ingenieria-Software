#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 10;
typedef array<int, MAX> TArray;

void leerV(TArray& v)
{
    cout << "Introduzca " << MAX << " numeros naturales: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cin >> v[i];
    }
}

int mayorLongitud(TArray& v)
{
    int mayorLong = 0;
    int mayorLongAnterior = 0;
    int numActual = v[0];

    for (int i = 1;i < MAX ;i++ )
    {
        if (numActual <= v[i])
        {
            mayorLong++;
        }
        else
        {
            mayorLong = 0;
        }

        if (mayorLong > mayorLongAnterior)
        {
            mayorLongAnterior = mayorLong;
        }
        numActual = v[i];
    }
    mayorLongAnterior++;        // Le sumo uno mas porque la long empieza en cero, y no pasa de long 1 a 2 y luego a 3 etc, sino que pasa de logn = 0 a long = 1 + 0
    return mayorLongAnterior;   // EJ: 34 2 43 43 333, del 2 al 43, la distancia es 2, pero el cnt empieza en 0 so cnt++; = cnt =1 , le sumamos uno al final para adecuar eso
}

int main(){
    TArray v1;

    leerV(v1);
    cout << "La longitud de la mayor sub-sucesion es: " << mayorLongitud(v1) << endl;
return 0;

}
