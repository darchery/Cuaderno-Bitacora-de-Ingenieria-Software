#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 6;
typedef array<int, MAX> TArray;

void leerArray(TArray& a)
{
    cout << "Introduzca una coleccion de 6 numeros enteros: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cin >> a[i];
    }
}

bool esNumDestacado(TArray& a, int numDes, int i)
{
    bool esDestacado = false;
    bool infEncontrado = false, supEncontrado = false;
    int index = i - 1;

    // Limite inferior
    while (a[index] == numDes && index < MAX  )
    {
        index--;
    }
    if (a[index] < numDes)
    {
        infEncontrado = true;
    }

    index = i + 1;

    // Limite superior
    while (a[index] == numDes && index < MAX)
    {
        index++;
    }
    if (a[index] < numDes)
    {
        supEncontrado = true;
    }


    // Analisis
    if (infEncontrado && supEncontrado)
    {
        esDestacado = true;
    }
    cout << endl;
    return esDestacado;
}

int recuentoNumsDestacados(TArray& a)
{
    int recuento = 0;

    for (int i = 1;i < MAX - 1 ;i++ )
    {
        if (esNumDestacado(a, a[i], i))
        {
            recuento++;
        }
    }
    return recuento;
}

int main(){
    TArray a1;

    leerArray(a1);
    cout << "En esa coleccion hay " << recuentoNumsDestacados(a1) << " numeros destacados" << endl;
return 0;

}
