#include <iostream>
#include <array>
#include <math.h>

/*
Diseña un algoritmo lea de teclado dos palabras (dos cadenas de caracteres, todos en minúscula)
y muestre por pantalla un mensaje indicando si la primera palabra es una subcadena o no
contenida en la segunda. La búsqueda a realizar se hará de forma eficiente, esto es, en el caso de
detectar dicha subcadena ya no se seguirán consultando más caracteres de la segunda palabra

Ejemplos de ejecución:

Introduzca dos palabras: pera esperando
La primera palabra SI es una subcadena contenida en la segunda palabra.

Introduzca dos palabras: pero esperando
La primera palabra NO es una subcadena contenida en la segunda palabra.
*/

using namespace std;

/// HACERLO DE NUEVO PERO USANDO SUBTRING, cadena.subtr()
/// EJ: pera esperando

bool apareceSubcadena(string subcadena, string cadena)
{
    bool found = false;

    for (size_t i = 0;i <= cadena.size() - 1 && found == false ;i++ )
    {
        for (size_t j = 0;j <= cadena.size() - 1 && found == false ;j++)
        {
            cout << "Subcadena: " << cadena.substr(i,j) << endl;
            cout << "Cadena: " << subcadena << endl;
            if (cadena.substr(i,j) == subcadena)                        /// ESTO PRUEBA TODAS LAS COMBINACIONES POSIBLES ORDENADAS Y SI ALGUNA ES IGUAL
            {                                                           /// A LA SUBCADENA EL BUCLE ACABA
                found = true;
            }
        }
    }
    return found;
}
// pera esperando
int main(){
    string subcadena;
    string cadena;

    cout << "Introduca una subcadena y la cadena: ";
    cin >> subcadena >> cadena;

    if (apareceSubcadena(subcadena,cadena))
    {
        cout << "La primera palabra SI es una subcadena contenida en la segunda palabra." << endl;
    }
    else
    {
        cout << "La primera palabra NO es una subcadena contenida en la segunda palabra." << endl;
    }

return 0;

}
