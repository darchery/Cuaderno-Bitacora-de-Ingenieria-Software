#include <iostream>
#include <array>
#include <math.h>

/*
Diseña una función que recibe como parámetros de entrada un array de MAX (una constante
definida) números enteros a y un número entero, y devuelve true si el número num está
contenido en a y false en otro caso. Si num está en la colección, la búsqueda se detendrá en el
momento de encontrarlo (búsqueda eficiente). Diseña la función principal (main) para probar el
funcionamiento de la función. Para ello, se leerá de teclado una colección de MAX números
enteros con los que se rellenará el array y también se leerá el número entero a buscar en la
colección, se invocará a la función implementada y se mostrará por pantalla una indicación de si
el número está o no en la colección.

Un ejemplo de ejecución sería (MAX = 10):
Introduzca 10 numeros enteros: 4 25 -3 4 2 17 9 5 -7 8
Introduzca el numero a buscar: 2
El numero 2 SI esta en la coleccion
*/

using namespace std;

const int MAX = 10;

typedef array<int, MAX> TSec;

void leerSec(TSec& v, int& n)
{
    cout << "Introduzca 10 numeros enteros: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cin >> v[i];
    }
    cout << endl;

    cout << "Introduzca un numero a buscas: ";
    cin >> n;
}

bool numEncontrado(const TSec& v, int n)
{
    bool found = false;

    for (int i = 0;i < MAX && !found ;i++ )
    {
        if (v[i] == n)
        {
            found = true;
        }
    }
    return found;
}

int main(){
    TSec v1;
    int n;

    leerSec(v1,n);
    if (numEncontrado(v1,n))
    {
        cout << "El numero "<< n << " SI esta en la coleccion" << endl;
    }
    else
    {
        cout << "El numero "<< n << " NO esta en la coleccion" << endl;
    }
return 0;

}
