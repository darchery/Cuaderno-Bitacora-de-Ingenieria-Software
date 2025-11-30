#include <iostream>
#include <array>
#include <math.h>

/*
Diseñe un algoritmo que lea de teclado un número natural M (mayor que 0 y menor o
igual que un valor MAX constante conocido). A continuación este algoritmo leerá una
sucesión indefinida de números naturales acabada en 0.

1. El algoritmo debe mostrar los M valores mayores de la sucesión,
2. así como la posición en que aparecen cada uno de ellos dentro de la misma.
3. En la sucesión cada número puede aparecer repetido un número máximo MAX_REP de veces.
4. Si el número de elementos de la sucesión es menor que M, el algoritmo mostrará todos los valores y sus posiciones.

2 partes:
Si el numero de elementos es mayor o igual a M , imprimiremos los M elementos mayores con sus posiciones
Si numero de elementos es menor que M, imprimiremos TODOS los elementos con sus posiciones
*/

using namespace std;

const int MAX = 5;
const int MAX_REP =4;
const int N = 100;

typedef array<int ,N> TVector;

struct TLista {
    TVector vec;
    int tamVec = 0;
};

void leerMSec(TLista& lista, int& M)
{
    int sec;
    do
    {
        cout << "Introduzca el valor de M: ";
        cin >> M;
    } while (M <= 0 || M > MAX);

    cout << "Introduzca una secuencia de numeros acabada en 0: ";
    cin >> sec;
    while (sec != 0)
    {
        lista.vec[lista.tamVec] = sec;
        lista.tamVec++;
        cin >> sec;
    }
}

// Si los numeros se repiten mas de 4 veces no se imprimen
bool masDe4Repes(TLista& lista, int num)
{
    int cntRepes = 0;
    bool mas4 = false;

    for (int i = 0;i < lista.tamVec ;i++ )
    {
        if (lista.vec[i] == num)
        {
            cntRepes++;
        }
    }
    if (cntRepes >= 4)
    {
        mas4 = true;
    }
    return mas4;
}

int calcularMaximos(TLista& lista)
{
    int maximo = lista.vec[0];

    for (int i = 1;i < lista.tamVec ;i++ )
    {
        if (maximo < lista.vec[i])
        {
            maximo = lista.vec[i];

        }
    }
    return maximo;
}

void imprimirPosiciones(TLista& lista, int num)
{
    cout << num << ": ";
    for (int i = 0;i < lista.tamVec ;i++)
    {
        if (lista.vec[i] == num)
        {
            cout << i + 1 << " ";
            lista.vec[i] = -1;
        }
    }
     cout << endl;
}


void mayoresPos(TLista& lista, int M)
{
    // Num. elementos menor que M
    if (lista.tamVec < M)
    {
        cout << "Los mayores y sus posiciones son: " << endl;
        for (int i = 0;i < lista.tamVec ;i++ )
        {
            if (lista.vec[i] > 0 && !masDe4Repes(lista, lista.vec[i]))
            {
                imprimirPosiciones(lista, lista.vec[i]);
            }
        }
    }
    // Ejecucion normal
    else
    {
        int cnt = 0;
        for (int i = 0;i < lista.tamVec && cnt < MAX;i++ )
        {
            if (lista.vec[i] > 0)
            {
                imprimirPosiciones(lista, calcularMaximos(lista));
                cnt++;
            }
        }
    }
}

int main(){
    TLista lista1;
    int M;

    leerMSec(lista1, M);
    mayoresPos(lista1, M);
return 0;

}
