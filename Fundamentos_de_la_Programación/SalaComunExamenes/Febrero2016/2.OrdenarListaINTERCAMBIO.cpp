#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 8;
typedef array<int, TAM> TArray;

void escribirArray(TArray arr)
{
    for (int i = 0;i < TAM ;i++ )
    {
        cout << arr[i] << " ";
    }
}

void intercambiar(int& x, int& y)
{
    int aux;
    aux = x;
    x = y;
    y = aux;
}

int menorIndice(const TArray& arr, int comienzo)
{
    int menor = arr[comienzo];
    int index = comienzo;

    for (int i = comienzo;i < TAM ;i++ )
    {
        if (menor > arr[i])
        {
            menor = arr[i];
            index = i;
        }
    }
    return index;
}

void ordenar(TArray& arr)
{
    int menorIndex;

    for (int i = 0;i < TAM ;i++ )
    {
        menorIndex = menorIndice(arr,i);
        intercambiar(arr[i], arr[menorIndex]);
    }
}

int main(){
    TArray arr1 = {2,7,12,89,5,2,9,10};

    cout << "El array antes de ordenarlo: ";
    escribirArray(arr1);
    cout << endl;
    ordenar(arr1);
    cout << "El array despues de ordenarlo: ";
    escribirArray(arr1);
return 0;

}
