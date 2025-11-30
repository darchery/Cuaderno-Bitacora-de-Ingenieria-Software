#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 5;
typedef array<int, TAM> TArray;

int numeroRepeticiones(const TArray& arr ,int num)
{
    int numRepes = 0;

    for (int i = 0;i < TAM ;i++ )
    {
        if (num == arr[i])
        {
            numRepes++;
        }
    }
    return numRepes;
}

bool esta(TArray& aux, int num , int posAct)
{
    bool siEsta = false;

    for (int i = posAct - 1 ;i >= 0;i-- )
    {
        if (num == aux[i])
        {
            siEsta = true;
        }
    }
    return siEsta;
}

int valorDominante(const TArray& arr)
{
    int valDom = -1;
    int numRepesDom = -1;
    TArray aux = {{}};
    int index = 0;

    for (int i = 0;i < TAM ;i++ )
    {
        int repes = numeroRepeticiones(arr,arr[i]);
        if (!esta(aux,arr[i],index) && numRepesDom < repes && repes > TAM/2 )
        {
            valDom = arr[i];
            numRepesDom = repes;
            aux[index] = arr[i];
            index++;
        }
    }
    return valDom;
}

int main(){
    TArray arr1 = {{1, 2, 2, 2, 1}};
    int valDom = valorDominante(arr1);

    if (valDom == -1)
    {
        cout << "No exite valor dominante" << endl;
    }
    else
    {
        cout << "Lista 1: " << valDom << endl;
    }

    TArray arr2 = {{1, 2, 4, 5, 6}};
    valDom = valorDominante(arr2);

    if (valDom == -1)
    {
        cout << "No exite valor dominante" << endl;
    }
    else
    {
        cout << "Lista 2: " << valDom << endl;
    }
return 0;

}

