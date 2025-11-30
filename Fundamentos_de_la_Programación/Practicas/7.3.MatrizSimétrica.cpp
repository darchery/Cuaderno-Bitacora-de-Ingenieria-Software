#include <iostream>
#include <array>

using namespace std;

const int N = 4;
typedef array<int, N> TFilas;
typedef array<TFilas, N> TMatriz;

void leerMatriz(TMatriz& matriz)
{
    cout << "Introduzca por filas una matriz (" << N << " x " << N << ")" << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            cin >> matriz[i][j];
        }
    }
}

bool esSimetrica(TMatriz& matriz)
{
    bool simetrica = true;

    for (int i = 0;i < N && simetrica ;i++ )
    {
        for (int j = 0;j < N && simetrica;j++ )
        {
            if (i != j && matriz[i][j] != matriz[j][i])
            {
                simetrica = false;
            }
        }
    }
    return simetrica;
}

int main() {
    TMatriz matriz1;

    leerMatriz(matriz1);
    if (esSimetrica(matriz1))
    {
        cout << "Es simetrica" << endl;
    }
    else
    {
        cout << "No es simetrica" << endl;
    }
    return 0;
}
