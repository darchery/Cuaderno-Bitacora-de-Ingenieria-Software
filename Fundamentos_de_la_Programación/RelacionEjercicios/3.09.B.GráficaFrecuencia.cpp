#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int const N = 10;
typedef array<int, N> TFrecuencia;

void leerFrecYCalc(TFrecuencia& frecuencia, int& maxFrec)
{
    int num;
    cout << "Introduzca una secuncia de numeros acabada en uno negativo: ";
    cin >> num;

    while (num >= 0)
    {
        frecuencia[num]++;
        if (maxFrec < frecuencia[num])
        {
            maxFrec = frecuencia[num];
        }
        cin >> num;
    }
}

void imprimirFrec(TFrecuencia& frecuencia, int& maxFrec)
{
    maxFrec = 0;
    for (int i = 0; i < 19 ;i++ )
    {
        cout << "-";
    }
    cout << endl;

    for (int i = maxFrec; i > 0 ;i-- )
    {
        for (int j = 0;j < N ;j++ )
        {
            if (frecuencia[j] == maxFrec)
            {
                cout << "* ";
                frecuencia[j]--;
            }
            else
            {
                cout << "  ";
            }
        }
        maxFrec--;
        cout << endl;
    }
    for (int i = 0; i < 19 ;i++ )
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0;i < N ;i++ )
    {
        cout << i << " ";
    }
}

int main(){
    TFrecuencia frecuencia1 = {{0}};
    int maxFrec;

    leerFrecYCalc(frecuencia1, maxFrec);
    imprimirFrec(frecuencia1, maxFrec);
return 0;

}
