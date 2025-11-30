#include <iostream>
#include <array>
#include <string>
#include <math.h>
#include <sstream>

/// LO HARÉ MEDIANTE 2 MANERAS, MEDIANTE STOI Y MEDIANTE UN BUCLE FOR

using namespace std;

void leer(string& cadena)
{
    cout << "Introduzca una cadena numerica: ";
    cin >> cadena;
}

int stringToInt(string cadena)
{
    int res = stoi(cadena);
    return res;
}

int stringToIntFor(string cadena)
{
    int res = 0;

    for (char c : cadena)
    {
        if (c >= '0' && c <= '9')
        {
            res = res * 10 + (c - '0');
        }
    }

    return res;
}

int sstreamConvert(string cadena)
{
    int res;
    stringstream convertir;

    convertir << cadena;

    convertir >> res;


    return res;
}

int main(){
    string cadena;
    leer(cadena);

    cout << "La cadena " << cadena << " to int con stoi es: " << stringToInt(cadena) << endl;
    cout << "La cadena " << cadena << " to int con FOR es: " << stringToIntFor(cadena) << endl;
    cout << "La cadena " << cadena << " to int con sstream es: " << sstreamConvert(cadena) << endl;
return 0;

}
