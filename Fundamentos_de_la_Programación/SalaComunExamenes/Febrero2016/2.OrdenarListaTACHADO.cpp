#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 8;
typedef array<int, TAM> TArray;
typedef array<bool , TAM> TTachado;

void escribirArray(TArray arr)
{
    for (int i = 0;i < TAM ;i++ )
    {
        cout << arr[i] << " ";
    }
}

void escribirTachado(const TTachado& tachado)
{
    for (int i = 0;i < TAM ;i++ )
    {
        cout << boolalpha << tachado[i] << " ";
    }
    cout << endl;
}

// Esta funcion solo sirve si quiero ordenarla de mayor a menor, y tampoco, porque si el mayor lo encuentra primero, no avanzar�, asi que No FUNCIONA

int menor(TArray& arr, TTachado& tachado)
{
    int menorACT = arr[0];
    int indexTachado = 0;

    for (int i = indexTachado + 1;i < TAM;i++ )
    {
        if (!tachado[i])
        {
            if (menorACT > arr[i])
            {
                menorACT = arr[i];
                indexTachado = i;
            }
        }
    }
    tachado[indexTachado] = true;
    escribirTachado(tachado);
    return menorACT;
}

void ordenar(TArray &arr, TArray& aux)
{
   TTachado tachado = {{}};

    for (int i = 0;i < TAM ;i++ )
    {
        aux[i] = menor(arr,tachado);
    }
}

int main(){
    TArray arr1 = {2,7,12,89,5,2,9,10};
    TArray aux;

    cout << "El array antes de ordenarlo: ";
    escribirArray(arr1);
    cout << endl;
    ordenar(arr1, aux);
    cout << "El array despues de ordenarlo: ";
    escribirArray(aux);
return 0;

}
