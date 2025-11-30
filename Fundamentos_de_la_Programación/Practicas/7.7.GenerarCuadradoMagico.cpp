#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N = 5;
const int NUM_VALORES = N * N;
typedef array<int, N> TFila;
typedef array<TFila, N> TMatriz;

/*
Modos de funcionamiento:
1. Imprimir numeros en diagonal hacia la izquierda(restandocindex) hasta que se salga
    1.1. Vacio: se imprimen los numeros
    1.2. Ocupado: se baja una posicon hacia abajo, (se le suma uno a fila)
    1.3. Se sale:
*/

void cuadradoMagico(TMatriz& matriz)
{
    int col = N/2;  // Posicion inicial en la que empieza el cuadrado
    int fila = 0;
    int num = 1;

    while (num <= NUM_VALORES)
    {
        // Primera posicion
        if (num == 1)
        {
            matriz[fila][col] = num;
            fila--;
            col--;
        }
        // Si la casilla anterior esta vacia
        else if (matriz[col-1][fila-1] == 0)
        {
            fila--;
            col--;
            matriz[col][fila] = num;
            fila--;
            col--;
        }
        // Si se sale por la fila
        else if (fila < 0)
        {
            fila = N - 1;
            col--;
            matriz[fila][col] = num;
            fila--;
            col--;
        }
        // Si se sale por la columna
        else if (col < 0)
        {
            fila--;
            col = N - 1;
            matriz[fila][col] = num;
            fila--;
            col--;
        }
        // Si la casilla anterior ya esta ocupa
        else if (matriz[fila-1][col-1] != 0)
        {
            fila--;
            matriz[fila][col] = num;
            fila--;
            col--;
        }
        num++;
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
