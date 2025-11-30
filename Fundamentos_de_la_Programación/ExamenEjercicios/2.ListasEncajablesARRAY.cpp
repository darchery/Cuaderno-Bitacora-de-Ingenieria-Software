#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 5;
typedef array<int, MAX> TVector;

struct TLista {
    TVector vec;
    int tamVec = 0;
};


void leerVector(TLista& lista)
{
    int num;

    cout << "Introduzca la lista: ";
    cin >> num;
    while (num != 0 && lista.tamVec < MAX)
    {
        lista.vec[lista.tamVec] = num;
        lista.tamVec++;
        cin >> num;
    }
    cout << endl;
}

bool sonEncajables(TLista& lista1, TLista& lista2)
{
    bool encajables = true;

    for (int i = 0;i < lista1.tamVec && encajables;i++ )    // COJE 2 NUMEROS POSITIVOS DE LA 1 Y 2
    {                                                       // Y LOS COMPARA  SI NO SON IGUALES PARA EL PROGRAMA
        if (lista1.vec[i] > 0)                              // SI SON IGUALES LOS PONE A CERO Y PARA EL BUCLE PARA ELEGIR OTRO
        {
            for (int j = 0;j < lista2.tamVec && encajables && lista1.vec[i] != 0 ;j++ )
            {
                if (lista2.vec[j] > 0)
                {
                    /*cout << "Lista 1: " << lista1.vec[i] << "   Indice: " << i << endl;
                    cout << "Lista 2: " << lista2.vec[j] << "   Indice; " << j << endl;
                    cout << endl;*/
                    if (lista1.vec[i] != lista2.vec[j])
                    {
                        encajables = false;
                    }
                    lista1.vec[i] = 0;
                    lista2.vec[j] = 0;
                }
            }
        }
    }
    return encajables;
}

void analizarListas(TLista& lista1, TLista& lista2)
{
    cout << "lista1 = ";
    for (int i = 0;i < lista1.tamVec ;i++ )
    {
        cout << lista1.vec[i] << " ";
    }
    cout << endl;

    cout << "lista2 = ";
    for (int i = 0;i < lista2.tamVec;i++ )
    {
        cout << lista2.vec[i] << " ";
    }
    cout << endl;
    if (sonEncajables(lista1, lista2))
    {
        cout << "Las listas SI son encajables" << endl;
    }
    else
    {
        cout << "Las listas NO son encajables" << endl;
    }
}

int main(){
    TLista lista1, lista2;

    leerVector(lista1);
    leerVector(lista2);
    analizarListas(lista1, lista2);
return 0;

}
