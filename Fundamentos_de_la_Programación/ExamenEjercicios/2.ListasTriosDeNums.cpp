#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 10;
typedef array<int, TAM> TVector;

struct TLista {
    TVector vec;
    int tamVec = 0;
};

void leerLista(TLista& lista, int i)
{
    int num;

    cout << "Introduzca la Lista " << i << ": ";
    cin >> num;
    while (num != 0 && lista.tamVec < TAM )
    {
        lista.vec[lista.tamVec] = num;
        lista.tamVec++;
        cin >> num;
    }
}

bool seRepite(TLista& lista, int num)
{
    bool seRepite = false;
    int repes = 0;

    for (int i = 0;i < lista.tamVec ;i++ )
    {
        if (num == lista.vec[i])
        {
            repes++;
        }
    }
    if (repes > 1)
    {
        seRepite = true;
    }
    return seRepite;
}

void cribarLista(TLista& lista,int n) // Si hay elementos repetidos mas de 2 veces el programa no funciona, hay que contar las repes en seRepite y en criba hacer repes ciclos
{
    int index;

    for (int i = 0;i < lista.tamVec ;i++ )
    {
        index = i + 1;
        if (seRepite(lista, lista.vec[i]))
        {
            // Aquí busca el numero repepetido
            while (lista.vec[i] != lista.vec[index])
            {
                index++;
            }

            //Va a elimnarlo y a cambiar de posicion a los demas
            while (index < lista.tamVec)
            {
                lista.vec[index] = lista.vec[index + 1];
                index++;
            }
            lista.tamVec--;
        }
    }
    cout << "Lista " << n << ": ";
    for (int i = 0;i < lista.tamVec ;i++ )
    {
        cout << lista.vec[i] << " ";
    }
    cout << endl;
}

/*
3 -2 3 5 -2 0
6 3 4 18 0
2 4 3 5 8 6 13 9 1 38 7 14 0
*/

void triosNums(TLista& lista1, TLista& lista2, TLista& lista3)
{
    cout << "Los trios de numeros son: " << endl;
    for (int i = 0;i < lista1.tamVec ;i++ )
    {
        for (int j = 0;j < lista2.tamVec ;j++ )
        {
            for (int k = 0;k < lista3.tamVec ;k++ )
            {
                if (lista1.vec[i] + lista2.vec[j] == lista3.vec[k])
                {
                    cout << lista1.vec[i] << " + " << lista2.vec[j] << " = " << lista3.vec[k] << endl;
                }
            }
        }
    }
}

int main(){
    TLista lista1, lista2, lista3;

    leerLista(lista1, 1);
    leerLista(lista2, 2);
    leerLista(lista3, 3);
    cribarLista(lista1, 1);
    cribarLista(lista2, 2);
    cribarLista(lista3, 3);
    triosNums(lista1, lista2, lista3);
return 0;

}
