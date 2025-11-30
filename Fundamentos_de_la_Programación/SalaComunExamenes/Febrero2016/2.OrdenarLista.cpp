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

int tope(const TArray& arr)
{
    int mayorTope = arr[0];

    for (int i = 1;i < TAM ;i++ )
    {
        if (mayorTope < arr[i])
        {
            mayorTope = arr[i];
        }
    }
    return mayorTope++;
}


int menor(TArray& arr)
{
    int TOPE = tope(arr);
    int menorACT = TOPE;
    int indexTachado = 0;

    for (int i = 0;i < TAM;i++ )
    {
        if (menorACT > arr[i])
        {
            menorACT = arr[i];
            indexTachado = i;
        }
    }
    arr[indexTachado] = TOPE;
    return menorACT;
}

void ordenar(TArray &arr, TArray& aux)
{
    for (int i = 0;i < TAM ;i++ )
    {
        aux[i] = menor(arr);
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
