#include <iostream>
#include <array>

using namespace std;

const int N = 4;
const int M = 5;
typedef array<int, M> TFilas;
typedef array<TFilas, N> TMatriz;

void leerMatriz(TMatriz& matriz)
{
    cout << "Introduzca por filas una matriz (" << N << " x " << M << ")" << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < M ;j++ )
        {
            cin >> matriz[i][j];
        }
    }
}

void mayorElemento(TMatriz& matriz)
{
    int posFila = 0, posCol = 0;
    int mayor = matriz[0][0];

    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < M ;j++ )
        {
            if (mayor < matriz[i][j])
            {
                mayor = matriz[i][j];
                posFila = i;
                posCol = j;
            }
        }
    }
    cout << "El mayor de la matriz es: " << mayor << " que aparece en la poscion [" << posFila << "] " << "[" << posCol << "]" << endl;
}

int main() {
    TMatriz matriz1;

    leerMatriz(matriz1);
    mayorElemento(matriz1);
    return 0;
}
