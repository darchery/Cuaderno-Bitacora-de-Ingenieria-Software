#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N = 4;
const int M = 3;
typedef array<int, M> TFila;
typedef array<TFila, N> TImagen;

void leerMatriz(TImagen& ima)
{
    cout << "Introduzca las intesidades luminonas en forma de matriz (" << N << " x " << M << "): " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < M ;j++ )
        {
            cin >> ima[i][j];
        }
    }
}

bool celdaValida(int fila, int col)
{
    return fila >= 0 && fila < N && col >= 0 && col < M;
}

int sumaVecinosCercanos(const TImagen& ima, int fila, int col)
{
    int suma = 0;
    int numVecinos = 0;

    for (int i = fila - 1;i <= fila + 1 ;i++ )
    {
        for (int j = col - 1;j <= col + 1 ;j++ )
        {
            if (celdaValida(i,j))
            {
                numVecinos++;
                suma += ima[i][j];
            }
        }
    }
    return suma/numVecinos;
}

TImagen suavizado(TImagen& ima)
{
    TImagen imaAux;

    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < M ;j++ )
        {
            imaAux[i][j] = sumaVecinosCercanos(ima,i,j);
        }
    }
    return imaAux;
}

void escribirMatriz(TImagen& ima)
{
    cout << "La matriz de intensidad suavizada: " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < M ;j++ )
        {
            cout << ima[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    TImagen ima, imaAux;

    leerMatriz(ima);
    imaAux = suavizado(ima);
    escribirMatriz(imaAux);
return 0;

}
/*
3 2 5
7 8 6
9 3 2
4 3 1
*/
