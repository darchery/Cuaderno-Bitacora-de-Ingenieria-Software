/*Escribe un algoritmo que lea un lista de números enteros terminada en 0 y que encuentre y
escriba en la pantalla la posición de la primera y de la última aparición del número 12 dentro de
la lista. Ejemplos de ejecución:

Introduzca la secuencia de numeros (0 para terminar): 3 -2 4 6 0
Primera Aparicion del 12: 0
Ultima Aparicion del 12: 0
Introduzca la secuencia de numeros (0 para terminar): 3 12 4 6 0
Primera Aparicion del 12: 2
Ultima Aparicion del 12: 2
Introduzca la secuencia de numeros (0 para terminar): 3 12 4 12 -5 8 12 0
Primera Aparicion del 12: 2
Ultima Aparicion del 12: 7
*/

#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int secuencia;
    int primer12;
    int ultimo12;
    int cnt12 = 0;
    int pos=1;

    cout << "Introduzca la secuencia de numeros (0 para terminar): ";
    cin >> secuencia;

    while (secuencia != 0)
    {
        if (secuencia == 12 && cnt12== 0)
        {
            primer12 = pos;
            cnt12++;
        }
        else if (secuencia == 12 && cnt12 != 0)
        {
            ultimo12 = pos;
        }
        cin >> secuencia;
        pos++;
    }
    cout << "Primera Aparicion del 12: " << primer12 << endl;
    cout <<"Ultima Aparicion del 12: " << ultimo12 << endl;
return 0;

}
