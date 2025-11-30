#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int  N = 9;
typedef array<int, N> TFila;
typedef array<TFila, N> TMatriz;

bool entreUnoNueve(int num)
{
    return num >= 1 && num <= 9;
}

void comprobarFilas(const TMatriz& tablero, int fila, bool& valido)
{
    for (int i = 0;i < N && valido;i++ )
    {
        for (int j = 0;j < N  && valido;j++ )
        {
            if (i != j && tablero[fila][i] == tablero[fila][j] &&
                entreUnoNueve(tablero[fila][i]) && entreUnoNueve(tablero[fila][j]))
            {
                valido = false;
            }
        }
    }
}

void comprobarColumnas(const TMatriz& tablero, int col, bool& valido)
{
    for (int i = 0;i < N && valido;i++ )
    {
        for (int j = 0;j < N  && valido;j++ )
        {
            if (i != j && tablero[i][col] == tablero[j][col] &&
                entreUnoNueve(tablero[i][col]) && entreUnoNueve(tablero[j][col]))
            {
                valido = false;
            }
        }
    }
}

void regionValida(const TMatriz& tablero, int fila, int col, bool& valido)
{
    for (int fila1 = fila ; fila1 < fila + 3 && valido ;fila1++ )
    {
        for (int col1 = col ; col1 < col + 3 && valido ;col1++ )
        {
            for (int fila2 = fila ; fila2 < fila + 3 && valido ;fila2++ )
            {
                for (int col2 = col ;col2 < col + 3 && valido ;col2++ )
                {
                    if ( !(fila1 == fila2 && col1 == col2) && tablero[fila1][col1] == tablero[fila2][col2] && entreUnoNueve(tablero[fila1][col1]) && entreUnoNueve(tablero[fila2][col2]) )
                    {
                        valido = false;
                    }
                }
            }
        }
    }
}

bool tableroValido(const TMatriz& tablero)
{
    bool valido = true;

    // Filas
    for (int i = 0;i < N && valido;i++ )
    {
        comprobarFilas(tablero,i,valido);
    }
    // Columnas
    for (int i = 0;i < N && valido;i++ )
    {
        comprobarColumnas(tablero,i,valido);
    }
    // Regiones 3x3
    for (int i = 0;i < N && valido;i += 3 )
    {
        for (int j = 0;j < N && valido;j += 3 )
        {
            regionValida(tablero,i,j,valido);
        }
    }
    return valido;
}

int main() {
    TMatriz tablero1 =
                    {{  {{5,3,0,0,7,0,0,0,0}},
                        {{6,0,0,1,9,5,0,0,0}},
                        {{0,9,8,0,0,0,0,6,0}},
                        {{8,0,0,0,6,0,0,0,3}},
                        {{4,0,0,8,0,3,0,0,1}},
                        {{7,0,0,0,2,0,0,0,6}},
                        {{0,6,0,0,0,0,2,8,0}},
                        {{0,0,0,4,1,9,0,0,5}},
                        {{0,0,0,0,8,0,0,7,9}}
                    }};

    TMatriz tablero2 =
                    {{ {{5,3,0,0,7,0,0,0,0}},
                        {{6,0,0,1,9,5,0,0,0}},
                        {{0,9,8,0,0,0,0,6,0}},
                        {{8,0,3,0,6,0,0,0,3}},
                        {{4,0,0,8,0,3,0,0,1}},
                        {{7,0,0,0,2,0,0,0,6}},
                        {{0,6,0,0,0,0,2,8,0}},
                        {{0,0,0,4,1,9,0,0,5}},
                        {{0,0,0,0,8,0,0,7,9}}
                    }};

    TMatriz tablero3 =
                    {{ {{5,3,0,0,7,0,0,0,0}},
                        {{6,0,0,1,9,5,0,0,0}},
                        {{0,9,8,0,2,0,0,6,0}},
                        {{8,0,0,0,6,0,0,0,3}},
                        {{4,0,0,8,0,3,0,0,1}},
                        {{7,0,0,0,2,0,0,0,6}},
                        {{0,6,0,0,0,0,2,8,0}},
                        {{0,0,0,4,1,9,0,0,5}},
                        {{0,0,0,0,8,0,0,7,9}}
                    }};

    TMatriz tablero4 =
                    {{ {{5,3,0,0,7,0,6,0,0}},
                        {{6,0,0,1,9,5,0,0,0}},
                        {{0,9,8,0,0,0,0,6,0}},
                        {{8,0,0,0,6,0,0,0,3}},
                        {{4,0,0,8,0,3,0,0,1}},
                        {{7,0,0,0,2,0,0,0,6}},
                        {{0,6,0,0,0,0,2,8,0}},
                        {{0,0,0,4,1,9,0,0,5}},
                        {{0,0,0,0,8,0,0,7,9}}
                    }};

    if (tableroValido(tablero1)) {
        cout << "El tablero1 es un sudoku VALIDO" << endl;
    } else {
        cout << "El tablero1 es un sudoku NO VALIDO" << endl;
    }

    if (tableroValido(tablero2)) {
        cout << "El tablero2 es un sudoku VALIDO" << endl;
    } else {
        cout << "El tablero2 es un sudoku NO VALIDO" << endl;
    }

    if (tableroValido(tablero3)) {
        cout << "El tablero3 es un sudoku VALIDO" << endl;
    } else {
        cout << "El tablero3 es un sudoku NO VALIDO" << endl;
    }

    if (tableroValido(tablero4)) {
        cout << "El tablero4 es un sudoku VALIDO" << endl;
    } else {
        cout << "El tablero4 es un sudoku NO VALIDO" << endl;
    }

    return 0;
}
