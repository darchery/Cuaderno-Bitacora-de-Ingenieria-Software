#include <iostream>
#include <array>
#include <math.h>

// HACER LA SECUENCIA 1 + X + X^2/2! + X^3/3!

using namespace std;

const int UMBRAL = 10;

int factorial(int den);
double sumaSerie(int x);
int elevado(int num, int i);

int main(){
    int x;
    cout << "Introduzca X: ";
    cin >> x;
    cout << "La suma de la serie es : " << sumaSerie(x) << endl;

return 0;

}

// FORMULA = X^I / I!
double sumaSerie(int x)
{
    double suma = 1;
    int i = 1;

    while (i <= UMBRAL)
    {
        suma += (elevado(x,i)/factorial(i));
        i++;
    }
    return suma;
}

int elevado(int num, int i)
{
    for (int j = 0;j < i ;j++ )
    {
        num *= num;
    }
    return num;
}

int factorial(int den)
{
    int fact = 1;
    for (int i = 1;i <= den ;i++ )
    {
        fact *= i;
    }
    return fact;
}
