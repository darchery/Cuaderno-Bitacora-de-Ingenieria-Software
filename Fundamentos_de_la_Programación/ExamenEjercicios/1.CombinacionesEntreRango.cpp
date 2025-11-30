#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void combinaciones(int minimo, int maximo);
void combinacionesCompletas(int minimo, int maximo);

int main(){
    int minimo, maximo;

    do
    {
        cout << "Introduzca un minimo y un maximo: ";
        cin >> minimo >> maximo;

    } while (minimo > maximo);

    cout << "Combinaciones sin repetir: " << endl;
    combinaciones(minimo, maximo);

    cout << "\n";

    cout << "Combinaciones repetidas(COORDENADAS): " << endl;
    combinacionesCompletas(minimo,maximo);
return 0;

}

void combinacionesCompletas(int minimo, int maximo)
{
    for (int n1 = minimo;n1 <= maximo ;n1++ )
    {
        for (int n2 = minimo;n2 <= maximo ;n2++ )
        {
            cout << "(" << n1 << "," << n2 << ")" << endl;
        }
    }
}

void combinaciones(int minimo, int maximo)
{
    int antMin = minimo;
    while (minimo < maximo)
    {
        cout << "(" << minimo << "," << maximo << ")" << endl;
        minimo++;
        //cout << "Min: " << minimo << endl;
        //cout << "Max: " << maximo << endl;
        if (minimo == maximo)
        {
            maximo--;
            minimo = antMin;
        }
    }
}

