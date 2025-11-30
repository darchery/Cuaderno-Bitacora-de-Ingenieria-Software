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

bool esta(const TLista& lista, string palabra, int posAct)
{
    bool siEsta = false;

    for (int i = posAct - 1;i >= 0 && !siEsta ;i-- )
    {
        if (palabra == lista.texto[i])
        {
            siEsta = true;
        }
    }
    return siEsta;
}

bool estaOrdenada(string palabra)
{
    bool siEsta = true;

    for (int i = 1;i < int(palabra.size()) && siEsta;i++ )
    {
        if (palabra[i-1] > palabra[i])
        {
            siEsta = false;
        }
    }
    return siEsta;
}

void escribirTexto(const TLista& lista)
{
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << lista.texto[i] << " ";
    }
}

int main(){
    TLista lista;
    string palabra;

    cout << "Introduzca el texto (FIN para terminar): " << endl;
    while (palabra != "FIN")
    {
        if (!esta(lista,palabra,lista.tamTexto) && estaOrdenada(palabra))
        {
            lista.texto[lista.tamTexto] = palabra;
            lista.tamTexto++;
        }
        cin >> palabra;
    }
    cout << "Las palabras cuyos caracteres estan ordenados son: " << endl;
    escribirTexto(lista);
return 0;

}
