#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 10;
typedef array<int, TAM> TArray;

void leerArray(TArray& a)
{
    cout << "Introduzca " << TAM << " numeros enteros: ";
    for (int i = 0;i < TAM ;i++ )
    {
        cin >> a[i];
    }
}

int mayorLongitud(const TArray& a)
{
    int mayLong = 1;
    int mayLongAct = 1;

    for (int i = 1;i < TAM ;i++ )
    {
        if (a[i] >= a[i-1])
        {
            mayLong++;
            if (mayLong > mayLongAct)
            {
                mayLongAct = mayLong;
            }
        }
        else
        {
            mayLong = 1;
        }
    }
    return mayLongAct;
}

int main(){
    TArray a;

    leerArray(a);
    cout << "La longitud de la mayor sub-sucesion es: " << mayorLongitud(a) << endl;
return 0;

}
