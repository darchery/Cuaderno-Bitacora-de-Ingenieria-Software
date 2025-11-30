#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_PAL_DIS = 15;

typedef array<string, MAX_PAL_DIS> TTexto;
typedef array<bool, MAX_PAL_DIS> TTachado;

struct TLista {
    TTexto texto;
    TTachado tachado = {{}};
    int tamTexto = 0;
};

int sumaASCII(string palabra)
{
    int suma = 0;

    for(int i = 0; i < int(palabra.size());i++ )
    {
        suma += int(palabra[i]);
    }
    return suma;
}

void leerTextoYDescartarMayoresQuePrimera(TLista& lista, int& tampPrimPalabra)
{
    string cadena;
    bool found;
    int cicloRepes;
    int index = 0;

    cout << "Introduzca un texto (FIN para terminar): ";
    cin >> cadena;
    tampPrimPalabra = sumaASCII(cadena);

    while (cadena != "FIN" && lista.tamTexto < MAX_PAL_DIS)
    {
        if (tampPrimPalabra >= sumaASCII(cadena))
        {
            found = false;
            cicloRepes = lista.tamTexto - 1;
            lista.texto[index] = cadena;

            while (cicloRepes >= 0 && !found)
            {
                if (lista.texto[cicloRepes] == lista.texto[index])
                {
                    found = true;
                }
                cicloRepes--;
            }
            if (!found)
            {
                lista.tamTexto++;
                index++;
            }
        }
        cin >> cadena;
    }

    /*for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << lista.texto[i] << " ";
    }*/
}

int calcTope(TLista& lista)
{
    int tope = 0;
    string menor = lista.texto[1];

    for (int i = 1;i < lista.tamTexto ;i++ )
    {
        if (sumaASCII(menor) < sumaASCII(lista.texto[i]))
        {
            menor = lista.texto[i];
            tope = sumaASCII(menor);
        }
    }
    tope++;
    return tope;
}

// HAY QUE ORDENARLO SEGUN SU ORDEN ALFABETICO
void analizarArray(TLista& lista)
{
    string menor = lista.texto[1];
    int tope = calcTope(lista);
    int index = 1;

    for(int i = 1; i < lista.tamTexto;i++ )
    {
       if(tope > sumaASCII(lista.texto[i]) && !lista.tachado[i])
       {
            menor = lista.texto[i];
            tope = sumaASCII(lista.texto[i]);
            index = i;
       }
    }
    cout << menor << " ";
    lista.tachado[index] = true;
}

int main(){
    TLista lista1;
    int tampPrimPalabra;

    leerTextoYDescartarMayoresQuePrimera(lista1, tampPrimPalabra);  // Mete las palabras en un array(sin repetir), maximo 15 diferentes
    cout << "Las palabras menores que " << lista1.texto[0] << " son: " << endl;
    for (int i = 0;i < lista1.tamTexto - 1 ;i++ )
    {
        analizarArray(lista1);
    }
    return 0;
}

/*
 Para ordenarlos alfabeticamente, cogeria una palabra y compararia la primera letra de esta con la otra:
 1. Si la primera es menor que la segundo esa palabra va antes que la segunda, por lo tanto compararia con otra palabra
 2. Si es mayor eso quiere decir que no es un candidato para ponerla asi que saltariamos a la siguiente palabra
 3. Si son iguales (sus primeras letras) analizariamos las segundas letras y asi hasta que una sea diferente que otra
    3.1. Si es menor vamos al paso 1
    3.2. Si es mayor vamos al paso 2
*/

// Se considera que una palabra P1 es menor que otra P2 si la suma del código ASCII de
// las letras que forman P1 es menor que la suma del código ASCII de las letras que
// forman P2.
// Las palabras menores que la primera palabra
// Se imprimen de menor a mayor


// CREO QUE VOY A IR ESTA TARDE AL CINE Y LUEGO VOY A IR A CENAR MAS TARDE FIN

