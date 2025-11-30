#include <iostream>
#include <array>
#include <math.h>

/*
Algoritmo que lee una matriz 6x8 de enteros (fila a fila),
la almacena en un array bidimensional "a", deja los resultados de
las sumas de los elementos de cada fila en un vector "b" y las
sumas de los elementos de cada columna en un vector "c".
Finalmente imprime los 3 arrays con el formato siguiente:

1. Leer array, crear 2 arrays, uno en el que meter la suma de las filas, y otro el de las columnas
2. Recorrer ese array sumando las filas
3. Recorrer ese array sumando las columnas
4. Cout el restultado de estas.
*/

using namespace std;

int const NFILA = 6;
int const NCOLUMNA = 8;
typedef array<int, NCOLUMNA> TFila; // SE ENCARAGA DE LAS FILAS
typedef array<TFila, NFILA> TMatriz;

typedef array<int, NFILA> TColumnas; // SE ENCARGA DE LAS COLUMNAS

void leerMatriz(TMatriz& mat)
{
    cout << "Introduzca los datos de una matriz " << NFILA << " x " << NCOLUMNA << ": ";
    for (int fila = 0;fila < NFILA;fila++ )
    {
        for (int col = 0;col < NCOLUMNA ;col++ )
        {
            cin >> mat[fila][col];
        }
    }
}

void sumarFilas(TMatriz& mat, TFila& sumFilas)
{
    for (int i = 0;i < NFILA ;i++ )
    {
        for (int j = 0;j < NCOLUMNA ;j++ )
        {
            sumFilas[i] += mat[i][j];
        }
    }
    cout << "La de los numeros de cada fila es : " << endl;
    for (int i = 0;i < NFILA ;i++ )
    {
        cout << "Fila " << i + 1 << ": " << sumFilas[i] << endl;
    }
}

void sumarColumnas(TMatriz& mat, TColumnas& sumColumnas)
{
    for (int i = 0;i < NCOLUMNA;i++ )
    {
        for (int j = 0;j < NFILA ;j++ )
        {
            sumColumnas[i] += mat[i][j];
        }
    }

    cout << "La de los numeros de cada columna es : " << endl;
    for (int i = 0;i < NCOLUMNA ;i++ )
    {
        cout << "Columna " << i + 1 << ": " << sumColumnas[i] << endl;
    }
}

int main(){
    TMatriz mat1;
    TFila sumFilas = {{}};
    TColumnas sumColumnas = {{}};

    leerMatriz(mat1);
    sumarFilas(mat1, sumFilas);
    sumarColumnas(mat1, sumColumnas);
return 0;

}

/*

void leerMatriz(TMatriz& mat)
{
cout <<"Introduzca valores fila a fila\n“;
for (int fi = 0; fi < NFILAS; fi++) {
for (int co = 0; co < NCOLUMNAS; co++) {
cin >> mat[fi][co];
}
}
}

void escribirFila(const TFila& fila)
{
for (int co=0; co < NCOLUMNAS; co++) {
cout << fila[co] << " ";
}
}

void escribirFila(const TFila& fila)
{
for (int co=0; co < NCOLUMNAS; co++) {
cout << fila[co] << " ";
}
}

int sumarCol(const TMatriz& mat,
int co)
{
int res=0;
for (int fi=0; fi<NFILAS; fi++) {
res += mat[fi][co];
}
return res;
}

int main() {
TMatriz a;
TColumna b;
TFila c;
leerMatriz(a);
for (int fi = 0; fi < NFILAS; fi++) {
b[fi]= sumarFila(a[fi]);
}
for (int co = 0; co < NCOLUMNAS; co++) {
c[co]= sumarCol(a,co);
}
for (int fi = 0; fi < NFILAS; fi++) {
escribirFila(a[fi]);
cout << b[fi] << endl;
}
escribirFila(c);
return 0;
}
*/
