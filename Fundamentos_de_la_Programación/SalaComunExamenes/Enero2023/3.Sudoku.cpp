#include <iostream>
#include <array>

using namespace std;

const int TAM = 9;

typedef array<int,TAM> TFila;
typedef array<TFila,TAM> TMatriz;

bool entreUnoYNueve(int numero)
{
    return numero >= 1 && numero <= 9;
}

void numFilaSinRepetir(const TMatriz& tablero, int fila, bool& valido)
{
    for (int col1 = 0 ;col1 < TAM && valido;col1++ )
    {
        for (int col2 = 0;col2 < TAM && valido;col2++ )
        {
            if (col1 != col2 && entreUnoYNueve(tablero[fila][col1])&& entreUnoYNueve(tablero[fila][col2])
                && tablero[fila][col1] == tablero[fila][col2])
            {
                valido = false;
            }
        }
    }
}

void numColumnaSinRepetir(const TMatriz& tablero, int col, bool& valido)
{
    for (int fila1 = 0 ;fila1 < TAM && valido;fila1++ )
    {
        for (int fila2 = 0;fila2 < TAM && valido;fila2++ )
        {
            if (fila1 != fila2 && entreUnoYNueve(tablero[fila1][col])&& entreUnoYNueve(tablero[fila2][col])
                && tablero[fila1][col] == tablero[fila2][col])
            {
                valido = false;
            }
        }
    }
}

void regionValida(const TMatriz& tablero, bool& valido, int limFila, int limCol)
{
    for (int fila1 = limFila;fila1 < limFila + 3 && valido;fila1++ )
    {
        for (int col1 = limCol;col1 < limCol + 3 && valido;col1++ )
        {
            for (int fila2 = limFila;fila2 < limFila + 3 && valido;fila2++ )
            {
                for (int col2 = limCol;col2 < limCol + 3 && valido;col2++ )
                {
                    if ((fila1 != fila2 || col1 != col2) /* !(fila1 == fila2 && col1 == col2)*/ && entreUnoYNueve(tablero[fila1][col1]) && entreUnoYNueve(tablero[fila2][col2])
                        && tablero[fila1][col1] == tablero[fila2][col2])
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

    //Filas
    for (int i = 0;i < TAM && valido;i++ )
    {
        numFilaSinRepetir(tablero,i,valido);
    }
    // Columnnas
    for (int i = 0;i < TAM && valido;i++ )
    {
        numColumnaSinRepetir(tablero,i,valido);
    }
    // Regiones 3x3
    for (int i = 0;i < TAM && valido;i += 3 )
    {
        for (int j = 0;j < TAM && valido;j += 3 )
        {
            regionValida(tablero,valido,i,j);
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

/*
1. Numero entre 1 y 9 o Vacia(0)
2. En misma fila no puede haber numeros repetidos (los 0's no cuentan)
3. En la misma columna no puede haber numeros repetidos (los 0's no cuentan)
4. Dentro de cada region(3x3) no puede haber numeros repetidos (los 0's no cuentan)
*/
/*
Analizaremos fila por fila y columna por columna
Posteriormente region por region;
*/
