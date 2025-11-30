#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int  TAM = 7;

typedef array<int, TAM> TColeccion;

void leerDatos(int& numRot, TColeccion& col1, TColeccion& col2)
{
    do
    {
        cout << "Introduzca las rotaciones que va a hacer: ";
        cin >> numRot;
    } while (numRot <= 0);

    cout << "Introduzca la primera lista de " << TAM << " elementos: ";
    for (int i = 0;i < TAM ;i++ )
    {
        cin >> col1[i];
    }
    cout << endl;
    cout << "Introduzca la primera lista de " << TAM << " elementos: ";
    for (int i = 0;i < TAM ;i++ )
    {
        cin >> col2[i];
    }
}

void rotacionesDerecha(int numRot, TColeccion& col1)
{
    numRot %= TAM;
    while (numRot > 0)
    {
        int ultNum = col1[TAM - 1];
        for (int i = TAM - 1;i > 0;i-- )
        {
            col1[i] = col1[i - 1];
        }
        col1[0] = ultNum;
        numRot--;
    }
}

void rotacionesIzquierda(int numRot, TColeccion& col2)
{
    numRot %= TAM;
    while (numRot > 0)
    {
        int primNum = col2[0];
        for (int i = 1;i < TAM ;i++ )
        {
            col2[i] = col2[i + 1];
        }
        col2[TAM - 1] = primNum;
        numRot--;
    }
}

void escribir(TColeccion& col, int n)
{
    cout << "coleccion" << n << " = ";
    for (int i = 0;i < TAM ;i++ )
    {
        cout << col[i] << " ";
    }
}

int main(){
    int numRot;
    TColeccion col1, col2;

    leerDatos(numRot, col1, col2);
    escribir(col1, 1);
    cout << endl;
    escribir(col2, 2);
    rotacionesDerecha(numRot, col1);
    rotacionesIzquierda(numRot, col2);
    cout << endl;
    cout << "Tras las " << numRot << " rotaciones: " << endl;
    escribir(col1, 1);
    cout << endl;
    escribir(col2, 2);
return 0;

}
