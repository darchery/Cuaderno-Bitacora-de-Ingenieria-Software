#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int const MAX = 20;
typedef array<char, MAX> TCadena;

struct TLista {
    TCadena cadena;
    int tamCadena = 0;
};
//ACDFE DFEAC
void leerCadena(TLista& lista1, TLista& lista2)
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
    while (c2 != '\n' &&  lista2.tamCadena < MAX)
    {
        lista2.cadena[index] = c2;
        index++;
        lista2.tamCadena = index;
        cin.get(c2);
    }
}

bool ordenRelativo(TLista& lista1, TLista& lista2)
{
    bool ordenado = true;
    int index = 0;
    int jIndex = 0;
    int tope = lista1.tamCadena - 1;

    /*if (lista1.tamCadena != lista2.tamCadena)
    {
        ordenado = false;
    }
    else
    {*/
        while (ordenado && jIndex < tope + 1)
        {
            if (lista1.cadena[index] == lista2.cadena[jIndex] )
            {
                for (int i = 0;i < lista1.tamCadena && ordenado ;i++ ) // SOLO SON LOS CICLOS
                {
                    index++;
                    jIndex++;

                    if (index > tope)
                    {
                        index = 0;
                    }

                    if (jIndex > tope)
                    {
                        jIndex = 0;
                    }

                    if (lista1.cadena[index] != lista2.cadena[jIndex])
                    {
                        ordenado = false;
                    }
                }
            }
            jIndex++;
        }
    //}
    return ordenado;
}

int main(){
    TLista lista1, lista2;

    leerCadena(lista1, lista2);
    if (ordenRelativo(lista1, lista2))
    {
        cout << "SI son iguales" << endl;
    }
    else
    {
        cout << "NO son iguales" << endl;
    }
return 0;

}
/*
                cout << "Orden 1: " << lista1.cadena[index] << endl;
                cout << "Orden 2: " << lista2.cadena[jIndex] << endl;
                cout << "Index I: " << index << endl;
                cout << "Index J: " << jIndex << endl;
*/
