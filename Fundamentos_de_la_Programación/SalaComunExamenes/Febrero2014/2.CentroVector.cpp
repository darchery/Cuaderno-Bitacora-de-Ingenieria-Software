#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N = 5;
typedef array<int, N> TVector;

void leerVector(TVector& v)
{
    cout << "El contenido del vector es: ";
    for (int i = 0;i < N ;i++ )
    {
        cin >> v[i];
    }
}

void centroVector(TVector& v, bool& existe, int& indexEncontrado)
{
    int sumaIzq, sumaDer;
    existe = false;

    //Provamos un centro del vector
    for (int cenVec = 1;cenVec <= N - 2  && !existe;cenVec++ )
    {
        // Sumatorio Izq
        sumaIzq = 0;
        for (int i = 0;i <= cenVec - 1 ;i++ )
        {

            sumaIzq += (cenVec - i) * v[i];
        }

        //Sumatorio Der
        sumaDer = 0;
        for (int j = cenVec + 1;j <= N - 1 ;j++ )
        {
            sumaDer += (j - cenVec) * v[j];
        }
            if (sumaDer == sumaIzq)
            {
                existe = true;
                indexEncontrado = cenVec;
            }
    }

}

int main(){
    TVector v1;
    bool existe;
    int indexEncontrado;

    leerVector(v1);
    centroVector(v1,existe, indexEncontrado);
    if (existe)
    {
        cout << "El centro de este vector es el indice "<< indexEncontrado <<" (casilla donde esta el " << v1[indexEncontrado] << ")" << endl;
    }
    else
    {
        cout << "Este vector no tiene centro" << endl;
    }
return 0;

}

// 6 2 3 0 1
