#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_PAL = 20;
const int MAX_REP =  5;

typedef array<int, MAX_REP> TAparicion;

struct TPalabra {
    string palabra;
    TAparicion aparicion;
    int numApari = 0;
};

typedef array<TPalabra, MAX_PAL> TTexto;

struct TLista {
    TTexto texto;
    int tamTexto = 0;
};

void esta( TLista& lista, string palabra, int posAct, bool& siEsta, int& index)
{
    siEsta = false;
    index = 0;

    for (int i = posAct - 1;i >= 0 && !siEsta ;i-- )
    {
        if (lista.texto[i].palabra == palabra)
        {
            siEsta = true;
            index = i;
        }
    }
}

void procesarPalabra(TLista& lista, string palabra, int pos)
{
    bool siEsta;
    int index;

    esta(lista,palabra,lista.tamTexto,siEsta,index);
    if (!siEsta)
    {
        lista.texto[lista.tamTexto].palabra = palabra;
        lista.texto[lista.tamTexto].aparicion[lista.texto[lista.tamTexto].numApari] = pos;
        lista.texto[lista.tamTexto].numApari++;
        lista.tamTexto++;
    }
    else
    {
        lista.texto[index].aparicion[lista.texto[index].numApari] = pos;
        lista.texto[index].numApari++;
    }
}

void escribirTexto(const TLista& lista)
{
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << lista.texto[i].palabra << ": ";
        for (int j = 0;j < lista.texto[i].numApari ;j++ )
        {
            cout << lista.texto[i].aparicion[j] << " ";
        }
        cout << endl;
    }
}

int main(){
    TLista lista;
    string palabra;
    int pos = 1;

    cout << "Introduzca un texto acabado en end: " << endl;
    cin >> palabra;
    while (palabra != "end")
    {
        procesarPalabra(lista,palabra,pos);
        pos++;
        cin >> palabra;
    }
    cout << "Las palabras con sus respectivas apariciones: " << endl;
    escribirTexto(lista);
return 0;

}
