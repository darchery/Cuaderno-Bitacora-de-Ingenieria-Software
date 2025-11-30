#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 4;

typedef array<int, MAX> TFilas;
typedef array<TFilas, MAX> TMatriz;

void leerMatriz(TMatriz& a)
{
    cout << "Introduzca la matriz fila a fila (" << MAX << " x " << MAX << "): ";
    for (int i = 0;i < MAX ;i++ )
    {
        for (int j = 0;j < MAX ;j++ )
        {
            cin >> a[i][j];
        }
    }
}

int sumaDiagonal(TMatriz& a)
{
    int suma = 0;

    for (int i = 0;i < MAX ;i++ )
    {
        suma += a[i][i];
    }
    /*for (int i = 0;i < MAX ;i++ )
    {
        for (int j = 0;j < MAX ;j++ )
        {
           if (i == j)
           {
               suma += a[i][j];
           }
        }
    }*/
    return suma;
}

int main(){
    TMatriz a1;

    leerMatriz(a1);
    cout << "La suma de la diagonal principal es: " << sumaDiagonal(a1) << endl;
return 0;

}
