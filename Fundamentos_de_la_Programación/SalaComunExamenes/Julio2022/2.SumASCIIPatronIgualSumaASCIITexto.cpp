#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_PAL_DIST = 15;
typedef array<string, MAX_PAL_DIST> TTexto;

struct TLista {
    TTexto texto;
    int tamTexto = 0;
    string patron;
    int sumaPatron;
};

bool esta(TLista& lista, string palabra, int index)
{
    bool siEsta = false;

    for (int i = index - 1;i >= 0 && !siEsta;i-- )
    {
        if (lista.texto[i] == palabra)
        {
            siEsta = true;
        }
    }
    return siEsta;
}

int sumaASCII(string palabra)
{
    int suma = 0;

    for (int i = 0;i < int(palabra.size()) ;i++ )
    {
        suma += int(palabra[i]);
    }
    return suma;
}

void leerTexto(TLista& lista)
{
    string palabra;

    cout << "Introduzca el patron: ";
    cin >> lista.patron;
    lista.sumaPatron = sumaASCII(lista.patron);
    cout << "Introduzca el texto (FIN para terminar): " << endl;
    cin >> palabra;

    while (palabra != "FIN")
    {
        if (!esta(lista,palabra,lista.tamTexto) && lista.sumaPatron == sumaASCII(palabra) )
        {
            lista.texto[lista.tamTexto] = palabra;
            lista.tamTexto++;
        }
        cin >> palabra;
    }
}

void escribirResultado(TLista& lista)
{
    cout << "Las palabras que cumplen la condicion son: " << endl;
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << lista.texto[i] << " ";
    }
}

int main(){
    TLista lista;

    leerTexto(lista);
    escribirResultado(lista);
return 0;

}
