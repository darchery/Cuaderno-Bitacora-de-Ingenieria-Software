#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 10;
typedef array<int, MAX> TArray;

struct TLista {
    TArray a;
    int tamVec = 0;
};

void leerLista(TLista& lista)
{
    do
    {
        cout << "Introduzca la cantidad de elementos de la lista (maximo " << MAX << "): ";
        cin >> lista.tamVec;
    } while (lista.tamVec > MAX || lista.tamVec < 0);
    cout << "Intoduzca los " << lista.tamVec << " elementos: ";
    for (int i = 0;i < lista.tamVec ;i++ )
    {
        cin >> lista.a[i];
    }
}

bool esPrimo (int num)
{
    bool primo = true;

    if (num == 2)
    {
        primo = true;
    }
    else
    {
        for (int i = 2;i < num ;i++ )
        {
            if (num % i == 0)
            {
                primo = false;
            }
        }
    }
    return primo;
}

void eliminarPrimo(TLista& lista, int posPrimo)
{
    cout << "La lista tras la eliminacion: ";
    lista.tamVec--;

    while (posPrimo < lista.tamVec)
    {
        lista.a[posPrimo] = lista.a[posPrimo + 1];
        posPrimo++;
    }

    for (int i = 0;i < lista.tamVec ;i++ )
    {
        cout << lista.a[i] << " ";
    }
}

void primerPrimo(TLista& lista)
{
    bool found = false;
    int posPrimo;

    for (int i = 0;i < lista.tamVec && !found;i++ )
    {
        if (esPrimo(lista.a[i]))
        {
            posPrimo = i;
            found = true;
        }
    }
    if (found == false)
    {
        cout << "No hay primos en la lista" << endl;
    }
    else
    {
        cout << "El primer primo es " << lista.a[posPrimo]  << " y esta en la posicion " << posPrimo << endl;
        eliminarPrimo(lista, posPrimo);
    }
}

int main(){
    TLista lista;

    leerLista(lista);
    primerPrimo(lista);
return 0;

}
