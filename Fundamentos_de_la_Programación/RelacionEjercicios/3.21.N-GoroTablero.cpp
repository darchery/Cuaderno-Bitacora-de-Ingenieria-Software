#include <iostream>
#include <array>
#include <math.h>

using namespace std;

/*
    Cada vez que cambia de punto es que la condicion anterior no se cumple

    1. Empieza en (1,1) y seguimos con hasta llegar a (n,n)
    2. Luego iremos a la posicion (n+1,n+1) como no exite
    3. Se pasa a la casilla equivalente en al primera fila: (1,n+1)
    4. Se continúa por la casilla equivalente de la primera columna, es decir, la (2,1)
    5. Nos movemos hacia la derecha y hacia abajo, hasta alcanzar la casilla (n,n-1)
    6. Siguiente casilla sería la (n+1,n), como nos saldríamos pasamos a la casilla equivalente de la primera fila (1,n)
    7. Se continúa con este proceso

    Cada vez que aparece una posicion invalisa se lleva a (1,n+1), cuando aparace otra pos invalida pasa a (1+ 1, n + 1 - 1) es decir (2, n),
    a la x se le suma y a la y se le resta, hasta llegar a (1,1) que seria (0, 0)
*/

const int N = 4;
const int NUM_ELEMENTOS = N * (N+1);
typedef array<int, N + 1> TFilas;
typedef array<TFilas, N> TMatriz;

void incrementar(int& fila, int& col)
{
    if (fila == N - 1)
    {
        fila = 0;
        col++;
    }
    else
    {
        fila++;
        col++;
    }
}

void siguientePosicion(int& fila, int& col)
{
    if (col == N)
    {
        fila++;
        col = 0;
    }
    else
    {
       incrementar(fila,col);
    }
}

void ngoros(TMatriz& a)
{
    int fila = 0;
    int col = 0;

    a[fila][col] = 1;
    for (int i = 2;i <= NUM_ELEMENTOS;i++ )
    {
        siguientePosicion(fila,col);
        a[fila][col] = i;
    }
}

void escribirMatriz(TMatriz& a)
{
    cout << "El tablero N-Goro para N = " << N << " es: " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N + 1 ;j++ )
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    TMatriz a1;

    ngoros(a1);
    escribirMatriz(a1);
return 0;

}

/*  Basicamente tenemos 3 modos de funcionamiento:
    1. Asignar numeros en diagonal hacia la derecha
    2. Si encuentra una pos invalida se desplaza hasta (0,n + 1), en cada ciclo se le resta uno  a (n+1)
    3. Si llegan
*/


/*
void ngoros(TMatriz& a)
{
    int num = 1;
    int xRei = 0, yRei = N - 1;     // Para regular los reinicios
    int i = 0, j = 0;

    while (yRei != 0)
    {
        while (i == j)  // MAL PENSAR MEJOR
        {
            a[i][j] = num;
            i++;
            j++;
            num++;
        }
        a[xRei][yRei] = num;
        xRei++;
        yRei--;
    }
}
*/
