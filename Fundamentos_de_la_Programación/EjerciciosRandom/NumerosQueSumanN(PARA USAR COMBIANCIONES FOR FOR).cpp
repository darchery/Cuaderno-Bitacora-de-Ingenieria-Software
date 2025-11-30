#include <iostream>
#include <array>
#include <math.h>

// EN ESTE PROGRAMA QUIERO DESARROLAR LA PRUEBA DE COMBINACIONES ENTRE 2 NUMEROS EN  ESTE CASO SUMANDOLOS
// PARA ELLO USARÉ DOS BUCLES FOR ANIDADOS, NO SE SI ESTA ESTO ES LO MAS EFICIENTE, PERO ES PARA PROBAR ESTA MECANICA

using namespace std;

bool sumanN(int num ,int N);
void analizarIntervalo(int n ,int m);

int main(){
    int n, m;

    do
    {
        cout << "Introduzca un minimo y un maximo: ";
        cin >> n >> m;

    } while (n > m);
    analizarIntervalo(n,m);
return 0;

}

void analizarIntervalo(int n ,int m)
{
    for (int i = n;i < m ;i++ )
    {
        if (sumanN(i,m))
        {
            sumanN(i,m);
        }
    }
}

bool sumanN(int num,int N)
{
    bool ok = false;

    for (int sum1 = 1;sum1 <= N ;sum1++ )
    {
        for (int sum2= 1;sum2 <= N ;sum2++ )
        {
            if (sum1 + sum2 == N)
            {
                cout << "Suma1: " << sum1 << endl;
                cout << "Suma2: " << sum2 << endl;
                cout <<"\n";*/
                ok = true;
            }
        }
    }
    return ok;
}
