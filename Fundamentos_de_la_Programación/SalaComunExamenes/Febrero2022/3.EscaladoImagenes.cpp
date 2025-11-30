#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int F = 2;
const int C = 3;
typedef array<int, C> TFila;
typedef array<TFila, F> TMatrizM;

typedef array<TFila, 2 * F> TMatrizT;

void leerMatriz(TMatrizM& matrizM)
{
    cout << "Introduzca la matriz M (" << F << " x " << C << "): " << endl;
    for (int i = 0;i < F ;i++ )
    {
        for (int j = 0;j < C ;j++ )
        {
            cin >> matrizM[i][j];
        }
    }
}

int calcularMediaM(TMatrizM& matrizM)
{
    int suma = 0;
    int numElementos = 0;

    for (int i = 0;i < F ;i++ )
    {
        numElementos += C;
        for (int j = 0;j < C ;j++ )
        {
            suma += matrizM[i][j];
        }
    }
    return suma/numElementos;
}

bool celdaValida(int fila, int col)
{
    return fila >= 0 && fila < 2*F && col >= 0 && col < C;
}

int mediaSumaVecinos(TMatrizT& matrizT, int fila, int col, int mediaM)
{
    int suma = 0, numVecinos = 0;

    for (int i = fila - 1;i <= fila + 1 ;i++ )
    {
        for (int j = col - 1;j <= col + 1 ;j++ )
        {
            if (celdaValida(i,j) && !(i == fila && j == col ))
            {
                numVecinos++;
                if (matrizT[i][j] == 0 )
                {
                    suma += mediaM;
                }
                else
                {
                    suma += matrizT[i][j];
                }
            }
        }
    }
    //cout << "En la fila " << fila << " " << col << " sale: " << suma/numVecinos << endl;
    return suma/numVecinos;
}

void calcularMatrizT(TMatrizM& matrizM, TMatrizT& matrizT)
{
    int mediaM = calcularMediaM(matrizM);
    int cnt = 0;

    // Meter filas M en filas pares T y poner a 0 cada fila impar
    for (int i = 0;i < (2 * F) ;i++ )
    {
        for (int j = 0;j < C ;j++ )
        {
            if (i % 2 != 0)
            {
                matrizT[i][j] = 0;
            }
            else
            {
                matrizT[i][j] = matrizM[i - cnt][j];
            }
        }
        if (i % 2 != 0)
        {
            cnt++;
        }
    }
    // Poner mediaVecinos en filas impares
    for (int i = 1;i < 2*F  ;i += 2 )
    {
        for (int j = 0;j < C ;j++ )
        {
            matrizT[i][j] = mediaSumaVecinos(matrizT, i, j, mediaM);
        }
    }
}

void escribirMatrizT(TMatrizT& matrizT)
{
    cout << "La matriz T (" << 2 * F << " x " << C << ")  es la siguiente: " << endl;
    for (int i = 0;i < (2 * F) ;i++ )
    {
        for (int j = 0;j < C ;j++ )
        {
            cout << matrizT[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    TMatrizM matrizM;
    TMatrizT matrizT;

    leerMatriz(matrizM);
    calcularMatrizT(matrizM, matrizT);
    escribirMatrizT(matrizT);
return 0;

}

/*
int suma3Vecinos(TMatrizT& matrizT, int fila, int col, int mediaM)
{
    int sumVecinos = 0;
    // Cada esquina es un caso diferente, 4 casos

    // Esquina superior izq
    if (fila == 0 && col == 0)
    {

    }
    // Esquina superior derecha
    else if (fila ==  0 && col == C - 1)
    {

    }
    // Esquina inferior izq
    else if (fila == 2*F - 1 && col == 0)
    {

    }
    // Esquina inferior derecha
    else if (fila == 2*F - 1 && col == C - 1)
    {

    }

    return sumVecinos;
}

int suma5Vecinos(TMatrizT& matrizT, int fila, int col, int mediaM)
{
    int sumVecinos = 0;

    // Casos laterales 2: izquierdo y derecho

    // Izquierdo
    if ()
    {

    }
    // Derecho
    else if ()
    {

    }
    // Superior
    else if ()
    {

    }

    else if ()
    {

    }
    return sumVecinos;
}

int suma8Vecinos(TMatrizT& matrizT, int fila, int col, int mediaM)
{
    int sumVecinos = 0;

    for (int i = fila - 1;i <= fila + 1 ;i++ )
    {
        for (int j = col - 1;j <= col + 1 ;j++ )
        {
            if (i >= 0 && i < 2*F && j >= 0 && j < C && (i != fila || j != col) )
            {
                if (matrizT[i][j] == 0)
                {
                    sumVecinos += mediaM;
                }
                else
                {
                    sumVecinos += matrizT[i][j];
                }
            }
        }
    }
    return sumVecinos/8;
}*/
/*
// Asignamos fila de T impares
     for (int i = 1;i < 2*F ;i += 2 )
     {
         for (int j = 0;j < C ;j++ )
         {
             // Interiores (8 vecinos)
             if (j == C/2 &&  i > 0 && i < 2*F - 1)
             {
                matrizT[i][j] = suma8Vecinos(matrizT, i, j, mediaM);
             }
            // Laterales (5 vecinoes)
             else if ( (col == 0 && fila > 0 && fila < 2*F - 1) || (col == C - 1 && fila > 0 && fila < 2*F - 1))
             {
                matrizT[i][j] = suma5Vecinos(matrizT, i, j, mediaM);
             }
             // Esquinas (3 vecinos)
             else if ()
             {
                matrizT[i][j] = suma3Vecinos(matrizT, i, j, mediaM);
             }
         }
     }
     */
