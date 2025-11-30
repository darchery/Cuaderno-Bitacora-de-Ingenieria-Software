#include <iostream>
#include <array>
#include <math.h>
#include <string>

using namespace std;

const int TAM_CAR = 5;
const int MAX_PAL_DIST = 15;

struct TDatos {
    string palabra;
    int numCaracteres;
};

typedef array<TDatos, MAX_PAL_DIST> TTexto;

struct TLista {
    TTexto texto;
    string patron;
    int tamTexto = 0;
};

bool letrasRepetidas(string palabra)
{
    bool repetido = false;

    for (int i = 0;i < int(palabra.size()) && !repetido;i++ )
    {
        for (int j = 0;j < int(palabra.size()) && !repetido;j++ )
        {
            if (i != j && palabra[i] == palabra[j])
            {
                repetido = true;
            }
        }
    }
    return repetido;
}

bool esta(TLista& lista, string palabra, int posAct)
{
    bool siEsta = false;

    for (int i = posAct - 1;i >= 0 && !siEsta;i-- )
    {
        if (palabra == lista.texto[i].palabra)
        {
            siEsta = true;
        }
    }
    return siEsta;
}

int letrasDelPatron(TLista& lista, string palabra)
{
    int numLetras = 0;
    bool found;

    for (int i = 0;i < int(lista.patron.size() ) ;i++ )
    {
        found = false;
        for (int j = 0;j < int(palabra.size()) && !found;j++ )
        {
            if (lista.patron[i] == palabra[j])
            {
                numLetras++;
                found = true;
            }
        }
    }
    return numLetras;
}

void escribirResultado(TLista& lista)
{
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << lista.texto[i].palabra << " " << lista.texto[i].numCaracteres << endl;
    }
}

int main(){
    TLista lista;
    string palabra;
    int veces = 0;

    do
    {
        cout << "Introduzca un patron (long = " << TAM_CAR << ", sin letras repetidas): ";
        cin >> lista.patron;
    } while (lista.patron.size() != TAM_CAR || letrasRepetidas(lista.patron) );
    cout << "Introduzca un texto (FIN para terminar): " << endl;
    cin >> palabra;

    while (palabra != "FIN")
    {
        veces = letrasDelPatron(lista,palabra);
        if (!esta(lista,palabra,lista.tamTexto) && veces > 0)
        {
            lista.texto[lista.tamTexto].palabra = palabra;
            lista.texto[lista.tamTexto].numCaracteres = veces;
            lista.tamTexto++;
        }
        cin >> palabra;
    }
    cout << "Palabras y numero de letras que coinciden con el patron:" << endl;
    escribirResultado(lista);
return 0;

}

// ANTERIORMENTE IBA A TRABAJAR EN TREN PERO AHORA VOY A TRABAJAR EN AUTOMOVIL FIN
