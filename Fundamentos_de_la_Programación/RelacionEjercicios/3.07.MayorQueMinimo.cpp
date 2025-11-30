#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N = 10;

typedef array<int, N> TVector;

void leer(TVector& v)
{
    cout << "Introduzca 10 numeros enteros: ";
    for(int i = 0;i < N;i++)
    {
        cin >> v[i];
    }
}

int mayorQueMinimo(TVector& v)
{
    int mayor = v[0];
    bool found = false;

    for(int i = 0;i < N && found == false ;i++)
    {
        if(mayor < v[i])
        {
            mayor = v[i];
            found = true;
        }
    }
    return mayor;
}

int main(){
    TVector v1;

    leer(v1);

    cout << "Un elemento Mayor que el Minimo es: " << mayorQueMinimo(v1) << endl;
return 0;

}
