#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_NUM_DIST = 15;

struct TDatosNum {
    int numero;
    int frec = 0;
};

typedef array<TDatosNum, MAX_NUM_DIST> TNumero;

struct TLista {
    TNumero sec;
    int nElemen = 0;
};

int buscarIndex(const TLista& lista, int num, int posAct)
{
    int index = -1;
    bool found = false;

    for (int i = posAct - 1;i >= 0 && !found;i-- )
    {
        if (num == lista.sec[i].numero)
        {
            index = i;
            found = true;
        }
    }
    return index;
}

void procesarNumero(TLista& lista, int num)
{
    int index = buscarIndex(lista,num,lista.nElemen);

    // Primera aparicion
    if (index == -1)
    {
        lista.sec[lista.nElemen].numero = num;
        lista.sec[lista.nElemen].frec++;
        lista.nElemen++;
    }
    // Demas aparciones
    else
    {
        lista.sec[index].frec++;
    }
}

void escribirLista(const TLista& lista)
{
    for (int i = 0;i < lista.nElemen ;i++ )
    {
        cout << lista.sec[i].numero << ": " << lista.sec[i].frec << endl;
    }
}

int main(){
    TLista lista;
    int num;

    cout << "Introduzca una secuencia de numeros acabada en 0: " << endl;
    cin >> num;

    while (num != 0)
    {
        procesarNumero(lista,num);
        cin >> num;
    }
    escribirLista(lista);
return 0;

}


// 45 7 38 33 1 1 45 46 45 73 73 2 0
