#include <iostream>
#include <array>
#include <math.h>

/*
Programa que lee una palabra (formada por
letras minúsculas), y escribe su plural según las
siguientes reglas:

– Si acaba en vocal se le añade la letra 's'.

– Si acaba en consonante se le añaden las
letras 'e‘ y ‘s'. Si la consonante es la letra
'z', se sustituye por la letra 'c‘.

– Suponemos que la palabra introducida es
correcta.
*/

using namespace std;

bool esVocal(char car)
{
    bool vocal = false;

    if (car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u')
    {
        vocal = true;
    }

    return vocal;
}

void construirPalabra(string& cadena)
{
    int tam = cadena.size() - 1;

    if (esVocal(cadena[tam]))
    {
        cadena += 's';
    }
    else if (!esVocal(cadena[tam]))
    {
        if (cadena[tam] == 'z')
        {
            cadena[cadena.size() - 1] = 'c';
        }
        cadena += "es";
    }
}

int main(){
    string cadena;

    cout << "Introduzca una palabra en minusculas: ";
    cin >> cadena;
    cout << "La palabra " << cadena << " corregida es: ";
    construirPalabra(cadena);
    cout << cadena << endl;
return 0;

}
