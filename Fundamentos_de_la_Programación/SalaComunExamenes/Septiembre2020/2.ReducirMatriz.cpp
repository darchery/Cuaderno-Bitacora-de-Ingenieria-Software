#include <iostream>
#include <array>
#include <math.h>

// PRIMERA VERSION: SIN CREAR UNA MATRIZ NUEVA

using namespace std;

const int N = 4;
const int M = N - 1;

// Aqui sobra una estructura
typedef array<int, N> TFila1;
typedef array<TFila1, N> TMatriz1;
typedef array<int, M> TFila2;
typedef array<TFila2, M> TMatriz2;



void leerMatriz(TMatriz1& matriz1)
{
    cout << "Introduce los numeros enteros para una matriz cuadrada de " << N << " x " << N << ": " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            cin >> matriz1[i][j];
        }
    }
}

void reducirMatriz(const TMatriz1& matriz1, TMatriz2& matriz2)
{
    int fila, col;
    int index = 0, jIndex = 0;

    cout << "Introduzca la fila y columna a eliminar: ";
    cin >> fila >> col;

    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            if (i != fila && j != col)
            {
                matriz2[index][jIndex] = matriz1[i][j];
                jIndex++;
            }
        }
        if (i != fila)
        {
            index++;
        }
        jIndex = 0;
    }
}

void escribirMatriz(const TMatriz2& matriz2)
{
    int cnt = 0;

    cout << "La matriz construida " << M << " x " << M << " es: " << endl;
    for (int i = 0;i < M ;i++ )
    {
        for (int j = 0;j < M ;j++ )
        {
            if (cnt == M)
            {
                cout << endl;
                cnt = 0;
            }
            cout << matriz2[i][j] << " ";
            cnt++;
        }
    }
}

int main(){
    TMatriz1 matriz1;
    TMatriz2 matriz2;

    leerMatriz(matriz1);
    reducirMatriz(matriz1, matriz2);
    escribirMatriz(matriz2);
return 0;

}


/*
    4 -8 32 15
    12 9 -5 -8
    -4 7 41 65
    6 45 -8 92
*/
