#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 10;
typedef array<int, MAX> TFila;
typedef array<TFila, MAX> TMatriz;

struct TLista {
    TMatriz mat;
    int tamMatriz;
};

void leerDatos(TLista& lista)
{
    cout << "Introduzca dimension de la matriz cuadrada (maximo " << MAX << "): ";
    cin >> lista.tamMatriz;
    cout << "Introduzca la matriz fila tras fila: " << endl;
    for (int i = 0;i < lista.tamMatriz ;i++ )
    {
        for (int j = 0;j < lista.tamMatriz ;j++ )
        {
            cin >> lista.mat[i][j];
        }
    }
}

// Esta tecnica es la mejor, se empieza en el primero o en el que toque, y si encuentra uno igual es que no es esctricto y si encuentra otro mayor (si es mayor estricto)
// lo actualiza e indica que si hay mayor estrcito y asi hasta acabar

int mayorEstrictoColumna(TLista& lista,int fila ,int col, bool& mayorEncontrado)
{
    int mayor = lista.mat[fila][col];
    bool found = true;
    mayorEncontrado = found;

    for (int i = 0;i < lista.tamMatriz ;i++ )
    {
        if (fila != i )
        {
            if (lista.mat[i][col] == mayor)
            {
                found = false;
                mayorEncontrado = found;
            }
            else if(mayor < lista.mat[i][col])
            {
                mayor = lista.mat[i][col];
                found = true;
                mayorEncontrado = found;
            }
        }
    }
    return mayor;
}

int menorEstrictoFila(TLista& lista,int fila ,int col, bool& menorEncontrado)
{
    int menor = lista.mat[fila][col];
    bool found = true;
    menorEncontrado = found;

    for (int i = 0;i < lista.tamMatriz ;i++ )
    {
        if (col != i)
        {
            if (menor == lista.mat[fila][i])
            {
                found = false;
                menorEncontrado = found;
            }
            else if (menor > lista.mat[fila][i])
            {
                menor = lista.mat[fila][i];
                found = true;
                menorEncontrado = found;
            }
        }
    }
    return menor;
}

void puntoDeSilla(TLista& lista)
{
    int filaMenor = 0, colMayor = 0;
    bool found = false;
    bool mayorEncontrado, menorEncontrado;

    for (int i = 0;i < lista.tamMatriz && !found;i++ )
    {
        for (int j = 0;j < lista.tamMatriz && !found;j++ )
        {
            if (mayorEstrictoColumna(lista,i,j,mayorEncontrado) == menorEstrictoFila(lista,i,j,menorEncontrado) && mayorEncontrado && menorEncontrado )
            {
                found = true;
                filaMenor = i;
                colMayor = j;
            }
        }
    }

    if (found)
    {
        cout << "El punto silla es: " << endl;
        cout << "Fila: " << filaMenor << ", " << "Columna: " << colMayor << endl;
    }
    else
    {
        cout << "No hay punto de silla" << endl;
    }
}

int main(){
    TLista lista;

    leerDatos(lista);
    puntoDeSilla(lista);
return 0;

}
// EN LA EJECUCION SALE EL  0 0, TENDRIA QUE SALIR EL 1 1

// Cogere un numero y los metere en 2 bools o en 2 void con un bool de entrada
// Luego si es menorEstricto de la fila y es el mayorEstricto de la columna
// Entonces este si es un punto de silla y el bucle se parará,

/*
1. Mayor esctricto de su columna
2. Menor estricto de su fila

2 3 5 2
7 6 8 9
4 4 5 2
1 2 5 7

Una matriz tiene un punto silla en una de sus componentes, si ese componente es el mayor
estricto de su columna y el menor estricto de su fila.
*/

/*cout << "Mayor estricto col = " << mayorEstrictoColumna(lista,i,j,mayorEncontrado) << " " << "Col: " << j << " " << boolalpha << mayorEncontrado << endl;
            cout << "Menor estricto fila = " << menorEstrictoFila(lista,i,j,menorEncontrado) << " " << "Fila: " << i << " " << boolalpha << menorEncontrado << endl;
            cout << "Punto de silla encontrado:  " << boolalpha << bool (mayorEstrictoColumna(lista,i,j,mayorEncontrado) == menorEstrictoFila(lista,i,j,menorEncontrado)) << endl;
            cout << endl;*/
