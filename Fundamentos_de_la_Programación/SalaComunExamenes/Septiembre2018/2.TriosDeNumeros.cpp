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

bool esta(TLista& lista, int num, int posAct)
{
    bool siEsta = false;

    for (int i = posAct - 1;i >= 0 && !siEsta;i-- )
    {
        if (num == lista.vec[i])
        {
           siEsta = true;
        }
    }
    return siEsta;
}

void leerLista(TLista& lista)
{
    int cadena;

    cin >> cadena;
    while (cadena != 0)
    {
        if (!esta(lista,cadena,lista.tamVec) && lista.tamVec  < TAM)
        {
            lista.vec[lista.tamVec] = cadena;
            lista.tamVec++;
        }
        cin >> cadena;
    }
}

void escribirLista(const TLista& lista)
{
    for (int i = 0;i < lista.tamVec ;i++ )
    {
        cout << lista.vec[i] << " ";
    }
}

void triosNumeros(const TLista& lista_1, const TLista& lista_2, const TLista& lista_3)
{
    for (int i = 0;i < lista_1.tamVec ;i++ )
    {
        for (int j = 0;j < lista_2.tamVec ;j++ )
        {
            for (int k = 0;k < lista_3.tamVec ;k++ )
            {
                if (lista_1.vec[i] + lista_2.vec[j] == lista_3.vec[k])
                {
                    cout << lista_1.vec[i] << " + " << lista_2.vec[j]
                    << " = " << lista_3.vec[k] << endl;
                }
            }
        }
    }
}

int main(){
    TLista lista_1, lista_2, lista_3;

    cout << "Introduzca lista 1: ";
    leerLista(lista_1);
    cout << "Introduzca lista 2: ";
    leerLista(lista_2);
    cout << "Introduzca lista 3: ";
    leerLista(lista_3);
    cout << endl;

    cout << "Lista 1: ";
    escribirLista(lista_1);
    cout << endl;
    cout << "Lista 2: ";
    escribirLista(lista_2);
    cout << endl;
    cout << "Lista 3: ";
    escribirLista(lista_3);
    cout << endl;

    cout << "Los trios de numeros son:" << endl;
    triosNumeros(lista_1,lista_2,lista_3);
return 0;

}
