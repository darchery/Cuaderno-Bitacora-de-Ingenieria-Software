#include <iostream>
#include <array>
#include <math.h>

// PRIMERA VERSION: SIN CREAR UNA MATRIZ NUEVA

using namespace std;

const int N = 4;
typedef array<int, N> TFila;
typedef array<TFila, N> TMatriz;

typedef array<bool, N> TOcupa;
typedef array<TOcupa, N> TTachado;

const int M = N - 1;

void leerMatriz(TMatriz& matriz)
{
    cout << "Introduce los numeros enteros para una matriz cuadrada de " << N << " x " << N << ": " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            cin >> matriz[i][j];
        }
    }
}

void reducirMatriz(TTachado& tachado)
{
    int fila, col;
    cout << "Introduzca la fila y columna a eliminar: ";
    cin >> fila >> col;

    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            if (i == fila || j == col)
            {
                tachado[i][j] = true;
            }
        }
    }
}

void escribirMatriz(TMatriz& matriz, TTachado& tachado)
{
    int cnt = 0;

    cout << "La matriz construida " << M << " x " << M << " es: " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            if (cnt == M)
            {
                cout << endl;
                cnt = 0;
            }
            if (!tachado[i][j])
            {
                cout << matriz[i][j] << " ";
                cnt++;
            }
        }
    }
}

int main(){
    TMatriz matriz1;
    TTachado tachado = {{}};

    leerMatriz(matriz1);
    reducirMatriz(tachado);
    escribirMatriz(matriz1, tachado);
return 0;

}
