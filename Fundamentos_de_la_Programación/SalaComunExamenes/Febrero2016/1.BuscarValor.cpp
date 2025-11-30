#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int FILA = 2;
const int COL = 4;
typedef array<int, COL> TFila;
typedef array<TFila, FILA> TMatriz;

void escribirMatriz(TMatriz& mat)
{
    for (int i = 0;i < FILA ;i++ )
    {
        for (int j = 0;j < COL ;j++ )
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void buscar(int x, TMatriz& mat, int& fila, int& col)
{
    fila = -1;
    col = -1;
    bool found = false;

    for (int i = 0;i < FILA && !found;i++ )
    {
        for (int j = 0;j < COL && !found;j++ )
        {
            if (x == mat[i][j])
            {
                found = true;
                fila = i;
                col = j;
            }
        }
    }
}

void mostrarResultado(int x, int& fila, int& col)
{
    if (fila == -1 && col == -1)
    {
        cout <<  x << " no se encuentra en la matriz" << endl;
    }
    else
    {
        cout << x << " esta en la fila " << fila << ", columna " << col << " de la matriz" << endl;
    }
}

int main(){
    TMatriz mat1 = {{
                        {{2, 7, 12, 89}},
                        {{5, 2, 9, 10}}
    }};
    int f, c;

    cout << "Mostramos el contenido de la matriz proporcionada: " << endl;
    escribirMatriz(mat1);

    buscar(10,mat1,f,c);
    mostrarResultado(10,f,c);

    buscar(2,mat1,f,c);
    mostrarResultado(2,f,c);

    buscar(27,mat1,f,c);
    mostrarResultado(27,f,c);
return 0;

}
