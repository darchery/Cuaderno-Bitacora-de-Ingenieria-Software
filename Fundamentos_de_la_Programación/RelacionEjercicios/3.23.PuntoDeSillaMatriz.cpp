#include <iostream>
#include <array>
#include <math.h>

using namespace std;


const int MAX = 10;
typedef array<int, MAX> TFila;
typedef array<TFila, MAX> TArrayBid ;

struct TMatriz {
    TArrayBid datos; // valores almacenados en tam filas y tam columnas
    int tam; // dimension de la matriz cuadrada (tam x tam)
};

void leerMatriz(TMatriz& matriz)
{
    do
    {
        cout << "Introduzca la dimension de la matriz cuadrada(maximo " << MAX << "): ";
        cin >> matriz.tam;
    } while (matriz.tam <= 0  || matriz.tam > 10);

    cout << "Introduzca la matriz (" << matriz.tam << " x " << matriz.tam << ") fila a fila: " << endl;
    for (int i = 0;i < matriz.tam ;i++ )
    {
        for (int j = 0;j < matriz.tam ;j++ )
        {
            cin >> matriz.datos[i][j];
        }
    }
}

bool seRepiteColumna(TMatriz& matriz, int value, int index)
{
    bool repite = false;

    for (int i = 0;i < matriz.tam;i++ )
    {
        if (value == matriz.datos[i][index])
        {
            repite = true;
        }
    }
    return repite;
}

bool seRepiteFila(TMatriz& matriz,int value, int index)
{
    bool repite = false;

    for (int i = 0;i < matriz.tam;i++ )
    {
        if (value == matriz.datos[index][i])
        {
            repite = true;
        }
    }
    return repite;
}

bool mayorEstrictoColumna(TMatriz& matriz, int col, int& fil1, int& col1)
{
    bool esMayor;
    int mayor = matriz.datos[0][col];
    fil1 = 0;

    for (int fila = 1;fila < matriz.tam ;fila++ )
    {
        if (mayor < matriz.datos[fila][col])
        {
            mayor = matriz.datos[fila][col];
            fil1 = fila;
            col1 = col;
        }
    }
    if (seRepiteColumna(matriz, mayor, col))
    {
        esMayor = false;
    }
    else
    {
        esMayor = true;
    }
    return esMayor;
}

/*int topeMayor(const TMatriz& matriz, int fila)
{
    int tope = matriz.datos[fila][0];

    for (int col = 0;col < matriz.tam ;col++ )
    {
        if (tope < matriz.datos[fila][col])
        {
            tope = matriz.datos[fila][col];
        }
    }
    tope++;
    return tope;
}*/

// Esta funcion no va, no coge los menores estrictos, no coge nada, se queda con datos basura
bool menorEstrictoFila(TMatriz& matriz, int fila, int& fil2, int& col2)
{
    bool esMenor;
    int menor = matriz.datos[fila][0];
    //int menor = topeMayor(matriz, fila);
    col2 = 0;

    for (int col = 1;col < matriz.tam ;col++ )
    {
        if (menor > matriz.datos[fila][col])
        {
            menor = matriz.datos[fila][col];
            fil2 = fila;
            col2 = col;
        }
    }
    if (seRepiteFila(matriz, menor, fila))
    {
        esMenor = false;
    }
    else
    {
        esMenor = true;
    }
    return esMenor;
}



void puntoDeSilla(TMatriz& matriz)
{
    bool hayPuntoSilla = false;
    int fil1, col1;
    int fil2, col2;
    int i = 0, j;

    while (i < matriz.tam && !hayPuntoSilla)
    {
        j = 0;
        while (j < matriz.tam && !hayPuntoSilla)
        {
            if (mayorEstrictoColumna(matriz, j, fil1, col1) && menorEstrictoFila(matriz, i, fil2, col2) && fil1 == fil2 && col1 == col2)
            {
                hayPuntoSilla = true;
            }
            cout << "MayorEstricCol: " << boolalpha << mayorEstrictoColumna(matriz,j,fil1,col1) << endl;
            cout << "MenorEstrictFil: " << boolalpha << menorEstrictoFila(matriz,i, fil2,col2) << endl;
            cout << "Fil1: " << fil1 << "  " << "Fil2: " << fil2 << endl;
            cout << "Col1: " << col1 << "  " << "Col2: " << col2 << endl;
            cout << endl;
            j++;
        }
        i++;
    }

    if (hayPuntoSilla)
    {
        cout << "El punto de sila es: " << endl;
        cout << "Fila: " << fil1 << ", " << "Columna: " << col2 << endl;
    }
    else
    {
        cout << "No hay punto de silla" << endl;
    }
}

int main(){
    TMatriz matriz;

    leerMatriz(matriz);
    puntoDeSilla(matriz);
return 0;

}

/*
Problemas encontrados:
Yo he diseñado unos subprogramas que: introduces una fila y te saca el menor estricto, y si metes una columna te saca el mayor estricto
Y el main: va numero por numero viendo si es un punto de silla
Si voy con la idea de los subprogramas necesito enviar una fila y devolver la fila y la columna en la que se ha encontrado
Y si le envio una columna que me devuelba la fila y col y si ESTOS 2 ANTERIORES son iguales es un punto de silla
*/

// Es punto de silla si ;
// 1. Mayor estricto de su columna
// 2. Menor estricto de su fila


/*
bool menorEstrictoFila(TMatriz& matriz, int fila, int& fil2, int& col2) {
    bool esMenor = true;
    int menor = matriz.datos[fila][0];
    col2 = 0;

    for (int col = 1; col < matriz.tam; col++) {

        if (menor >= matriz.datos[fila][col])
        {
            if (menor == matriz.datos[fila][col])
            {
                esMenor = false; // If there's a repetition, it's not strictly smaller
            }
            else
            {
                menor = matriz.datos[fila][col];
                col2 = col;
            }
        }
    }

    fil2 = fila; // The row index remains the same

    return esMenor;
}*/
