#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void imprimirPiramide(int N);

int main(){
    int N;

    do
    {
        cout << "Introduzca un numero(>0): ";
        cin >> N;
        imprimirPiramide(N);
    } while (N < 0);
return 0;

}

void imprimirPiramide(int N)
{
    for (int filas = 1;filas < N ;filas++ )
    {
        for (int columnas = 1;columnas < filas;columnas++ )
        {

        }
    }
}
