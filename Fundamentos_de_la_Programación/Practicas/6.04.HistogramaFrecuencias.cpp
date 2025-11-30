#include <iostream>
#include <array>

using namespace std;

const int DIGITOS = 10;
typedef array<int, DIGITOS> TFrecuencia;

void leerDigitosCalcFrec(TFrecuencia& frec)
{
    int digito;
    cout << "Introduzca una secuencia de digitos (negativo termina): ";
    cin >> digito;
    while (digito >= 0 && digito <= 9)
    {
        frec[digito]++;
        cin >> digito;
    }
}

int calcMaxFrec(TFrecuencia& frec)
{
    int maxFrec = 0;

    for (int i = 0;i < DIGITOS ;i++ )
    {
        if (maxFrec < frec[i])
        {
            maxFrec = frec[i];
        }
    }
    return maxFrec;
}

void escribir(TFrecuencia& frec, int maxFrec)
{
    while (maxFrec >  0)
    {
        for (int i = 0;i < DIGITOS ;i++ )
        {
            if (maxFrec == frec[i])
            {
                cout << "* ";
                frec[i]--;
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
        maxFrec--;
    }

    for (int i = 0;i < DIGITOS ;i++ )
    {
        cout << i << " ";
    }
}

int main()
{
    TFrecuencia frec = {{0}};
    int maxFrec;

    leerDigitosCalcFrec(frec);
    maxFrec = calcMaxFrec(frec);
    escribir(frec, maxFrec);
    return 0;
}
