#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void dibujarMarco(int n);

int main(){
    int n;

    do
    {
        cout <<"Introduzca un numero para hacer el marco: ";
        cin >> n;

    } while (n < 0);

    dibujarMarco(n);

return 0;

}
void dibujarMarco(int n)
{
    for (int filas = 1; filas <= n ;filas++ )
    {
        for (int columnas = 1; columnas <= n ;columnas++)
        {
            if (columnas == 1 || filas == n || columnas == n || filas == 1)
            {
                cout << "+";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
