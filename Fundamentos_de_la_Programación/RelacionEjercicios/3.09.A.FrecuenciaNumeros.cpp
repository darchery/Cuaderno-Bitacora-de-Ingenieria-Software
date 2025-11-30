#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int const N = 10;
typedef array<int, N> TFrecuencia;

void leerFrecYCalc(TFrecuencia& frecuencia)
{
    int num;
    cout << "Introduzca una secuncia de numeros acabada en uno negativo: ";
    cin >> num;

    while (num >= 0)
    {
        frecuencia[num]++;
        cin >> num;
    }
}

void imprimirFrec(TFrecuencia& frecuencia)
{
    cout << "La frecuencia de cada dígito es: " << endl;
    for (int i = 0;i < N ;i++ )
    {
        cout << i << ": " << frecuencia[i] << endl;
    }
}

int main(){
    TFrecuencia frecuencia1 = {{0}};

    leerFrecYCalc(frecuencia1);
    imprimirFrec(frecuencia1);
return 0;

}
