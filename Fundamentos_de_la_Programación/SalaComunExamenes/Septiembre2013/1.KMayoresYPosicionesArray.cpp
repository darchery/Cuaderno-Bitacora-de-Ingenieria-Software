#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 5;
const int MAX_REP = 4;

typedef array<int, MAX_REP> TPosiciones;

struct TNumero {
    int numero;
    TPosiciones posiciones;
    int numPos = 0;
};

typedef array<TNumero, MAX> TSecuencia;

struct TLista {
    TSecuencia secuencia;
    int numElem = 0;
};

int buscarIndice(TLista& lista, int num)
{
    int index = -1;
    bool found = false;

    for (int i = 0;i < lista.numElem && !found;i++ )
    {
        if (num == lista.secuencia[i].numero)
        {
            index = i;
            found = true;
        }
    }
    return index;
}

void buscarMenor(TLista& lista, int& menor, int& indexMenor)
{
    menor = lista.secuencia[0].numero;
    indexMenor = 0;

    for (int i = 1;i < lista.numElem ;i++ )
    {
        if (menor > lista.secuencia[i].numero)
        {
            menor = lista.secuencia[i].numero;
            indexMenor = i;
        }
    }
}

void procesarNumero(TLista& lista, int num, int pos)
{
    int indexActual = buscarIndice(lista,num);

    // Vector lleno
    if (lista.numElem == MAX)
    {
        int indexMenor;
        int menor;
        buscarMenor(lista,menor,indexMenor);

        // Ya está
        if (indexActual != -1)
        {
            lista.secuencia[indexActual].posiciones[lista.secuencia[indexActual].numPos] = pos;
            lista.secuencia[indexActual].numPos++;
        }
        // Si es nuevo (no está) y mayor que el menor se intercambian
        else if (indexActual == -1 && num > menor)
        {
            // Reiniciamos vector
            lista.secuencia[indexMenor].posiciones = {{}};
            lista.secuencia[indexMenor].numPos = 0;

            lista.secuencia[indexMenor].numero = num;
            lista.secuencia[indexMenor].posiciones[lista.secuencia[indexMenor].numPos] = pos;
            lista.secuencia[indexMenor].numPos++;
        }
    }
    // Vacio
    else
    {
        // Primera aparicion
        if (indexActual == -1)  // No esta
        {
            /*cout << num << ": " << pos << endl;
            cout << endl;*/
            lista.secuencia[lista.numElem].numero = num;
            lista.secuencia[lista.numElem].posiciones[lista.secuencia[lista.numElem].numPos] = pos;
            lista.secuencia[lista.numElem].numPos++;
            lista.numElem++;

        }
        // Demas apariciones (indexActual != -1)
        else
        {
            /*cout << num << ": " << pos << endl;
            cout << endl;*/
            lista.secuencia[indexActual].posiciones[lista.secuencia[indexActual].numPos] = pos;
            lista.secuencia[indexActual].numPos++;
        }
   }

}

void escribirMayoresM(TLista& lista)
{
    cout << "Los " << lista.numElem << " y sus posiciones: " << endl;
    for (int i = 0;i < lista.numElem ;i++ )
    {
        cout << lista.secuencia[i].numero << ": ";
        for (int j = 0;j < lista.secuencia[i].numPos ;j++ )
        {
            cout << lista.secuencia[i].posiciones[j] << " ";
        }
        cout << endl;
    }
}

int main(){
    TLista lista;
    int M;
    int sec;
    int pos = 1;

    do
    {
        cout << "Introduzca el valor de M: ";
        cin >> M;
    } while (M <= 0);

    cout << "Introduzca una secuencia de numeros acabada en 0: ";
    cin >> sec;
    while (sec != 0)
    {
        procesarNumero(lista,sec,pos);
        pos++;
        cin >> sec;
    }
    escribirMayoresM(lista);
return 0;

}

// 2 3 4 7 28 4 5 1 1 1 9 7 4 4 28 2 1 3 3 6 0
