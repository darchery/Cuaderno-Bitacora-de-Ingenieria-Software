#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N = 10;

typedef array <int, N> TVector;

void leer(TVector& v)
{
    cout << "Introduzca los valores del vector: ";
    for (int i = 0;i < N ;i++ )
    {
        cin >> v[i];
    }
}
/*
void leer(Tvector& v) {
    cout << "Introduzca vector: ";
    for (int& x : v){
        cin >> x;
    }
}
*/

int sumar(const TVector& v)
{
    int suma = 0;

    for (int i = 0;i < N ;i++ )
    {
        suma += v[i];
    }
    return suma;
}

void mostrar(const TVector& v)
{
    cout << "El vector es: ";
    for (int i = 0;i < N ;i++ )
    {
        cout << v[i] << " ";
    }
}
/*
void mostrar(const Tvector& v) {
    for (int x : v){
        cout << x << " ";
    }
    cout << endl;
}
*/

int main(){
    TVector v1, v2, v3;

    leer(v1);
    leer(v2);

    mostrar(v1);
    cout << endl;
    mostrar(v2);

    cout << endl;
    if (sumar(v1) == sumar(v2))
    {
        cout << "La suma de los dos vectores es la misma: " << sumar(v1) << " = " << sumar(v2) << endl;
    }
    else
    {
        cout << "La suma de los dos vectores NO es la misma: " << sumar(v1) << " = " << sumar(v2) << endl;
    }

     cout << endl;

    v3 = v2;
    mostrar (v3);
return 0;

}
//1 2 3 4 5 6 7 8 9 10
