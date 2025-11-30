#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void masNumeroPosNeg(int secuencia);

int main(){
    int secuencia;

    cout << "Introduzca una secuencia acabada en cero: ";
    cin >> secuencia;
    masNumeroPosNeg(secuencia);
return 0;

}

void masNumeroPosNeg(int secuencia)
{
    int cntPos = 0, cntNeg = 0;
    while (secuencia != 0 )
    {
        if (secuencia > 0)
        {
            cntPos++;
        }
        else
        {
            cntNeg++;
        }
        cin >> secuencia;
    }

    if (cntPos > cntNeg)
    {
        cout << "Hay MAS numeros Positivos que negativos, en concreto " << cntPos << endl;
    }
    else if (cntPos < cntNeg)
    {
        cout << "Hay MAS numeros Negativos que positivos, en concreto " << cntNeg << endl;
    }
    else
    {
        cout << "Hay igual numeros positivos que negativos, en concreto " << cntPos << endl;
    }

}
