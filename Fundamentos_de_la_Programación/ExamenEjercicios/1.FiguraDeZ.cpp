#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void dibujarZ(int n);

int main(){
    int n;

    do
    {
        cout << "Introduzca un numero (>3): ";
        cin >> n;
        cout << "\n";

    } while (n < 3);

    dibujarZ(n);
return 0;

}
// ARREGLAR
// ME HE FIJADO QUE EL DIAGONAL SIEMPRE EMPIEZA EN 1 Y N Y ACABA AL REVES N Y 1 Y PASA POR EJ:5 1,5 ,2,4 ,3,3 ,4,2 ,5,1
void dibujarZ(int n)
{
    for (int filas = 1;filas <= n ;filas++)
    {
        for (int columnas = 1;columnas <= n ;columnas++ )
        {
            if (filas == columnas || filas == n || filas == 1)
            {
                cout << "&";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
