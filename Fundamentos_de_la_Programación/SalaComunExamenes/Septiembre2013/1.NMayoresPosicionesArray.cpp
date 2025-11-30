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

    if (lista.numElem == MAX)
    {
        int indexMenor;
        int menor;
        buscarMenor(lista,menor,indexMenor);

        cout << menor << " se intercambia por  " <<  num << endl;
        // Si ya esta y se suma a una posicion
        if (indexActual != -1)
        {
            lista.secuencia[indexActual].posiciones[lista.secuencia[indexActual].numPos] = pos;
            lista.secuencia[indexActual].numPos++;
        }
        // Si no esta y es mayor que menor se intercambia por este y se actualiza su array pos
        else if (indexActual == -1 && num > menor)
        {
            // Limpiar array
            lista.secuencia[indexMenor].posiciones = {{0}};
            lista.secuencia[indexMenor].numPos = 0;

            // Poner nuevo numero
            lista.secuencia[indexMenor].numero = num;
            lista.secuencia[indexMenor].posiciones[lista.secuencia[indexMenor].numPos] = pos;
            lista.secuencia[indexMenor].numPos++;
        }
        // Si no esta pero es menor  No se hace nada
    }
    else
    {
        //Primera aparicion
        if (indexActual != -1)
        {
            cout << num << " " << indexActual << endl;
            lista.secuencia[lista.numElem].numero = num;
            lista.secuencia[lista.numElem].posiciones[lista.secuencia[lista.numElem].numPos] = pos;
            lista.secuencia[lista.numElem].numPos++;
            lista.numElem++;
        }
        // Demas apariciones
        else
        {
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
    } while (M > MAX || M <= 0);

    cout << "Introduzca una secuencia de numeros acabada en 0: ";
    cin >> sec;
    while (sec != 0)
    {
        procesarNumero(lista,sec,pos);
        pos++;
        cin >> sec;
    }

    /*if (lista.numElem <= M)
    {

    }
    else
    {*/
        escribirMayoresM(lista);
    //}
return 0;

}

// 2 3 4 7 28 4 5 1 1 1 9 7 4 4 28 2 1 3 3 6 0
