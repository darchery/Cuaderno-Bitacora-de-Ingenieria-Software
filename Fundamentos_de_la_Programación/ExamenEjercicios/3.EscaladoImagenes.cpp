#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int F = 2;
const int C = 3;
typedef array<int,C> TFila;
typedef array<TFila,F> TMatrizM;

typedef array<TFila, 2*F> TMatrizT;

void leerMatriz(TMatrizM& matM)
{
    for (int i = 0;i < F ;i++ )
    {
        for (int j = 0;j < C ;j++ )
        {
            cin >> matM[i][j];
        }
    }
}

int mediaM(const TMatrizM& matM)
{
    int suma = 0;

    for (int i = 0;i < F ;i++ )
    {
        for (int j = 0;j < C ;j++ )
        {
            suma += matM[i][j];
        }
    }
    return suma / (F * C);
}

bool celdaValida(int fila , int col)
{
    return fila >= 0 && fila < 2*F && col >= 0 && col < C;
}

int mediaSumaVecinos(const TMatrizT& matT, int media, int fila, int col)
{
    int suma = 0;
    int numVecinos = 0;

    for (int i = fila - 1;i <= fila + 1 ;i++ )
    {
        for (int j = col - 1;j <= col + 1 ;j++ )
        {
            if ((fila != i || col != j) && celdaValida(i,j))
            {
                numVecinos++;
                if (matT[i][j] == 0)
                {
                    suma += media;
                }
                else
                {
                    suma += matT[i][j];
                }
            }
        }
    }
    return suma / numVecinos;
}

void escaladoImgagen(const TMatrizM& matM, TMatrizT& matT)
{
    int media = mediaM(matM);
    int cnt = 0;

    // Filas pares de M en T
    for (int i = 0;i < (2*F) ;i++ )
    {
        for (int j = 0;j < C ;j++ )
        {
            if (i % 2 == 0)
            {
                matT[i][j] = matM[i-cnt][j];
            }
        }
        if (i % 2 != 0)
        {
            cnt++;
        }
    }

    // Hago las cosas por separado ya que sino los vecinos van cambiando a media que se analiza
    // Necesito la matriz T con las filas impares vacias acabada

    // MediaVecinos en impares de T
    for (int i = 0;i < 2*F ;i++ )
    {
        for (int j = 0;j < C ;j++ )
        {
            if (i % 2 != 0)
            {
                matT[i][j] = mediaSumaVecinos(matT,media,i,j);
            }
        }
    }
}

void escribirMatrizT(const TMatrizT& matT)
{
    for (int i = 0;i < 2*F ;i++ )
    {
        for (int j = 0;j < C ;j++ )
        {
            cout << matT[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    TMatrizM matM;
    TMatrizT matT = {{}};

    cout << "Introduzca la matriz M (" << F << " x " << C << "): " << endl;
    leerMatriz(matM);
    escaladoImgagen(matM,matT);
    cout << "La matriz T (" << 2*F << " x " << C << " es la siguiente: " << endl;
    escribirMatrizT(matT);
return 0;

}
