#include<iostream>
#include<array>
#include<string>

using namespace std;

int const MAX_PAL_DIST = 16;
int const N = 100;
typedef array<string, MAX_PAL_DIST> TString;
typedef array<bool, MAX_PAL_DIST> TOcupado;
typedef array<string, N> TTexto;  // CON ESTO PUEDO CONTABILIZAR Y GUARDAS LAS PALABRAS DEL TEXTO EN UN ARRAY Y ASI USARLO CUANDO QUERAMOS
                                        // DE ESTO NECESITAMOS QUE CADA VEZ QUE llamamos a lista.cadena GUARDARLO EN TTexto texto,
                                        // y aumentar el tamTexto, para no tener que usar la constante N
struct TLista{
    string cadena;
    TString palabra;
    TOcupado ocupado;
    TTexto texto;
    int tamTexto;
};

/// SI CONSIGO SABER ORDENAR ARRAYS PUEDE FUNCIONAR
void leerTextoYString(TLista& lista)
{
    int index = 0;
    lista.tamTexto = index;

    cout << "Introduzca un texto (FIN para terminar): ";
    cin >> lista.cadena;

    while (lista.cadena != "FIN")   /// SOLO SIRVE PARA TRASPASAR EL TEXTO DE LA VARIABLE cadena A EL ARRAY TTexto PARA PODER USARLO CUANDO SEA
    {
        lista.texto[lista.tamTexto] = lista.cadena;
        lista.tamTexto++;
        cin >> lista.cadena;
    }

    /// DE ESTA PARTE SOLO QUEDA ORDENAR LAS PALABRAS EN LOS 15 ESPACIOS SIN QUE SE REPITAN Y POR ORDEN DE APARCION
    int cnt;
    bool esta = false;
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cnt = 0;
        if (i == 0)
        {
            lista.palabra[0] = lista.texto[0];
        }
        else
        {
            for (int j = i; j >= 0 && !esta ;j-- )
            {
                cout << "Anlaizar: " << lista.palabra[i] << endl;
                cout << "Comparacion: " << lista.texto[j-cnt] << endl;
                if (lista.texto[j-cnt] != lista.palabra[i])
                {
                    esta = false;
                }
                else if (lista.texto[j-cnt] == lista.palabra[i])
                {
                    esta = true;
                }
            }
        }
        if (!esta)
        {
            lista.palabra[i] =  lista.texto[i];
        }
    }
    for (int i = 0;i < MAX_PAL_DIST ;i++ )    // SOLO CHEQUEA EL VECTOR QUE GUARDA LAS PALABRAS DEL TEXTO EN ORDEN CORRECTO Y SIN REPETIR
    {
        cout << lista.palabra[i]  << endl;
    }
}


void calcPos(TLista& lista)
{
    int primeraPos = 0;
    int ultimaPos = 0;
    bool primeraApari = false;

    for (int i = 0;i < MAX_PAL_DIST;i++ )
    {
        primeraApari = false;
        for (int j = 0;j < lista.tamTexto ;i++ )
        {
            if (lista.palabra[i] == lista.texto[j] && !primeraApari)    // PARA LA PRIMERA APARICION
            {
                primeraPos = j + 1;
                ultimaPos = primeraPos;
                primeraApari = true;
            }
            else if (lista.palabra[i] == lista.texto[j] && primeraApari) // POR SI HAY MAS DE UNA APARCION
            {
                ultimaPos = j + 1;
            }
        }
        cout << lista.palabra[i] << " " << primeraPos << " " << ultimaPos << endl;
    }
}

int main()
{
    TLista lista1;
    lista1.ocupado = {{}};

    leerTextoYString(lista1);
    calcPos(lista1);
    return 0;
}

/*
while (lista.cadena != "FIN")   /// ESTE S�LO ORDENARA LAS PALABRAS EN TString palabra
    {
        cout << "Analizar: " << lista.cadena << endl;
        for (int i = index;i >= 0 && !lista.ocupado[index] ;i-- )
        {
            lista.palabra[index] = lista.cadena;
            cout << "Comparacion: " << lista.palabra[index] << endl;
            if (lista.palabra[index] != lista.palabra[i])
            {
                lista.palabra[index] = lista.cadena;
                lista.ocupado[index] = true;
            }
        }
        lista.texto[index] = lista.cadena;
        index++;
        lista.tamTexto = index;
        cin >> lista.cadena;
    }
    for (int i = 0;i < lista.tamTexto ;i++ )    // SOLO CHEQUEA EL VECTOR QUE GUARDA LAS PALABRAS DEL TEXTO
    {
        cout << lista.texto[i]  << endl;
    }
*/
