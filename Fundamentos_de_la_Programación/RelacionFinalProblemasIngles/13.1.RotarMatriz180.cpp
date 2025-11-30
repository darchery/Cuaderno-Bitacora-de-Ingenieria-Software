#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N = 5;
typedef array<int, N> TFila;
typedef array<TFila, N> TMatriz;

void leerMatriz(TMatriz& mat)
{
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            cin >> mat[i][j];
        }
    }
}

void girar(TMatriz& mat,TMatriz& aux)
{
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            aux[N-1-i][N-1-j] = mat[i][j];
        }
    }
}

void escribirMatriz(TMatriz& mat)
{
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    TMatriz mat, aux;

    cout << "Introduzca una matriz de (" << N << " x " << N << ") fila por fila: " << endl;
    leerMatriz(mat);
    girar(mat, aux);
    cout << "La matriz girada: " << endl;
    escribirMatriz(aux);
return 0;

}

/*
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

25 24 23 22 21
20 19 18 17 16
15 14 13 12 11
10 9 8 7 6
5 4 3 2 1

21 22 23 24 25
16 17 18 19 20
11 12 13 14 15
6 7 8 9 10
1 2 3 4 5
*/
