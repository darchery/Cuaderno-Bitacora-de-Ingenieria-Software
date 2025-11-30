#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N = 5;
const int TOPE = N * N;
typedef array<int, N> TFila;
typedef array<TFila, N> TCuadrado;

// Falta hacer que los numeros sean entre 1 y N * N, en este caso 25

void leerCuadrado(TCuadrado& cuadrado)
{
    cout << "Introduzca " << N << " filas de " << N << " numeros: " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            cin >> cuadrado[i][j];
        }
    }
}

int sumaFila(const TCuadrado& cuadrado, int fila)
{
    int suma = 0;

    for (int j = 0;j < N ;j++ )
    {
        suma += cuadrado[fila][j];
    }
    return suma;
}

int sumaColumna(const TCuadrado& cuadrado, int col)
{
    int suma = 0;

    for (int i = 0;i < N ;i++ )
    {
        suma += cuadrado[i][col];
    }
    return suma;
}

int sumaDiagonalPrincipal(const TCuadrado& cuadrado)
{
    int suma = 0;

    for (int i = 0;i < N ;i++ )
    {
       for (int j = 0;j < N ;j++ )
       {
           if (i == j)
           {
                suma += cuadrado[i][j];
           }
       }
    }
    return suma;
}

int sumaDiagonalInversa(const TCuadrado& cuadrado)
{
    int suma = 0;
    int j = N - 1;

    for (int i = 0;i < N ;i++ )
    {
        suma += cuadrado[i][j];
        j--;
    }
    return suma;
}

bool entreNN(const TCuadrado& cuadrado)
{
    bool esta = true;

    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            if (cuadrado[i][j] > TOPE)
            {
                esta = false;
            }
        }
    }
    return esta;
}

bool esMagico(const TCuadrado& cuadrado)
{
    bool magico = true;

    // Suma filas
    int sumaFil = sumaFila(cuadrado, 0);
    for (int i = 1;i < N && magico;i++ )
    {
        if (sumaFil != sumaFila(cuadrado,i))
        {
            magico = false;
        }
    }
    // Suma columnas
    int sumaCol = sumaColumna(cuadrado,0);
    for (int i = 1;i < N && magico;i++ )
    {
        if (sumaCol != sumaColumna(cuadrado,i))
        {
            magico = false;
        }
    }
    // Suma diagonal
    if (sumaFil != sumaDiagonalPrincipal(cuadrado))
    {
        magico = false;
    }
    // Suma diagonal inversa
    if (sumaFil != sumaDiagonalInversa(cuadrado))
    {
        magico = false;
    }
    // Numeros comprendidos entre 1 y N*N
    if (!entreNN(cuadrado))
    {
        magico = false;
    }
    return magico;
}

void escribirCuadrado(TCuadrado& cuadrado)
{
    int cnt = 0;

    cout << "El cuadrado: " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            if (cnt == N)
            {
                cnt = 0;
                cout << endl;
            }
            cout << cuadrado[i][j] << " ";
            cnt++;
        }
    }
    cout << endl << endl;
}

int main(){
    TCuadrado cuadrado;

    leerCuadrado(cuadrado);
    escribirCuadrado(cuadrado);
    if (esMagico(cuadrado))
    {
        cout << "SI es magico" << endl;
    }
    else
    {
        cout << "NO es magico" << endl;
    }
return 0;

}
