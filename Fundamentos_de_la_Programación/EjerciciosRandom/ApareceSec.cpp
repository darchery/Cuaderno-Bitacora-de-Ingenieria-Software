/*Diseña un algoritmo que lea un número entero n por teclado (hay que controlar que sea distinto
de 0). Después se le pedirá al usuario que introducirá por teclado una secuencia de números
enteros terminada en 0. El algoritmo debe determinar si el número n aparece o no en la
secuencia. Para ello, el algoritmo leerá números de la secuencia hasta encontrar el número n o
bien hasta leer el 0, mostrando por pantalla el mensaje correspondiente. En el caso de que se
detecte el número buscado en la secuencia ya no se seguirán leyendo más números. Dos
ejemplos de ejecución serían:
Introduzca el numero entero a buscar (distinto de 0): 3
Introduzca una secuencia de numeros enteros terminada en 0: 4 2 3 -5 7 -6 0
El numero 3 SI aparece en la secuencia
*/

#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int n;
    int cadena;
    bool encontrado = false;

    cout << "Introduzca un numero para buscarlo en la secuencia mayor que 0: ";
    cin >> n;

    if (n < 0)
    {
        cout << "ERROR: introduzca un numero mayor que 0..." << endl;
    }
    else
    {
        cout << "Introduzca la sencuencia acabada en 0: ";
        cin >> cadena;

        while (cadena != 0 && encontrado == false)
        {
            if (cadena == n)
            {
                encontrado = true;
            }
            cin >> cadena;
        }

        if (encontrado)
        {
            cout << n << " si aparece en la secuencia" << endl;
        }
        else
        {
            cout << n << " NO aparece en la secuencia" << endl;
        }
    }

return 0;

}
