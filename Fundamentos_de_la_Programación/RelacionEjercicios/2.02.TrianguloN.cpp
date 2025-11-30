#include <iostream>
#include <array>
#include <math.h>

/*Escribe un programa que lea un número natural N por teclado y dibuje un triángulo de
asteriscos con base y altura N. Por ejemplo, si N=5 debería dibujarse:
     *
    * *
   * * *
  * * * *
 * * * * * */

using namespace std;

int main(){
    int N;

    cout << "Introduzca el tamaño del triangulo(acaba el programa en 0): ";
    cin >> N;

    while (N != 0)
    {
        for (int filas = 0; filas < N ; filas++)
        {
            for (int espacios = 0; espacios < N-filas-1 ;espacios++ )
            {
                cout <<" ";
            }

            for (int columnas = 0; columnas <= filas ; columnas++ )
            {
                cout <<"* ";
            }
            cout << endl;
        }
        cout << "Introduzca el tamaño del triangulo(acaba el programa en 0): ";
        cin >>  N;
    }
return 0;

}

