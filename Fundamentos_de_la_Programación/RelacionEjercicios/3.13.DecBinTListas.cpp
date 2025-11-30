#include <iostream>
#include <array>
#include <math.h>
using namespace std;

const int N = 50;
typedef array<int, N> TNumeroBaseB;

struct TListaNum{
    TNumeroBaseB vectorNums;
    int numeroBase10;
    int base;
};
void intercambiarArray(int& x, int& y)
{
    int aux;

    aux = x;
    x = y;
    y = aux;
}
void leerNumero(TListaNum& lista)
{
    do
    {
        cout << "Introduzca un numero natural en base 10: ";
        cin >> lista.numeroBase10;
    } while (lista.numeroBase10 < 0);

    do
    {
        cout << "Introduzca la base a la que convertirlo (2 <= base <= 9): ";
        cin >> lista.base;
    } while (lista.base < 2 || lista.base > 9);
}

void numBase10aBaseB(TListaNum& lista, int& tamBinario)
{
    //int copiaNum = lista.numeroBase10;
    int index = 0;
    while (lista.numeroBase10 != 0)
    {
        lista.vectorNums[index] = lista.numeroBase10 % lista.base;
        lista.numeroBase10 /= lista.base;
        index++;
    }
    tamBinario = index;

    // ESTO ES MAS SENCILLO QUE ES SIMPLEMENTE IMPRIMIR EL ARRAY AL REVES
    /*int tamNumeroBaseB = index - 1;
    cout << "El numero " << copiaNum << " en base " << lista.base << " es: ";
    for (int j = tamNumeroBaseB ;j >= 0 ;j-- )
    {
        cout << lista.vectorNums[j];
    }*/
}

void invertirArray(TListaNum& lista, int& tamBinario)
{
    for (int i = 0;i < tamBinario/2-1 ;i++ )            /// ESE tam/2-1 es para que solo intercambie la hasta la mitad, si sigue intercambiando todo vueleve a como estaba
    {
        intercambiarArray(lista.vectorNums[i], lista.vectorNums[tamBinario - i - 1]);
    }
}

void escribir(TListaNum lista, int& tamBinario)
{
    cout << "El numero en base " << lista.base << " es: ";
    for (int i = 0;i < tamBinario ;i++ )
    {
        cout << lista.vectorNums[i];
    }

}
int main(){
    TListaNum lista1;
    int tamBinario;

    leerNumero(lista1);
    numBase10aBaseB(lista1, tamBinario);
    invertirArray(lista1, tamBinario);
    escribir(lista1, tamBinario);
return 0;

}

