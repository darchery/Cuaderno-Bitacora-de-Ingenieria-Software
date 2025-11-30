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
    int j = 0;

    for (int i = 0;i < int(cadena.size()) && found == false ;i++ )
    {
        // cout << "Subcadena: " << subcadena[j] << endl;
        // cout << "Cadena: " << cadena[i] << endl;

        if (cadena[i] == subcadena[j])
        {
            while (cadena[i] == subcadena[j] && j <= int(subcadena.size()) )
            {
                if (cadena[i] == subcadena[subcadena.size() - 1])
                {
                    found = true;
                }
                j++;
            }
        }
    }
    return found;
}

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
