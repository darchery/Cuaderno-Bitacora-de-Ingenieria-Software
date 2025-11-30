#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 5;
typedef array<int, TAM> TArray;

bool esPrimo(int num)
{
    bool siEs = true;

    if (num == 1)
    {
        siEs = false;
    }
    else
    {
        for (int i = 2;i < num && num != 2 && siEs;i++ )
        {
            if (num % i == 0)
            {
                siEs = false;
            }
        }
    }
    return siEs;
}

void menorEstricto(const TArray& arr, bool& siHay, int& menorEstric)
{
    siHay = true;
    menorEstric = arr[0];

    for (int i = 1;i < TAM ;i++ )
    {
        if (menorEstric == arr[i])
        {
            siHay = false;
        }
        else if (menorEstric > arr[i])
        {
            menorEstric = arr[i];
            siHay = true;
        }
    }
}

void esMenorEstrictoPrimo(const TArray& arr)
{
    int menorEstric;
    bool esMenorPrimo;

    menorEstricto(arr,esMenorPrimo,menorEstric);
    if (esMenorPrimo && esPrimo(menorEstric))
    {
        cout << "Si hay un menor estricto primo que es: " << menorEstric << endl;
    }
    else
    {
        cout << "NO hay menor estricto primo" << endl;
    }
}

int main(){

    TArray arr1 = {{2,7,3,4,5}};
    TArray arr2 = {{5,5,3,4,5}};
    TArray arr3 = {{2,5,6,2,5}};

    esMenorEstrictoPrimo(arr1);
    esMenorEstrictoPrimo(arr2);
    esMenorEstrictoPrimo(arr3);
return 0;

}
