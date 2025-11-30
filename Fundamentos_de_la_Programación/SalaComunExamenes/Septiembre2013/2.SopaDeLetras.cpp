#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N = 8;
typedef array<char, N> TFila;
typedef array<TFila, N> TSopa;

struct TLista {
    TSopa sopa;
    string palabra;
};

void leerSopa(TLista& lista)
{
    for (int i = 0;i < N;i++ )
    {
       for (int j = 0;j < N ;j++ )
       {
            cin >> lista.sopa[i][j];
       }
    }
}

bool celdaValida(int fila, int col)
{
    return fila >= 0 && fila < N && col >= 0 && col < N;
}

void probarOrientaciones(TLista& lista ,int& fila, int& col, string& orientacion, bool& aparece)
{
    int index;
    aparece = true;

    // Arriba
    if (celdaValida(fila-1,col) && lista.sopa[fila-1][col] == lista.palabra[1] && aparece)
    {
        index = 2;
        orientacion =  "Norte";
        for (int i = fila-2 ;i >= 0 && aparece;i-- )
        {
            if (lista.sopa[i][col] != lista.palabra[index])
            {
                aparece = false;
            }
            index++;
        }
    }
    // Abajo
    aparece = true;
    if (celdaValida(fila+1,col) && lista.sopa[fila+1][col] == lista.palabra[1] && aparece)
    {
        index = 2;
        orientacion = "Sur";
        for (int i = fila+2;i < N && aparece;i++ )
        {
            if (lista.sopa[i][col] != lista.palabra[index])
            {
                aparece = false;
            }
            index++;
        }
    }

    // Derecha
    aparece = true;
    if (celdaValida(fila,col+1) && lista.sopa[fila][col+1] == lista.palabra[1] && aparece)
    {
        index = 2;
        orientacion = "Este";
        for (int i = col+2;i < N && aparece;i++ )
        {
            if (lista.sopa[fila][i] != lista.palabra[index])
            {
                aparece = false;
            }
            index++;
        }
    }

    // Izquierda
    aparece = true;
    if (celdaValida(fila,col-1) && lista.sopa[fila][col-1] == lista.palabra[1] && aparece)
    {
        index = 2;
        orientacion = "Oeste";
        for (int i = col-2;i >= 0 && aparece;i-- )
        {
            if (lista.sopa[fila][i] != lista.palabra[index])
            {
                aparece = false;
            }
            index++;
        }
    }
}

void sopaLetras(TLista& lista ,int& fila, int& col, string& orientacion, bool& aparece)
{
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            if (lista.sopa[i][j] == lista.palabra[0])
            {
                fila = i;
                col = j;
                probarOrientaciones(lista,fila,col,orientacion,aparece);
            }
        }
    }
}

int main(){
    TLista lista;
    int f, c;
    string orient;
    bool aparece;

    cout << "Introduzca " << N << " cadenas de " << N << " letras cada una de ellas: " << endl;
    leerSopa(lista);
    cout << "Introduzca la palabra a buscar: ";
    cin >> lista.palabra;
    sopaLetras(lista,f,c,orient,aparece);
    if (aparece)
    {
        cout << "La palabra " << lista.palabra << " esta en la posicion (" << f << "," << c << ") hacia el " << orient << endl;
    }
    else
    {
        cout << "La palabra " << lista.palabra << " NO aparece" << endl;
    }
return 0;

}

/* ank

wynapjgu
fplmodrd
ipiankee
riurkxrd
cjogomid
ikgoxpiq
lcdrghef
sgnpycft
*/


