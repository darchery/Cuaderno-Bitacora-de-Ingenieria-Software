#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 20;
typedef array<int, MAX> TMontones;

struct TLista {
    TMontones monton;
    int nuMontones;
    int numMaxMontones;
};

bool montonesOrdenados(TLista& lista)
{
    int montonAnterior = lista.monton[0];
    bool ordenado = true;

    for (int i = 1;i < lista.nuMontones && ordenado;i++ )
    {
        if (montonAnterior + 1 != lista.monton[i])
        {
            ordenado = false;
        }
        montonAnterior = lista.monton[i];
    }
    return ordenado;
}

void escribirMontones(TLista& lista)
{
    for (int i = 0;i < lista.nuMontones ;i++ )
    {
        cout << lista.monton[i] << " ";
    }
    cout << endl;
}

bool hayUno(TLista& lista)
{
    bool hay = false;

    for (int i = 0;i < lista.nuMontones && !hay;i++ )
    {
        if (lista.monton[i] == 1)
        {
            hay = true;
        }
    }
    return hay;
}

void moverMontos(TLista& lista, int indexUno)
{

    while (indexUno < lista.nuMontones)
    {
        lista.monton[indexUno - 1] = lista.monton[indexUno];
        indexUno++;
    }
    /*if (lista.nuMontones < NMONTOS - 1)
    {*/
        lista.nuMontones--;
    //}
}

void calcularMontos(TLista& lista)
{
    int newMonto = 0;

    for (int i = 0;i < lista.nuMontones ;i++ )
    {
        lista.monton[i]--;
        newMonto++;
    }
    lista.nuMontones++;
    lista.monton[lista.nuMontones-1] = newMonto;
}

void maximoDeMontos(TLista& lista)
{
    int numTriangular = 0;
    int maxDivisor = 1;
    int sumaDivisores = 0;

    for (int i = 0;i < lista.nuMontones ;i++ )
    {
        numTriangular += lista.monton[i];
    }
    for (int i = 1;sumaDivisores < numTriangular ;i++ )
    {
        sumaDivisores += i;
        maxDivisor = i;
    }
    lista.numMaxMontones = maxDivisor;
    cout << lista.numMaxMontones << endl;
}

void solitarioBulgaro(TLista& lista)
{
    int index;

    //Calcula nuevo monto si NO HA LLEGADO AL MAXIMO DE MONTOS
    if (lista.nuMontones < lista.numMaxMontones)
    {
        calcularMontos(lista);
        escribirMontones(lista);
    }

    // Calcula nuevo monto, Elimina Monton de 1 y lo escribe
    if (!montonesOrdenados(lista) && hayUno(lista))
    {
        index = 0;
        // Si no está ordenado elimina el 1
        while (lista.monton[index] != 1)
        {
            index++;
        }
        // Mover pos
        calcularMontos(lista);
        escribirMontones(lista);
        moverMontos(lista,index + 1);
        escribirMontones(lista);
    }
}

int main(){
    TLista lista;

    do
    {
        cout << "Introduzca el numero de montones: ";
        cin >> lista.nuMontones;
    } while (lista.nuMontones > MAX || lista.nuMontones <= 0);
    cout << "Introduzca los montones: " << endl;
    for (int i = 0;i < lista.nuMontones ;i++ )
    {
        cin >> lista.monton[i];
    }
    maximoDeMontos(lista);
    while (!montonesOrdenados(lista) && lista.nuMontones < MAX)
    {
       solitarioBulgaro(lista);
    }
return 0;

}
