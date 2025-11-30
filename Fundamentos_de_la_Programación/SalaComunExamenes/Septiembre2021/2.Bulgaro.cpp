#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_NUM_MONTS = 20;
typedef array<int ,MAX_NUM_MONTS> TMontones;

struct TLista {
    TMontones montones;
    int numMontones;
    int maximoMontos;
};

int montoMaximo(TLista& lista)
{
    int numCartas = 0;
    int montMaximo = 0;

    for (int i = 0;i < lista.numMontones ;i++ )
    {
        numCartas += lista.montones[i];
    }
    int cnt = 0;
    for (int i = 1;cnt < numCartas ;i++ )
    {
        cnt += i;
        montMaximo = i;
    }
    return montMaximo;
}

bool montonesOrdenados(TLista& lista)
{
    bool ordenado = true;

    for (int i = 1;i < lista.numMontones ;i++ )
    {
        if (lista.montones[i] < lista.montones[i-1])
        {
            ordenado = false;
        }
    }
    return ordenado;
}

void escribirMonto(const TLista& lista)
{
    for (int i = 0;i < lista.numMontones ;i++ )
    {
        cout << lista.montones[i] << " ";
    }
    cout << endl;
}

void crearNuevoMonto(TLista& lista)
{
    int nuevoMonto = 0;

    for (int i = 0;i < lista.numMontones ;i++ )
    {
        lista.montones[i]--;
        nuevoMonto++;
    }
    lista.numMontones++;
    lista.montones[lista.numMontones - 1] = nuevoMonto;
}

void moverMonto(TLista& lista, int posAct)
{
    for (int i =  posAct;i < lista.numMontones ;i++ )
    {
        lista.montones[i] = lista.montones[i+1];
    }
    lista.numMontones--;
}

void solitarioBulgaro(TLista& lista)
{
    if (lista.numMontones < lista.maximoMontos)
    {
        crearNuevoMonto(lista);
        escribirMonto(lista);
    }
    else
    {
        int index = 0;

        crearNuevoMonto(lista);
        while (lista.montones[index] != 0)
        {
            index++;
        }
        moverMonto(lista,index);
        escribirMonto(lista);
    }
}

int main(){
    TLista lista;

    cout << "Introduzca el numero de montones inicial: ";
    cin >> lista.numMontones;
    cout << "Introduzca los montones: " << endl;
    for (int i = 0;i < lista.numMontones ;i++ )
    {
        cin >> lista.montones[i];
    }
    lista.maximoMontos = montoMaximo(lista);
    while (!montonesOrdenados(lista) && lista.numMontones < MAX_NUM_MONTS)
    {
        solitarioBulgaro(lista);
    }
return 0;

}
