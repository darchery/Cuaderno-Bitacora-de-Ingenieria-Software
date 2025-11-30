#include <iostream>
#include <array>
#include <math.h>

// A Y B SON AMIGOS SI LA SUMA DE SUS DIVISORES DE A ES IGUAL A B Y LA SUMA DE LOS DIVISORES DE B ES IGUAL A A
// EJ: 220 Y 284 SON AMIGOS
using namespace std;

bool numerosAmigos(int a, int b);
int sumaDivisores(int num);

int main(){
    int a, b;

    cout << "Introduzca 2 numeros separados por espacios para ver si son amigos: ";
    cin >> a >> b;

    if (numerosAmigos(a,b))
    {
        cout << a << " y " << b << " son numeros amigos" << endl;
    }
    else
    {
        cout << a << " y " << b << " NO son numeros amigos" << endl;
    }
return 0;

}

bool numerosAmigos(int a, int b)
{

    if (sumaDivisores(a) == b && sumaDivisores(b) == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int sumaDivisores(int num)
{
    int suma = 0;
    for (int div = 1;div < num ;div++ )
    {
        if (num % div == 0)
        {
            suma += div;
        }
    }
    return suma;
}
/*
bool numerosAmigos(int a, int b)
{
    int sumA = 0; // DEBERIA SER IGUAL A B , es la suma de los divisores de A
    int sumB = 0; // DEBERIA SER IGUAL A A , es la suma de los divisores de B

    for (int divA = 1;divA < a ;divA++ )
    {
        if (a % divA == 0)
        {
            sumA += divA;
        }
    }

    for (int divB = 1;divB < b ;divB++ )
    {
        if (b % divB == 0)
        {
            sumB += divB;
        }
    }

    if (sumA == b && sumB == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}
*/
