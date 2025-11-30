#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_PAL_DIST = 25;
typedef array<string, MAX_PAL_DIST> TTexto;

struct TLista {
    TTexto texto;
    int tamTexto = 0;
    string sufijo;
};

bool esta(TLista& lista ,string palabra, int posAct)
{
    bool siEsta = false;

    for (int i = posAct;i >= 0 && !siEsta;i-- )
    {
        if (palabra == lista.texto[i])
        {
            siEsta = true;
        }
    }
    return siEsta;
}

bool contieneSufijo(TLista& lista, string palabra)
{
    bool contiene = true;
    int index = lista.sufijo.size() - 1;

    for (int i = palabra.size() - 1;i >= 0 && contiene && index >= 0;i-- )
    {
        if (palabra[i] != lista.sufijo[index])
        {
            contiene = false;
        }
        index--;
    }
    return contiene;
}

void escribirTexto(TLista& lista)
{
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << lista.texto[i] << " ";
    }
}

int main(){
    TLista lista;
    string palabra;

    cout << "Introduzca el sufijo: ";
    cin >> lista.sufijo;
    cout << endl;
    cout << "Introduzca el texto (FIN para terminar): " << endl;
    cin >> palabra;
    while (palabra != "FIN")
    {
        if (!esta(lista,palabra,lista.tamTexto) && contieneSufijo(lista,palabra))
        {
            lista.texto[lista.tamTexto] = palabra;
            lista.tamTexto++;
        }
        cin >> palabra;
    }
    cout << "Las palabras que terminan en " << lista.sufijo << " son:" << endl;
    escribirTexto(lista);
return 0;

}
