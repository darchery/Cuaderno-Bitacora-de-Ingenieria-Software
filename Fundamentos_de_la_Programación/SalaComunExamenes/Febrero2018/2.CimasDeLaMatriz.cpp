#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int F = 3;
const int C = 3;
typedef array<int, C> TFila;
typedef array<TFila, F> TMatriz;

void leerMatriz(TMatriz& mat)
{
    for (int i = 0;i < F ;i++ )
    {
        for (int j = 0;j < C ;j++ )
        {
            cin >> mat[i][j];
        }
    }
}

bool celdaValida(int fila, int col)
{
    return fila >= 0 && fila < F && col >= 0 && col < C;
}


void numeroVecinos(const TMatriz& mat, int num, int fila, int col, bool& siEs)
{
    for (int i = fila - 1;i <= fila + 1 && siEs;i++ )
    {
        for (int j = col - 1;j <= col + 1 && siEs;j++ )
        {
            if (celdaValida(i,j) && !(fila == i && col == j) && num < mat[i][j] &&
                 !(fila - 1 == i && col - 1 == j) &&
                 !(fila + 1 == i && col + 1 == j) &&
                 !(fila - 1 == i && col + 1 == j) &&
                 !(fila + 1 == i && col - 1 == j))
            {
                siEs = false;
            }
        }
    }
}

// Un valor de una matriz es una cima si todos sus vecinos menos las diagoanles son menores o igual que el

bool esCima(const TMatriz& mat, int num, int& fila, int& col)
{
    bool siEs = true;

    numeroVecinos(mat,num,fila,col,siEs);
    return siEs;
}

int main(){
    TMatriz mat;

    cout << "Introduzca una matriz (" << F << " x " << C << ") fila por fila: " << endl;
    leerMatriz(mat);
    cout << "Salida: Las cimas de la matriz son: " << endl;
    for (int i = 0;i < F ;i++ )
    {
        for (int j = 0;j < C ;j++ )
        {
            if (esCima(mat, mat[i][j], i, j))
            {
                cout << "Fila: " << i << ", Columna: " << j << ", Valor: " << mat[i][j] << endl;
            }
        }
    }
return 0;

}

/*
void numeroVecinos(const TMatriz& mat, int num, int fila, int col, bool& siEs)
{
    // Arriba
    if (celdaValida(fila-1,col) &&  num < mat[fila-1][col])
    {
        siEs = false;
    }
    // Abajo
    if (celdaValida(fila+1,col) &&  num < mat[fila+1][col])
    {
        siEs = false;
    }
    // Izquierda
    if (celdaValida(fila,col-1) &&  num < mat[fila][col-1])
    {
        siEs = false;
    }
    // Derecha
    if (celdaValida(fila,col+1) &&  num < mat[fila][col+1])
    {
        siEs = false;
    }
}*/
