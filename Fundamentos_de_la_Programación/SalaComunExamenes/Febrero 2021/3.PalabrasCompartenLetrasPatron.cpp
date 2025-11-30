#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_CAR_PATRON = 5;
const int MAX_PAL_DIST = 20;

typedef array<string, MAX_PAL_DIST> TTexto;

struct TLista
{
    TTexto texto;
    string patron;
    int tamTexto = 0;
};

bool esta(TLista& lista, int index, string palabra)
{
    bool found = false;

    for (int i = index - 1;i < lista.tamTexto && i >= 0 && !found;i-- )
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
    int index = 0;
    string palabra;

    do
    {
        cout << "Introduzca un patron (longitud maxima = " << MAX_CAR_PATRON << " ): ";
        cin >> lista.patron;
    } while (lista.patron.size() > MAX_CAR_PATRON || lista.patron.size() < 0);

    cout << "Introduzca un texto (FIN para terminar): " << endl;
    cin >> palabra;
    while (palabra != "FIN" && lista.tamTexto < MAX_PAL_DIST)
    {
        if (!esta(lista,index,palabra))
        {
            lista.texto[index] = palabra;
            lista.tamTexto++;
            index++;
        }
        cin >> palabra;
    }
}

bool apareceRepetidaLetraPatron(string patron, int index, char letra)
{
    bool aparece = false;

    for (int i = index - 1;i < int(patron.size()) && i >= 0 && !aparece;i-- )
    {
        if (letra == patron[i])
        {
            aparece = true;
        }
    }
    return aparece;
}

void letrasPatronComparteTexto(TLista& lista)
{
    int tamPatron = int(lista.patron.size());
    bool primeraLetraEncontrada ;
    string palabra;

    cout << "Palabras que comparten letra con las letras del patron: " << endl;
    // Elige una letra del patron
    for (int i = 0;i < tamPatron ;i++ )
    {
        // Comprueba que no se ha utilizado antes
        if (!apareceRepetidaLetraPatron(lista.patron,i,lista.patron[i]))
        {
            cout << lista.patron[i] << ": ";
            // Elige una palabra del texto
            for (int j = 0;j < lista.tamTexto ;j++ )
            {
                palabra = lista.texto[j];
                primeraLetraEncontrada = false;
                // Elige una letra de la palabra del texto
                for (int k = 0;k < int(lista.texto[j].size()) && !primeraLetraEncontrada;k++ )
                {
                    // Las compara
                    if (lista.patron[i] == palabra[k])
                    {
                        cout << lista.texto[j] << " ";
                        primeraLetraEncontrada = true;
                    }

                }
            }
            cout << endl;
        }
    }
}

int main(){
    TLista lista;

    leerDatos(lista);
    letrasPatronComparteTexto(lista);
return 0;

}


