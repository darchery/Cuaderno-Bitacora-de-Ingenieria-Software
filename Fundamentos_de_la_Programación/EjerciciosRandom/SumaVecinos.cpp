#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int NFIL = 4;
const int NCOL = 5;

typedef array<int,NCOL> TFila;
typedef array<TFila,NFIL> TMatriz;

bool esValida(int fila, int col)
{
    bool valido;

    if (fila >= 0 && fila < NFIL && col >= 0 && col < NCOL)
    {
        valido = true;
    }
    else
    {
        valido = false;
    }
    return valido;
}

int sumaVecinos(TMatriz& matriz,int fila, int columna)
{
    int suma = 0;

    if (esValida(fila, columna))
    {
        for (int i = fila - 1;i <= fila + 1 ;i++ )
        {
            for (int j = columna - 1;j <= columna + 1 ;j++ )
            {
                if ( !( (i == fila && j == columna) && esValida(i,j) ) )
                {
                    suma += matriz[i][j];
                }
            }
        }
    }
    return suma;
}

/*
El programa funciona solamente para numero que tengan de vecino unicamente a  8 numeros de vecinos, es decir que tenga numeros en las
4 posiciones estandar y en las 4 diagonales, si se sale de este margen no funcionará

Consiste en empezar a analizar la matriz por el vecino mas cercano al 0 0, poniendo limites en la fila y en la columna
En la fila se empieza en la fila - 1 hasta la fila + 1, asi recorres el anterior y posterior que son  vecinos
En la columna se empeiza en la col - 1 hasta la col + 1, asi recorrera todos
Tenemos una funcion que verifica que sean coordenadas correctas
Con el for vamos rotando des de la pocicion de arriba izq y vamos continuando hacia a la derecha, y cuando se llegue a una columna no existente
se irá a la siguiente fila

        7,  8,  3,

        4,  3,  2,

        7,  9,  2,
*/

int main(){
    TMatriz matriz = {{ {{1,2,3,4,5}},
                        {{6,7,8,3,4}},
                        {{5,4,3,2,1}},
                        {{6,7,9,2,4}},
                      }};
    int fila = 2;
    int columna = 2;

    cout << "Resultado: " << sumaVecinos(matriz,fila,columna) << endl;
    return 0;
return 0;

}

/*
    {{1,2,3,4,5}}
    {{6,7,8,3,4}}
    {{5,4,3,2,1}}
    {{6,7,9,2,4}}

    Si sumamos los vecinos de la pos (2,2): 3
    {{1,2,3,4,5}}
    {{6,7,8,3,4}}
   {{5,4, 3 ,2,1}}
    {{6,7,9,2,4}}
    Seria 7 + 8 + 3 + 4 + 2 + 7 + 9 + 2 = 42
*/
