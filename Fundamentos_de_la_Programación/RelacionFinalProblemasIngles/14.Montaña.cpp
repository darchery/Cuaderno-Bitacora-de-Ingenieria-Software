#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N = 10;
typedef array<int, N> TAlturas;

void leerVec(TAlturas& alturas)
{
    for (int i = 0;i < N ;i++ )
    {
        cin >> alturas[i];
    }
}

void picosVector(const TAlturas& alturas ,TAlturas& picos, int& numPicos)
{
    // Extremo inical
    if (alturas[0] > alturas[1])
    {
        picos[numPicos] = 0;
        numPicos++;
    }
    // Picos entre medio
    for (int i = 1;i < N - 1 ;i++ )
    {
        if (alturas[i] > alturas[i-1] && alturas[i] > alturas[i+1])
        {
            picos[numPicos] = i;
            numPicos++;
        }
    }
    // Extremo final
    if (alturas[N-1] > alturas[N-2])
    {
        picos[numPicos] = N-1;
        numPicos++;
    }
}

void mayoresDistancias(const TAlturas& picos, TAlturas& distancias, int& numDistancias, int numPicos)
{
    for (int i = 1;i < numPicos ;i++ )
    {
        distancias[numDistancias] = picos[i] - picos[i-1];
        numDistancias++;
    }
}

int main(){
    TAlturas alturas;
    TAlturas picos;
    TAlturas distancias;
    int numPicos = 0;
    int numDistancias = 0;

    cout << "Introduzca una lista de alturas para encontrar los picos: " << endl;
    leerVec(alturas);
    picosVector(alturas,picos,numPicos);
    cout << "Hay " << numPicos << " picos, que estan en: ";
    for (int i = 0;i < numPicos ;i++ )
    {
        cout << picos[i] << " ";
    }
    cout << endl;
    mayoresDistancias(picos, distancias, numDistancias, numPicos);
    cout << "Hay " << numDistancias << ", las cuales son: ";
    for (int i = 0;i < numDistancias ;i++ )
    {
        cout << distancias[i] << " ";
    }
return 0;

}

// 5 3 2 1 3 6 4 4 5 3
// 0 5 8
