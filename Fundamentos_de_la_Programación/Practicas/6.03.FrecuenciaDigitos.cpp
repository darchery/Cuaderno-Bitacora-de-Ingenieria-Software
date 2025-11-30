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
    cout << "La frencuencia de cada digito es: " << endl;;
    for (int i = 0;i < DIGITOS ;i++ )
    {
        cout << i << ": " << frec[i] << endl;
    }
}

int main()
{
    TFrecuencia frec = {{0}};

    leerDigitosCalcFrec(frec);
    return 0;
}
