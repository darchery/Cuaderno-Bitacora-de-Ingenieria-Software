#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 5;
typedef array<int, MAX> TVector;

struct TLista {
    TVector vec;
    int tamVec = 0;
};

void leerListas(TLista& lista)
{
    int num;

    cout << "Introduzca la lista: ";
    cin >> num;
    while (num > 0 && lista.tamVec < MAX)
    {
        lista.vec[lista.tamVec] = num;
        lista.tamVec++;
        cin >> num;
    }

}

void imprimirListas(TLista& lista, int n)
{
    cout << "lista" << n << ": ";
    for (int i = 0;i < lista.tamVec; i++ )
    {
            cout << lista.vec[i] << " ";
    }
}

/*
Mi intento era coger el primero numero guardarlo en una variable junto a su futuro index,
tambien guardar el numero por el que lo vamos a intercambiar y su futuro index(index del otro numero)
EJ: 2 5 1 4, 2 se va a mover 6 veces, 2 tiene index 0, y si se mueve 6 veces quedará en 6 - 4 = 2
en index 2, donde está 1 , asi que pondremos a 2 en index 2 y a 1 en index 0
Y al ser par este intercambio solo habria que hacerlo 2 veces , basicamente TAMVEC / 2 si es par
Y TAMVEC/2 + 1 si es impar
Despues pasaria al siguiente  numero siempre y cuando no se haya usado
*/

void rotaciones(TLista lista, int numRots)
{
    int numAnt;
    int numAct;
    int indexFutu;
    int indexAct = 0;

    for (int i = 0;i < lista.tamVec / 2 ;i++ )
    {
        numAct = lista.vec[indexAct];
        indexFutu = numRots + lista.tamVec;
        numAnt = lista.vec[indexFutu];
        lista.vec[indexAct] = numAnt;
        lista.vec[indexFutu] = numAct;
    }
}

void analizar(TLista& lista1, TLista& lista2, int numRots)
{

    imprimirListas(lista1, 1);
    cout << endl;
    imprimirListas(lista2, 2);

    cout << endl;
    cout << "Tras las " << numRots << " rotaciones: " << endl;
    rotaciones(lista1, numRots);
    rotaciones(lista2, numRots);

    imprimirListas(lista1, 1);
    cout << endl;
    imprimirListas(lista2, 2);
}

int main(){
    TLista lista1, lista2;
    int numRots;

    do
    {
        cout << "Introduzca el numero de rotaciones: ";
        cin >> numRots;
    } while (numRots < 0);
    leerListas(lista1);
    leerListas(lista2);
    analizar(lista1, lista2, numRots);
return 0;

}
