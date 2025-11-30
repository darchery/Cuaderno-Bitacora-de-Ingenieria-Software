#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N = 5;
const int NUM_VALORES = N * N;
typedef array<int, N> TFila;
typedef array<TFila, N> TMatriz;

void buscarPosicion(TMatriz& matriz, int& fila, int& col)
{
    // Ajustar fila (se sale por arriba)
    if (fila == 0)
    {
        fila = N - 1;
    }
    else    // Si no se resta
    {
        fila--;
    }
    // Ajustar col (se sale por la izquierda)
    if (col == 0)
    {
        col = N - 1;
    }
    else    // Si no se resta
    {
        col--;
    }

    // Si la posicion ya está ocupada Bajar uno
    if (matriz[fila][col] != 0)
    {
        //Deshacer cambio
        if (col == N - 1)
        {
            col = 0;
        }
        else
        {
            col++;
        }
        if (fila == N -1)
        {
            fila = 0;
        }
        else
        {
            fila++;
        }
        // Sumar fila (bajar)
        if (fila == N -1)
        {
            fila = 0;
        }
        else
        {
            fila++;
        }
    }

}

void cuadradoMagico(TMatriz& matriz)
{
    int fila = 0;
    int col = N/2;

    matriz[fila][col] = 1;
    for (int i = 2;i <= NUM_VALORES ;i++ )
    {
        buscarPosicion(matriz,fila,col);
        matriz[fila][col] = i;
    }
}

void escribirCuadradoMagico(TMatriz& matriz)
{
    cout << "El cuadrado magico para N = " << N << " es: " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    TMatriz matriz = {{}};

    cuadradoMagico(matriz);
    escribirCuadradoMagico(matriz);
return 0;

}
