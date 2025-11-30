#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 7;
typedef array<int, TAM> TColecion;

void leerColeccion(TColecion& col)
{
    cout << "Introduzca la primera coleccion (" << TAM << " numeros enteros): ";
    for (int i = 0;i < TAM ;i++ )
    {
        cin >> col[i];
    }
}

void escribirColeccion(TColecion& col, int num)
{
    cout << "coleccion" << num << " = ";
    for (int i = 0;i < TAM ;i++ )
    {
        cout << col[i] << " ";
    }
}

void rotacionesDerecha(TColecion& col)
{
    int ultNum = col[TAM - 1];  // Guardo el ultimo numero
    for (int i = TAM - 1;i >= 1 ;i-- )
    {
        col[i] = col[i - 1];
    }
    col[0] = ultNum;    // Pongo el ultimo numero en primera posicion
}

void rotacionesIzquierda(TColecion& col)
{
    int primNum = col[0];

    for (int i = 0;i < TAM - 1  ;i++ )
    {
        col[i] = col[i + 1];
    }
    col[TAM - 1] = primNum;
}

int main(){
    TColecion col1 = {9, 5, 1, 4, 12, 9, -1};
    TColecion col2 = {3, -1, 7, 4, 9, 8, 1};
    int numRot;

    do
    {
        cout << "Introduzca el numero de rotaciones (> 0): ";
        cin >> numRot;
    } while (numRot <= 0);

    /*leerColeccion(col1);
    leerColeccion(col2);*/

    escribirColeccion(col1,1);
    cout << endl;
    escribirColeccion(col2,2);
    cout << endl;

    // Rotaciones hacia derecha (coleccion 1)
    for (int i = 0;i < numRot ;i++ )
    {
        rotacionesDerecha(col1);
    }

    // Rotaciones hacia izquierda (coleccion 2)
    for (int i = 0;i < numRot ;i++ )
    {
        rotacionesIzquierda(col2);
    }

    cout << "Tras " << numRot << " rotaciones: " << endl;
    escribirColeccion(col1,1);
    cout << endl;
    escribirColeccion(col2,2);
return 0;

}
