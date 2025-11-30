#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int FILAS = 2;
const int COLUMNAS = 4;
typedef array<int, COLUMNAS> TFila;
typedef array<TFila, FILAS> TMatriz;


void leerMatriz(TMatriz& matriz, int& num)
{
    cout << "Introduzca una matriz (" << FILAS << " x " << COLUMNAS << "): ";
    for (int i = 0;i < FILAS ;i++ )
    {
        for (int j = 0;j < COLUMNAS ;j++ )
        {
            cin >> matriz[i][j];
        }
    }
    cout << "Introduzca un numero a buscar: ";
    cin >> num;
}

void buscar(TMatriz& matriz, int num)
{
    int fil = -1, col = -1;
    bool found = false;

    for (int i = 0;i < FILAS && !found;i++ )
    {
        for (int j = 0;j < COLUMNAS && !found;j++ )
        {
            if (matriz[i][j] == num)
            {
                fil = i;
                col = j;
                found = true;
            }
        }
    }
    if (fil == -1 && col == -1)
    {
        cout << num << " no esta en la matriz" << endl;
    }
    else
    {
        cout << num << " esta  el fila " << fil << ", columna " << col <<  " de la matriz" << endl;
    }
}

int main(){
    TMatriz matriz1;
    int num;

    leerMatriz(matriz1, num);
    buscar(matriz1, num);
return 0;

}
