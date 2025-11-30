#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int const MAX_REP = 15;
int const MAX_PAL_DIST = 15;
int const N = 100; /// PROVISIONALMENTE
typedef array<string, N> TTexto;
typedef array<bool, N> TTachado;

struct TLista {
    TTexto texto;
    TTachado tachado;
    int tamTexto;
};

void inicializar(TLista& lista)
{
    for (int i = 0;i < N ;i++ )
    {
        lista.tachado[i] = true;
    }
}

void leerTexto(TLista& lista)
{
    string cadena;
    lista.tamTexto = 0;

    cout << "Introduzca un texto (FIN para terminar): ";
    cin >> cadena;
    while (cadena != "FIN")
    {
        lista.texto[lista.tamTexto] = cadena;
        lista.tamTexto++;
        cin >> cadena;
    }
    cout << endl;
}

void elegirPalabra(TLista& lista, string& palabra)
{
    bool found = false;
    for (int i = 0;i < lista.tamTexto && !found ;i++ )
    {
        if (lista.tachado[i])
        {
            palabra = lista.texto[i];
            found = true;
        }
    }
}

bool maximoRepeticones(TLista& lista, string palabra)
{
    bool masDe15 = false;
    int repes = 0;

    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        if (palabra == lista.texto[i])
        {
            repes++;
        }
    }
    if (repes > MAX_REP)
    {
        masDe15 = true;
    }
    return masDe15;
}

void calcPosiciones(TLista& lista,string palabra ,int& primAparicion, int&  ultAparicion)
{
    bool aparicion = false;

    cout << palabra;
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        if (palabra == lista.texto[i] && !aparicion)    // PRIMERA APARCION
        {
            primAparicion = i + 1;
            cout << " " << primAparicion;
            ultAparicion = primAparicion;
            aparicion = true;
        }
        else if (palabra == lista.texto[i] && aparicion) // N-ESIMA APARCION QUE SE ACTUALIZA
        {
            ultAparicion = i + 1;
            cout << " " << ultAparicion;
        }
    }
    cout << endl;

}

int main(){
    TLista lista1;
    string palabra;
    string palabraAnterior;
    int primAparicion, ultAparicion;

    int palabrasImpresiones = 0;

    inicializar(lista1);
    leerTexto(lista1);
    cout << "Palabras y posiciones primera y ultima: " << endl;
    for (int i = 0;i <= MAX_PAL_DIST && palabrasImpresiones < MAX_PAL_DIST;i++ )
    {
            elegirPalabra(lista1, palabra);
            if (!maximoRepeticones(lista1, palabra) && palabra != palabraAnterior)
            {
                calcPosiciones(lista1, palabra, primAparicion, ultAparicion);
                palabrasImpresiones++;

            }
            for (int j = 0;j < lista1.tamTexto ;j++ )
            {
                if (palabra == lista1.texto[j])
                {
                    lista1.tachado[j] = false;
                }
            }
            palabraAnterior = palabra;
    }
return 0;

}
