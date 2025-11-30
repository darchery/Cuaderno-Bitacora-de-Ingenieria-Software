/*
Escribe un algoritmo que encuentre el mayor, el menor y la media aritmética de una colección
de N números enteros leídos por el teclado donde N es el primero de los números. Un ejemplo
de ejecución sería:
Introduzca la secuencia de numeros: 5 3 7 2 1
El mayor es: 7
El menor es: 1
La media es: 3.6*/

#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int n;
    int media = 0;
    int den = 0;

    cout << "Introduzca una secuencia de numeros(el primer numero es numero de valores de la secuencia) acabado en 0: ";
    cin >> n;

    int menor = n;
    int mayor = n;

    if (n != 0)
    {
        for (int i = n; i > 0 ; i-- )
        {
            if (n > mayor)
            {
                mayor = n;
            }
            else if (n < menor)
            {
                menor = n;
            }

            media += n;
            den++;
            cin >> n;
        }
    }
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
    cout << "Media: " << double(media)/den << endl;
return 0;

}
