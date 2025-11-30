#include <iostream>
#include <array>
#include <math.h>
#include <string>

using namespace std;

const char VACIO = 'V';
const int MAX_PAL_DIST = 20;
typedef array<string, MAX_PAL_DIST> TTexto;

struct TLista {
    TTexto texto;
    string patron;
    int tamTexto = 0;
    int x;
};

void reducirPatron(TLista& lista)
{
    // Elegimos una letra
    for (int i = 0;i < int(lista.patron.size()) ;i++ )
    {
        for (int j = i + 1; j < int(lista.patron.size())  ;j++ )
        {
            if (lista.patron[i] == lista.patron[j])
            {
                lista.patron[j] = VACIO;
            }
        }
    }
}

bool esta(TLista& lista, string palabra ,int posAnt)
{
    bool found = false;

    for (int i = posAnt - 1;i < lista.tamTexto && i >= 0 && !found;i-- )
    {
        if (palabra == lista.texto[i])
        {
            found = true;
        }
    }
    return found;
}

void leerDatos(TLista& lista)
{
    string palabra;
    int index = 0;

    cout << "Introduzca el patron: ";
    cin >> lista.patron;
    reducirPatron(lista);
    do
    {
        cout << "Introduzca el valor de x: ";
        cin >> lista.x;
    } while (lista.x <= 0);
    cout << "Introduzca el texto (FIN para terminar):  " << endl;
    cin >> palabra;
    while (palabra != "FIN" && lista.tamTexto < MAX_PAL_DIST)
    {
        if (!esta(lista,palabra,index))
        {
            lista.texto[index] = palabra;
            index++;
            lista.tamTexto++;
        }
        cin >> palabra;
    }
}

// Para arreglar el problema: que sume tambien las letras repetidas con;
// crear un nuevo patron pero sin letras repetidas y comparar ese
// Hay que reducir el patron

void compararPatronConLetrasTexto(TLista& lista)
{
    int cnt;
    char letra;
    string palabra;

    // Elegimos la palabra
    for (int i = 0 ;i < lista.tamTexto ;i++ )
    {
        cnt = 0;
        palabra = lista.texto[i];
        // Elegimos letra de la palabra
        for (int j = 0;j < int(lista.texto[i].size()) ;j++ )
        {
            letra = palabra[j];
            // Comparamos letra por letra a las letras del patron
            for (int k = 0;k < int(lista.patron.size()) ;k++ )
            {
                if (lista.patron[k] == letra)
                {
                    cnt++;
                }
            }
        }
        if (cnt >= lista.x)
        {
            cout << palabra << " ";
        }
    }
}

int main(){
    TLista lista;

    leerDatos(lista);
    compararPatronConLetrasTexto(lista);
return 0;

}

