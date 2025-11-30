#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAXPAL = 30;
const int MAX_REP_PALS = 10;

typedef array<int, MAX_REP_PALS> TPosiciones;

struct TDatos {
    string palabra;
    TPosiciones posiciones;
    int numPos = 0;
};

typedef array<TDatos, MAXPAL> TRepetidas;

struct TLista {
    TRepetidas texto;
    int numPals = 0;
};

void esta(TLista& lista, string palabra, int posAct, bool& siEsta, int& posRepetido)
{
    siEsta = false;
    posRepetido = 0;

    for (int i = posAct - 1;i >= 0 && !siEsta;i-- )
    {
        if (lista.texto[i].palabra == palabra)
        {
            siEsta = true;
            posRepetido = i;
        }
    }
}

void procesarPalabras(TLista& lista, string palabra, int pos)
{
    bool siEsta;
    int posRepetido;

    esta(lista,palabra,lista.numPals,siEsta,posRepetido);
    if (!siEsta)
    {
        lista.texto[lista.numPals].palabra = palabra;
        lista.texto[lista.numPals].posiciones[lista.texto[lista.numPals].numPos] = pos;
        lista.texto[lista.numPals].numPos++;
        lista.numPals++;
    }
    else
    {
        lista.texto[posRepetido].posiciones[lista.texto[posRepetido].numPos] = pos;
        lista.texto[posRepetido].numPos++;
    }
}

int mayorDistancia(TLista& lista, int indexPal)
{
    int mayorDist = lista.texto[indexPal].posiciones[1] - lista.texto[indexPal].posiciones[0];
    int distProvisional;

    for (int i = 2;i < lista.texto[indexPal].numPos ;i++ )
    {
        distProvisional = lista.texto[indexPal].posiciones[i] - lista.texto[indexPal].posiciones[i-1];
        if (mayorDist < distProvisional)
        {
            mayorDist = distProvisional;
        }
    }
    mayorDist--;
    return mayorDist;
}

void escribirMaximasDistancias(TLista& lista)
{
    for (int i = 0;i < lista.numPals;i++ )
    {
        // Esta repetida
        if (lista.texto[i].numPos > 1)
        {
            cout << lista.texto[i].palabra << ": " << mayorDistancia(lista,i) << endl;
        }
    }
}

int main(){
    TLista lista;
    string palabra;
    int pos = 1;

    cout << "Introduzca una frase terminada en fin: " << endl;
    cin >> palabra;
    while (palabra != "fin")
    {
        procesarPalabras(lista,palabra,pos);
        pos++;
        cin >> palabra;
    }
    cout << "La maxima distancia de las palabras repetidas son: " << endl;
    escribirMaximasDistancias(lista);
return 0;

}

// can you can a can as a canner can can a can fin
