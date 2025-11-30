/*Desarrolla un algoritmo para el siguiente juego entre un usuario y la máquina:
Se leen dos números enteros que el usuario introduce por teclado y que representan el límite
inferior y superior de un determinado rango de valores. Después el usuario piensa un número
en ese rango. La máquina tiene que acertar dicho número. Para ello propone un número y el
usuario responde con un carácter: > (si el número pensado es mayor que el propuesto), < (si el
número pensado es menor que el propuesto) o = (si el número pensado es igual al propuesto).
Si la respuesta es > o <, la máquina propondrá otro número. El proceso se repite hasta que la
máquina acierte el número pensado por el usuario.
*/

#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    char operador;
    int inf, sup, numPropuesto;

    cout << "Introduzca los limites inferiores y superiores: ";
    cin >> inf >> sup;

    while (operador != '=')
    {
        numPropuesto = (inf + sup)/2;

        cout << "Es tu numero el " << numPropuesto << " ?" << "(> = <): ";
        cin >> operador;

        if (operador == '>')
        {
            inf = numPropuesto + 1;
        }
        else if (operador == '<')
        {
            sup = numPropuesto - 1;
        }
    }

    if (inf > sup)
    {
        cout << "Me has mentido\n";
    }
    else {
        cout << "ACERTADO\n";
    }
return 0;

}
