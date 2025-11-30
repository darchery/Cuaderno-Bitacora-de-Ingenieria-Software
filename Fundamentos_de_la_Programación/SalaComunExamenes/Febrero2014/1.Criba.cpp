#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 9;
typedef array< int, MAX> TLista;

void leerLista(TLista& lista)
{
    for (int i = 0;i < MAX ;i++ )
    {
        cin >> lista[i];
    }
}

bool esta(TLista& lista2, int posAct, int num)
{
    bool siEsta = false;

    for (int i = posAct - 1;i >= 0  && !siEsta;i-- )
    {
        if (num == lista2[i])
        {
            siEsta = true;
        }
    }
    return siEsta;
}

int vecesQueAparece(TLista& lista ,int num)
{
    int veces = 0;

    for (int i = 0;i < MAX ;i++ )
    {
        if (num == lista[i])
        {
            veces++;
        }
    }
    return veces;
}

void criba(TLista& lista1, TLista& lista2, int x,int& tamLista2)
{
    tamLista2 = 0;

    for (int i = 0;i < MAX ;i++ )
    {
        if (!esta(lista2,tamLista2,lista1[i]) && x == vecesQueAparece(lista1,lista1[i]) )
        {
            lista2[tamLista2] = lista1[i];
            tamLista2++;
        }
    }
}

void escribirLista(TLista& lista2, int tamLista2)
{
    for (int i = 0;i < tamLista2 ;i++ )
    {
        cout << lista2[i] << " ";
    }
}

int main(){
    TLista lista1, lista2;
    int x;
    int tamLista2;

    cout << "El contenido de la lista1 es: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cin >> lista1[i];
    }
    cout << "El valor de x es: ";
    cin >> x;
    criba(lista1,lista2,x, tamLista2);
    cout << "El contenido de la lista2 es: ";
    escribirLista(lista2, tamLista2);
return 0;

}

// 1 3 4 3 1 3 0 -6 4
