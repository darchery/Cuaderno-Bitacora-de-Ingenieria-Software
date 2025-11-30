#include <iostream>
#include <array>
#include <string>
#include <math.h>

/*
Diseña un algoritmo lea de teclado dos palabras (dos cadenas de caracteres, todos en minúscula)
y muestre por pantalla un mensaje indicando si la letra inicial de la primera coincide o no con
alguno de los caracteres de la segunda. La búsqueda a realizar se hará de forma eficiente, esto
es, en el caso de producirse una coincidencia ya no se seguirán consultando más caracteres de la
segunda palabra.

Ejemplos de ejecución:

Introduzca dos palabras: primera segunda
La letra inicial de la primera palabra NO aparece en la segunda palabra.

Introduzca dos palabras: antonio maria
La letra inicial de la primera palabra SI aparece en la segunda palabra.
*/

using namespace std;

bool apareceSegunda(char primero, string& p2)
{
    bool found = false;
    for (int i = 0;i < int(p2.size()) && found == false ;i++ ) /// O CON size_t i = 0; i < p2.size()
    {
        if (primero == p2[i])
        {
            found = true;
        }
    }
    return found;
}

int main(){
    string p1;
    string p2;

    cout << "Introduzca dos palabra: ";
    cin >> p1 >> p2;

    char primero = p1[0];

    if (apareceSegunda(primero,p2))
    {
        cout << "La letra inicial de la primera palabra SI aparece en la segunda palabra." << endl;
    }
    else
    {
        cout << "La letra inicial de la primera palabra NO aparece en la segunda palabra." << endl;
    }

return 0;

}
