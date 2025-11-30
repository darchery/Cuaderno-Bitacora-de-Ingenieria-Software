 #include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int NUM_FILAS = 3;
const int NUM_COLUMNAS = 4;

typedef array<int, NUM_COLUMNAS> TFilas;
typedef array<TFilas, NUM_FILAS> TMatriz;

void leerMatriz(TMatriz& a, int& x)
{
    cout << "Introduzca una matriz fila a fila (" << NUM_FILAS << " x " << NUM_COLUMNAS << "): ";
    for (int i = 0;i < NUM_FILAS ;i++ )
    {
        for (int j = 0;j < NUM_COLUMNAS ;j++ )
        {
            cin >> a[i][j];
        }
    }

    cout << "Introduzca el numero entero a buscar: ";
    cin >> x;
}

bool esta(TMatriz& a, int x)
{
    bool found = false;

    for (int i = 0;i < NUM_FILAS && !found ;i++ )
    {
        for (int j = 0;j < NUM_COLUMNAS && !found ;j++ )
        {
            if (a[i][j] == x)
            {
                found = true;
            }
        }
    }
    return found;
}

void analizarRes(bool aparece, int x)
{
    if (aparece)
    {
        cout << "El numero " << x << " SI esta en la matriz" << endl;
    }
    else
    {
        cout << "El numero " << x << " NO esta en la matriz" << endl;
    }
}

int main(){
    TMatriz a;
    int x;

    leerMatriz(a, x);
    analizarRes(esta(a,x), x);
return 0;

}
