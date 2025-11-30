/*
Diseña un algoritmo que determine si la cadena abc aparece en una sucesión de caracteres
introducida por el usuario y cuyo final viene dado por un punto. El algoritmo leerá caracteres
hasta encontrar la cadena abc o bien hasta leer el punto, mostrando por pantalla el mensaje
correspondiente. Al igual que en el problema anterior, en el caso de que se detecte la presencia
de la cadena buscada, ya no se seguirán leyendo más caracteres. Por ejemplo, si se introduce el
texto hpabxbcpq., la salida será Cadena abc NO encontrada. En cambio, si se
introduce el texto haabcbxbcpq., la salida será Cadena abc SI encontrada.
*/

#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    char cadena;
    bool encontrado = false;

    cout << "Introduzca la cadena acabada en punto: ";
    cin.get(cadena);

    while (cadena != '.' && !encontrado)
    {
        if(cadena=='a')
        {
            cin.get(cadena);

            if(cadena=='b')
            {
				cin.get(cadena);

				if(cadena=='c')
				{
					encontrado=true;
				}
			}
        }
        cin.get(cadena);
    }
    if (encontrado)
    {
        cout << "abc ha sido encontrado en la cadena" << endl;
    }
    else
    {
        cout << "abc NO ha sido encontrado en la cadena" << endl;
    }

return 0;

}
