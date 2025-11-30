#include <iostream>
#include <array>

using namespace std;

const int N = 4;
typedef array<int, N> TFilas;
typedef array<TFilas, N> TMatriz;

void leerMatriz(TMatriz& matriz)
{
    cout << "Introduzca por filas una matriz (" << N << " x " << N << ")" << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            cin >> matriz[i][j];
        }
    }
}

int sumaFila(const TMatriz& matriz, int fila)
{
    int suma = 0;

    for (int j = 0;j < N ;j++ )
    {
        suma += matriz[fila][j];
    }
    return suma;
}

int sumaColumna(const TMatriz& matriz, int col)
{
    int suma = 0;

    for (int i = 0;i < N ;i++ )
    {
        suma += matriz[i][col];
    }
    return suma;
}

int sumaDiagonalPrincipal(const TMatriz& matriz) // Se puede reducir con un for ya que fila y col siempre seran iguales
{
    int suma = 0;

    for (int i = 0;i < N ;i++ )
    {
       for (int j = 0;j < N ;j++ )
       {
           if (i == j)
           {
                suma += matriz[i][j];
           }
       }
    }
    return suma;
}

int sumaDiagonalInversa(TMatriz& matriz)
{
    int suma = 0;
    int j = N - 1;

    for (int i = 0;i < N ;i++ )
    {
        suma += matriz[i][j];
        j--;
    }
    return suma;
}

int main() {
    TMatriz matriz1;
    int fila, col;

    leerMatriz(matriz1);
    do
    {
        cout << "Introduzca la fila a sumar (entre " << 0 <<  " y " << N - 1 << "): ";
        cin >> fila;
    } while (fila < 0 || fila > N - 1);
    cout << "La suma de la fila " << fila << " es: " << sumaFila(matriz1, fila) << endl;

    do
    {
        cout << "Introduzca la columna a sumar (entre " << 0 <<  " y " << N - 1 << "): ";
        cin >> col;
    } while (col < 0 || col > N - 1);
    cout << "La suma de la columna " << col << " es: " << sumaColumna(matriz1, col) << endl;
    cout << "La suma de la diagonal principal es: " << sumaDiagonalPrincipal(matriz1) << endl;
    cout << "La suma de la diagonal inversa es: " << sumaDiagonalInversa(matriz1) << endl;
    return 0;
}
