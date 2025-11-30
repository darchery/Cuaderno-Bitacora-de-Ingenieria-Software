#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const char VACIO = 'o';
const char VIVO = 'x';
const int TAM = 5;
typedef array<char, TAM> TFila;
typedef array<TFila, TAM> TMatriz;

void leerGen(TMatriz& matriz)
{
    cout << "Introduzca la generacion inicial: " << endl;
    for (int i = 0;i < TAM ;i++ )
    {
        for (int j = 0;j < TAM ;j++ )
        {
            cin >> matriz[i][j];
        }
    }
}

bool celdaValida(int fila, int col)
{
    return fila >= 0 && fila < TAM && col >= 0 && col < TAM;
}


int numeroVecinosCercanos(TMatriz& matriz, int fila, int col)
{
    int sumaVecinos = 0;

    for (int i = fila - 1;i <= fila + 1 ;i++ )
    {
        for (int j = col - 1;j <= col + 1 ;j++ )
        {
            if (celdaValida(i,j) && !(i == fila && j == col) && matriz[i][j] == VIVO)
            {
                sumaVecinos++;
            }
        }
    }
    return sumaVecinos;
}

/*
1. Si esta vacia ==> ser vivo si numVecinosCercanos = 3;
2. Si ser vivo ==> permanece ser vivo si numVecinosCercanos = 2 o = 3
    2.1. Si es != 2 o != 3 muere == > pasa a vacia
*/

void generararGeneraciones(TMatriz& matriz , TMatriz& matrizCopia)
{
    int numVec;

    for (int i = 0;i < TAM ;i++ )
    {
        for (int j = 0;j < TAM ;j++ )
        {
            numVec = numeroVecinosCercanos(matriz, i, j);
            // Casilla VACIA
            if (matriz[i][j] == VACIO  )
            {
                if (numVec == 3)
                {
                   matrizCopia[i][j] = VIVO;
                }
                else
                {
                    matrizCopia[i][j] = VACIO;
                }
            }
            // Casilla VIVA
            else
            {
                if (numVec == 2 || numVec == 3)
                {
                    matrizCopia[i][j] = VIVO;
                }
                else
                {
                    matrizCopia[i][j] = VACIO;
                }
            }
        }
    }
}

void escribirGeneracion(TMatriz& matriz)
{
    for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			cout <<  matriz[i][j];
		}
		cout << endl;
	}
}

int main(){
    TMatriz matriz = {{}};
    TMatriz matrizCopia;
    int n;

    do
    {
        cout << "Introduzca un numero de generaciones: ";
        cin >> n;
    } while (n <= 0);

    leerGen(matriz);
    cout << "Generacion inicial: " << endl;
    escribirGeneracion(matriz);
    matrizCopia = matriz;
    for (int i = 1;i < n ;i++ )
    {
        cout << "Generacion " << i + 1 << ": " << endl;
        generararGeneraciones(matriz, matrizCopia);
        matriz = matrizCopia;
        escribirGeneracion(matriz);
    }
return 0;

}
/*
ooxoo
oxoox
xooxx
ooxoof
xoooo

1. Si esta vacia ==> ser vivo si numVecinosCercanos = 3;
2. Si ser vivo ==> permanece ser vivo si numVecinosCercanos = 2 o = 3
    2.1. Si es != 2 o != 3 muere == > pasa a vacia

- Si en una generación una determinada casilla está vacía, en la siguiente generación
nacerá un ser vivo en la casilla correspondiente si el número de seres vivos vecinos
(arriba, abajo, derecha, izquierda y diagonales) es igual a 3.

- Si en una generación una determinada casilla está ocupada por un ser vivo, en la
siguiente generación ese ser vivo permanecerá en la casilla correspondiente si el
número de seres vivos vecinos es igual a 2 o 3. En otro caso, ese ser vivo morirá, por
lo que la casilla correspondiente en la siguiente generación permanecerá vacía
*/
