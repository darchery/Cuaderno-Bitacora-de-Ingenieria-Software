#include <iostream>
#include <array>
using namespace std;

const int FILA = 3;
const int COL = 4;
typedef array<int,COL> TFila;
typedef array<TFila, FILA> TMatriz;

typedef array<bool,COL> TFilaTachado;
typedef array<TFila, FILA> TTachado;

typedef array<int,COL*FILA> TVec;

void leerMatriz(TMatriz& mat)
{
    for (int i = 0;i < FILA ;i++ )
    {
        for (int j = 0;j < COL ;j++ )
        {
            cin >> mat[i][j];
        }
    }
}

bool esta(const TVec& vec, int num, int posAct)
{
    bool siEsta = false;

    for (int i = posAct - 1;i >= 0 && !siEsta;i-- )
    {
        if (num == vec[i])
        {
            siEsta = true;
        }
    }
    return siEsta;
}

int tope(const TMatriz& mat)
{
    int top = mat[0][0];

    for (int i = 0;i < FILA ;i++ )
    {
        for (int j = 0;j < COL ;j++ )
        {
            if (top > mat[i][j])
            {
                top = mat[i][j];
            }
        }
    }
    return top;
}

int buscarMayor(const TMatriz& mat,TTachado& tachado)
{
    int fila = 0, col = 0;
    int mayor = tope(mat);

    for (int i = 0;i < FILA ;i++ )
    {
        for (int j = 0;j < COL ;j++ )
        {
            if (!tachado[i][j] && mayor < mat[i][j])
            {
                mayor = mat[i][j];
                fila = i;
                col = j;
            }
        }
    }
    tachado[fila][col] = true;
    return mayor;
}

void sacarMayores(TMatriz& mat, TVec& vec, int tamVec)
{
    TTachado tachado = {{}};
    int index = 0;
    int mayor;
    int cnt = 0;

    while (index < tamVec && cnt < FILA*COL)
    {
        mayor = buscarMayor(mat,tachado);
        if (!esta(vec,mayor,index))
        {
            vec[index] = mayor;
            index++;
        }
        cnt++;
    }
}

void escribirMayores(const TVec& vec, int tamVec)
{
    for (int i = 0;i < tamVec ;i++ )
    {
        cout << vec[i] << " ";
    }
}

int main()
{
    TVec vec;
    TMatriz mat = {{
        {{45, -17, 867, 45}},
        {{2, 867, -17, 3}},
        {{1, -2, 45, 3}}
    }};
    // int k;
    // cout << "Introduzca k: "; cin >> k;
    // cout << "Introduzca una matriz " << FILA << " x " << COL << " (fila por fila):" << endl;
    // leerMatriz(mat);

    // Sacar mayores
    sacarMayores(mat,vec,4);
    escribirMayores(vec, 4);    // 867 45 3 2
    cout << endl;

    // Reinicar vector
    vec = {{}};
    // Sacar mayores
    sacarMayores(mat,vec,8);
    escribirMayores(vec, 8);   //
    cout << endl;

    // Reinicar vector
    vec = {{}};
    // Sacar mayores
    sacarMayores(mat,vec,3);
    escribirMayores(vec, 3);

    return 0;
}

/*
The values more repeated are: 45 -17 867 3

The values more repeated are: 45 -17 867 3 2 1 -2

The values more repeated are: 45 -17 867
*/
