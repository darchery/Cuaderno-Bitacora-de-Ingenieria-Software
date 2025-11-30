#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_PAL_DIS = 15;

typedef array<string, MAX_PAL_DIS> TTexto;
typedef array<string, MAX_PAL_DIS> TRes;

struct TLista {
    TTexto texto;
    TRes resultado;
    int tamTexto = 0;
    int tamRes = 0;
};

void leerTexto(TLista& lista)
{
    string cadena;
    bool repetido;
    int ciclosRepes;
    int index = 0;

    cout << "Introduzca el texto (FIN para terminar): ";
    cin >> cadena;

    while (cadena != "FIN" && lista.tamTexto < MAX_PAL_DIS)
    {
        repetido = false;
        ciclosRepes = lista.tamTexto - 1;

        // Asigancion de cadena en la posicion index del array
        lista.texto[index] = cadena;

        // Se repite el string?
        while (ciclosRepes >= 0 && !repetido)
        {
            if (lista.texto[ciclosRepes] == lista.texto[index] )
            {
                repetido = true;
            }
            ciclosRepes--;
        }

        // Si no se repite
        if (!repetido)
        {
            index++;
            lista.tamTexto++;
        }

        // Siguiente elemento
        cin >> cadena;
    }
}

bool estaOrdenada(string palabra)
{
    bool found = true;
    char letraAnt = palabra[0];

    for (int i = 1;i < int(palabra.size()) && found;i++ )
    {
        if (letraAnt > palabra[i])
        {
            found = false;
        }
        letraAnt = palabra[i];
    }
    return found;
}

void palabrasOrdenadasAlfabeticamente(TLista& lista)
{
    int index = 0;

    cout << "Las palabras cuyos caracteres estan ordenados son: " << endl;
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        if (estaOrdenada(lista.texto[i]))
        {
            lista.resultado[index] = lista.texto[i];
            index++;
        }
    }

    lista.tamRes = index;
    for (int i = 0;i < lista.tamRes ;i++ )
    {
        cout << lista.resultado[i] << " ";
    }
}

// ELLOS CANTAN EL HIMNO DE SU EQUIPO DE FUTBOL CON PASION Y YO NO CANTO EL HIMNO FIN
int main(){
    TLista lista1;

    leerTexto(lista1);
    palabrasOrdenadasAlfabeticamente(lista1);
    return 0;
}

/*for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << lista.texto[i] << endl;
    }*/

// Antiguo bucle
/*
while (cadena != "FIN" && lista.tamTexto < MAX_PAL_DIS)
    {
        repetido = false;
        ciclosRepes = lista.tamTexto - 1;

        // Primer elemento
        if (index == 0)
        {
            lista.texto[index] = cadena;
            index++;
            lista.tamTexto++;
        }
        else
        {
            // Asigancion de cadena en array
            lista.texto[index] = cadena;

            // Se repite el string?
            while (ciclosRepes >= 0 && !repetido)
            {
                if (lista.texto[ciclosRepes] == lista.texto[index] )
                {
                    repetido = true;
                }
                ciclosRepes--;
            }

            // Si no se repite
            if (!repetido)
            {
                index++;
                lista.tamTexto++;
            }
        }

        // Siguiente elemento
        cin >> cadena;
    }
*/
