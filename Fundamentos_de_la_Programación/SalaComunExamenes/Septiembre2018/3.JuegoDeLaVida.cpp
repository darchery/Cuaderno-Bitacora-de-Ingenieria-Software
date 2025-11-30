#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const char VIVO = 'x';
const char VACIO = 'o';

const int TAM = 5;
typedef array<char,TAM> TFila;
typedef array<TFila, TAM> TMatriz;

void leerGeneracion(TMatriz& mat)
{
    for (int i = 0;i < TAM ;i++ )
    {
        for (int j = 0;j < TAM ;j++ )
        {
            cin >> mat[i][j];
        }
    }
}

bool celdaValida(int fila, int col)
{
    return fila >= 0 && fila < TAM && col >= 0 && col < TAM;
}

int numeroVecinosVivos(const TMatriz& mat, int fila, int col)
{
    int numVecinos = 0;

    for (int i = fila - 1;i <= fila + 1 ;i++ )
    {
        for (int j = col - 1;j <= col + 1;j++ )
        {
            if (!(i == fila && j == col) && celdaValida(i,j) && mat[i][j] == VIVO)
            {
                numVecinos++;
            }
        }
    }
    return numVecinos;
}

/*
1. Si vacia -> vivo si numVivos == 3, SI No vacia (numVivos != 3)
2. Si vivo -> vivo si numVivos == 2 || numVivos == 3, SI No VACIO
*/

void juegoDeLaVida( TMatriz& mat, TMatriz& aux)
{
    int numVecinos;

    for (int i = 0;i < TAM ;i++ )
    {
        for (int j = 0;j < TAM ;j++ )
        {
            numVecinos = numeroVecinosVivos(mat,i,j);
            if (mat[i][j] == VACIO )
            {
                if (numVecinos == 3)
                {
                    aux[i][j] = VIVO;
                }
                else
                {
                    aux[i][j] = VACIO;
                }
            }
            else // (mat[i][j] == VIVO)
            {
                if (numVecinos == 2 || numVecinos == 3)
                {
                    aux[i][j] = VIVO;
                }
                else
                {
                    aux[i][j] = VACIO;
                }
            }
        }
    }
}

void escribirGeneracion(TMatriz& mat)
{
    for (int i = 0;i < TAM ;i++ )
    {
        for (int j = 0;j < TAM ;j++ )
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

int main(){
    int numGeneraciones;
    TMatriz mat, aux;

    do
    {
        cout << "Introduzca numero de generaciones: ";
        cin >> numGeneraciones;
    } while (numGeneraciones <= 0 );
    cout << "Introduzca generacion inicial: " << endl;
    leerGeneracion(mat);
    aux = mat;
    cout << "Generacion 1 (inicial): "  << endl;
    escribirGeneracion(mat);

    for (int i = 0;i < numGeneraciones - 1 ;i++ )
    {
        cout << "Generacion " << i + 2 << ": " << endl;
        juegoDeLaVida(mat, aux);
        mat = aux;
        escribirGeneracion(mat);
    }
return 0;

}

/*
1. Si vacia -> vivo si numVivos == 3, SI No vacia (numVivos != 3)
2. Si vivo -> vivo si numVivos == 2 || numVivos == 3, SI No VACIO

Si en una generación una determinada casilla está vacía, en la siguiente
generación nacerá un ser vivo en la casilla correspondiente si el número
de seres vivos vecinos (arriba, abajo, derecha, izquierda y diagonales) es
igual a 3.
- Si en una generación una determinada casilla está ocupada por un ser
vivo, en la siguiente generación ese ser vivo permanecerá en la casilla
correspondiente si el número de seres vivos vecinos es igual a 2 o 3. En
otro caso, ese ser vivo morirá, por lo que la casilla correspondiente en la
siguiente generación permanecerá vacía.
*/

/*
ooxoo
oxoox
xooxx
ooxoo
xoooo
*/
