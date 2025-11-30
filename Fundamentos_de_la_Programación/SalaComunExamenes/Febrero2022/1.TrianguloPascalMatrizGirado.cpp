#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 7;
typedef array<int, TAM> TFila;
typedef array<TFila, TAM> TMatriz;

void inicializarMatriz(TMatriz& matriz)
{
    int fila = 0, col = 0;

    for (int i = 0;i < TAM ;i++ )
    {
        matriz[fila][i] = 1;
        matriz[i][col] = 1;
    }
}

void sumarDosSuperiores(TMatriz& matriz)
{
    int fila = 1, col = 1;
    int cnt = 0;

    for (int i = fila ;i < TAM - 1;i++ )
    {
        for (int j = col ;j < TAM - 1 - cnt;j++ )
        {
            matriz[i][j] = matriz[i-1][j] + matriz[i][j-1];
        }
        cnt++;
    }
}

void escribirTriangulo(TMatriz& matriz)
{
    cout << "Triangulo de pascal girado 45 grados: " << endl;
    for (int i = 0;i < TAM;i++ )
    {
        for (int j = 0;j < TAM ;j++ )
        {
            if (matriz[i][j] != 0 /*&& matriz[i][j] <= 20*/)
            {
                cout << matriz[i][j] << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main(){
    TMatriz matriz = {{}};

    inicializarMatriz(matriz);
    sumarDosSuperiores(matriz);
    escribirTriangulo(matriz);
return 0;

}
