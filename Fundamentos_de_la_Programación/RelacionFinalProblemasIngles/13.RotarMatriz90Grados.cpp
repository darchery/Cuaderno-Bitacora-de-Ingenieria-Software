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
            aux[j][N-i-1] = mat[i][j];
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
    girar(aux, mat);
    cout << "La matriz girada: " << endl;
    escribirMatriz(mat);
return 0;

}
