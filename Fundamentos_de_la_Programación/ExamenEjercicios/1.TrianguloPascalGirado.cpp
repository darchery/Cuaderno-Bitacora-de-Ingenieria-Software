#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 7;
typedef array<int, TAM> TFila;
typedef array<TFila, TAM> TMatriz;

void inicializarMatriz(TMatriz& mat)
{
    for (int i = 0;i < TAM ;i++ )
    {
        mat[0][i] = 1;
        mat[i][0] = 1;
    }
}

void trianguloPascal(TMatriz& mat)
{
    int cnt = 0;

    for (int i = 1;i < TAM - 1;i++ )
    {
        for (int j = 1;j < TAM - 1 - cnt;j++ )
        {
            mat[i][j] = mat[i-1][j] + mat[i][j-1];
        }
        cnt++;
    }
}

void imprimirMatriz(const TMatriz& mat)
{

    for (int i = 0;i < TAM ;i++ )
    {
        for (int j = 0;j < TAM ;j++ )
        {
            if (mat[i][j] != 0)
            {
                cout << mat[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    TMatriz mat = {{}};

    inicializarMatriz(mat);
    trianguloPascal(mat);
    imprimirMatriz(mat);
return 0;

}
