#include <iostream>
#include <array>
#include <math.h>

using namespace std;

// Realizar un programa que lea una secuencia de caracteres terminada en un punto (.). El
// programa deberá mostrar la longitud de cada secuencia de caracteres entre dos comas y la
// longitud de las secuencias antes la primera coma y detrás de la última. Por ejemplo, para la
// secuencia aabc,adddff,ddf,ee,,ddd,e. El programa deberá mostrar 4 6 3 2 0 3 1

void analizarCadena(char cadena);

// EL UNICO FALLITO ES QUE LA ULTIMA E NO LA LEE PORQUE NO ESTÁ ENTRE COMAS

int main(){
    char cadena;

    cout << "Introduzca una cadena acabada en punto: ";
    cin.get(cadena);
    analizarCadena(cadena);

return 0;

}

void analizarCadena(char cadena)
{
    int cntCar = 0;
    while (cadena != '.')
    {
        if (cadena == ',')
        {
            cout << cntCar << " ";
            cntCar = 0;
        }
        else{
            cntCar++;
        }
        cout << cadena << endl;
        cin.get(cadena);
    }
}
