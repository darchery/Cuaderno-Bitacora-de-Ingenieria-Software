#include <iostream>
#include <array>
#include <math.h>

/*
Escribe un programa que acepte como entrada desde teclado un número natural mayor que uno
(> 1) y dé como salida el resultado de realizar la descomposición en factores primos de dicho
número.
Para realizar la descomposición en factores primos se procede de la siguiente forma:
• Paso 1: Se toma como primer primo el 2 (p = 2).
• Paso 2: Se va dividiendo n por p mientras que el resto de la división sea 0. Cada vez que
se hace esto, se muestra por pantalla el valor de p y se actualiza el valor de n al valor del
cociente de la división entera de n entre p.
• Paso 3: Cuando deja de cumplirse que el resto de la división de n entre p sea 0, se pasa
al siguiente primo.
• Se repiten los pasos 2 y 3 mientras que n sea mayor o igual que p.*/

using namespace std;

int main(){
    int n;
    int p = 2;
    bool fin = false;

    cout << "Introduzca un numero para descomponerlo: ";
    cin >> n;

    if ( n < 1)
    {
        cout << "Introduzca un numero mayor que 1..." << endl;
    }
    else
    {
        cout << "Los divisores son: ";
        while (n > 0 && fin == false)
        {
            while ( n%p == 0)
            {
                cout << p << " ";
                n /= p;
            }
            p++;
            if (n < p)
            {
                fin = true;
            }
        }
    }

return 0;

}
