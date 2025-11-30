#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 5;
typedef array<int, TAM> TArray;

bool ordenado(TArray& arr)
{
    bool siEsta = true;

    for (int i = 1;i < TAM ;i++ )
    {
        if (arr[i-1] > arr[i])
        {
            siEsta = false;
        }
    }
    return siEsta;
}

int main(){
    TArray arr1 = {{1,3,5,7,10}};
    TArray arr2 = {{2,5,1,6,5}};

    if (ordenado(arr1))
    {
        cout << "El primer array SI esta ordenado" << endl;
    }
    else
    {
        cout << "El primer array NO esta ordenado" << endl;
    }
    if (ordenado(arr2))
    {
        cout << "El segundo array SI esta ordenado" << endl;
    }
    else
    {
        cout << "El segundo array NO esta ordenado" << endl;
    }
return 0;

}
