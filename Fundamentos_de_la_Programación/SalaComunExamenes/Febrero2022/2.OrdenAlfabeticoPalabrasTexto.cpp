#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_PAL_DIST = 15;
typedef array<string, MAX_PAL_DIST> TTexto;

struct TLista {
    TTexto texto;
    int tamTexto = 0;
};

bool esta(TLista& lista, string palabra, int posAct)
{
    bool siEsta = false;

    for (int i = posAct - 1;i < lista.tamTexto && i >= 0 && !siEsta;i-- )
    {
        if (palabra == lista.texto[i])
        {
            siEsta = true;
        }
    }
    return siEsta;
}

bool ordenadaAlfabeticamente(string palabra)
{
    bool ordenada = true;
    int indexAnt = 0;

    for (int i = 1;i < int(palabra.size()) && ordenada;i++ )
    {
        if (palabra[indexAnt] > palabra[i])
        {
            ordenada = false;
        }
        indexAnt = i;
    }
    return ordenada;
}

void leerDatos(TLista& lista)
{
    string palabra;
    int index = 0;

    cout << "Introduzca el texto (FIN para terminar): " << endl;
    cin >> palabra;

    //  Correcion: podemos guardar en el array solo el resultado sin tener que meter el texto entero
    while (palabra != "FIN" && lista.tamTexto < MAX_PAL_DIST)
    {
        if (!esta(lista,palabra,index) && ordenadaAlfabeticamente(palabra))
        {
            lista.texto[index] = palabra;
            index++;
            lista.tamTexto++;
        }
        cin >> palabra;
    }
}


void imprimirOrdenadasAlfabeticamente(TLista& lista)
{
    cout << "Las palabras cuyos caracteres estan ordenados son: " << endl;
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << lista.texto[i] << " ";
    }
}

int main(){
    TLista lista;

    leerDatos(lista);
    cout << endl;
    imprimirOrdenadasAlfabeticamente(lista);
    return 0;
}
