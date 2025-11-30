#include <iostream>
#include <array>
#include <math.h>

using namespace std;

/*
Diseña un procedimiento recursivo que lea por teclado una secuencia de caracteres de
longitud arbitraria terminada en un punto, y la imprima en orden inverso (el carácter punto no
se escribe, sólo es un carácter terminador). El procedimiento no tiene parámetros. Diseña
también un algoritmo principal (main) para probar el procedimiento. Por ejemplo, si se
introduce por teclado la secuencia hola, la salida por pantalla será aloh.*/

const int MAX_TAMANO = 100;

void cadenaInversa(char cadena[]);

void escribirReves()
{
    char c;
    cin >> c;

    if (c != '.')   /// CASO BASE
    {
        escribirReves();    /// alo
        cout << c;          /// c = 'h'
    }
}

int main(){
    char c;

    cout << "Introduzca la cadena de caracteres acabada en punto: ";
    escribirReves();
return 0;

}


