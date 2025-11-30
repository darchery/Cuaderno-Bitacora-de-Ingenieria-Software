#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int const MAX = 20;
typedef array<char, MAX> TArray;

struct TLista {
    TArray cadena;
    int tamCadena = 0;
};

void leerCadenas(TLista& lista1, TLista& lista2)
{
    char c1, c2;
    int index = 0;

    cout << "Introduzca una secuencia de letras mayusculas (salto de linea para terminar y como maximo " << MAX << " letras): ";
    cin.get(c1);
    while (c1 != '\n' && lista1.tamCadena < MAX)
    {
        lista1.cadena[index] = c1;
        index++;
        lista1.tamCadena = index;
        cin.get(c1);
    }

    index = 0;

    cout << "Introduzca una secuencia de letras mayusculas (salto de linea para terminar y como maximo " << MAX << " letras): ";
    cin.get(c2);
    while (c2 != '\n' && lista2.tamCadena < MAX)
    {
        lista2.cadena[index] = c2;
        index++;
        lista2.tamCadena = index;
        cin.get(c2);
    }
}

/*
1. Seleccionaremos una letra de cada cadena
2. Las comaparamos mediante su valor int
3. Y la que sea menor la escogemos y la metemos en el array
4. Y el mayor, lo dejamos guardado en la variable c1 o c2
5. Y buscamos un numero valor en el array
6. Así hasta vaciar el array

Cuando usemos un caracter lo vamos a eliminar asignandolo a ' '
*/

TLista mezclaOrdenada(TLista& lista1, TLista& lista2)
{
    TLista listaRes;
    int index = 0, jIndex = 0;
    int indexRes = 0;
    char c1 = ' ', c2 = ' ';

    // ARREGLAR LOGICA
    while (((index < lista1.tamCadena) && (jIndex < lista2.tamCadena)) && (listaRes.tamCadena < MAX))
    {
        cout << "Indice I: " << index << endl;
        cout << "Indice J: " << jIndex << endl;

        // Se eligen caracteres
        if (index < lista1.tamCadena)
        {
            c1 = lista1.cadena[index];
        }

        if (jIndex <  lista2.tamCadena)
        {
            c2 = lista2.cadena[jIndex];
        }

        // Analisis
        if (c1 < c2)    // Se mete c1 y se guarda c2
        {
            listaRes.cadena[indexRes] = c1;
            index++;
            indexRes++;
        }
        else if (c2 < c1)   // Se mete c2 y se guarda c1
        {
            listaRes.cadena[indexRes] = c2;
            jIndex++;
            indexRes++;
        }
        else if (c1 == c2)  // Caso igual, se mete c1 y se guarda c2
        {
            listaRes.cadena[indexRes] = c1;
            index++;
            indexRes++;
        }
        listaRes.tamCadena = indexRes;
    }
    cout << listaRes.tamCadena << endl;
    return listaRes;
}

void escribirRes(TLista& lista)
{
    cout << "La mezcla ordenada es: ";
    for (int i = 0; i < lista.tamCadena; i++)
    {
        cout << lista.cadena[i];
    }
}

int main(){
    TLista lista1, lista2, listaRes;

    leerCadenas(lista1, lista2);
    listaRes = mezclaOrdenada(lista1, lista2);
    escribirRes(listaRes);
    return 0;
}
