#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int const N = 5;

typedef array <int, N> Vector;

void leerVector(Vector& v)
{
    cout << "Introduzca " << N << " numeros: ";
    for (int& x: v)
    {
        cin >> x;
    }
}

/*void mostrarVector(Vector& v)
{
    cout << endl;
    for (int x: v)
    {
        cout << x;
    }
}*/

int posicionMayor(const Vector& v, int& mayor)
{
    mayor = v[0];
    for (int i = 0;i < N;i++ )
    {
        if (mayor < v[i])
        {
            mayor = v[i];
        }
    }
    return mayor;
}

int posicionMenor(const Vector& v, int& menor)
{
    menor = v[0];
    for (int i = 0;i < N;i++ )
    {
        if (menor > v[i])
        {
            menor = v[i];
        }
    }
    return menor;
}

double media(const Vector& v, double med, double M)
{
    med = 0.0;
    for (int i = 0;i < N ;i++ )
    {
        med += v[i];
    }
    return med / M;
}

int main(){
    Vector v1;
    int mayor;
    int menor;
    double M = 5;
    double med;

    leerVector(v1);
    cout << "La posicion del mayor elemento es: " << posicionMayor(v1, mayor) << endl;
    cout << "La posicion del menor elemento es: " << posicionMenor(v1, menor) << endl;
    cout << "Media del array: " << media(v1, med, M) << endl;
    //cout << "La psicion del elemento mas cercano
return 0;

}
