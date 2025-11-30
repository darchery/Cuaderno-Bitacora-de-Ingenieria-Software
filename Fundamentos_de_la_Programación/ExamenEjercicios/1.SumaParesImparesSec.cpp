#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int sumaPares(int a, int b);
int sumaImpares(int a, int b);

int main(){
    int a, b;

    do
    {
        cout << "Introduzca un intervalo de numeros separados por un espacio:";
        cin >> a >> b;

    } while (a > b);

    int sumPar = sumaPares(a,b);
    int sumImpar = sumaImpares(a,b);

    cout << "La suma de los numeros pares del " << a << " al " << b <<" es: " << sumPar << endl;
    cout << "La suma de los numeros impares del " << a << " al " << b <<" es: " << sumImpar << endl;
return 0;

}

int sumaPares(int a, int b)
{
    int sumPar = 0;

    for (int i = a;i <= b;i++)
    {
        if (i % 2 == 0)
        {
            sumPar += i;
        }
    }
    return sumPar;
}

int sumaImpares(int a, int b)
{
    int sumImpar = 0;

    for (int i = a;i <= b;i++)
    {
        if (i % 2 != 0)
        {
            sumImpar += i;
        }
    }
    return sumImpar;
}
