#include <iostream>
#include <array>
#include <math.h>

using namespace std;

double factorial(double num);
double numeroE(double num, double prec);

int main(){
    double n;
    double precision = 0.0001;

    cout << "Introduzca el exponente para cacular e^x (> -1): ";
    cin >> n;

    if (n == 0)
    {
        cout << "e elevado a " << n << " es : " << 1 << endl;
    }
    else
    {
        cout << "e elevado a " << n << " es : " << numeroE(n,precision) << endl;
    }

return 0;

}

double numeroE(double num, double prec)
{
    double suma = 0;
    double term;
    for (double i = 0;i < num ;i++ )
    {
        term = pow(num,i)/factorial(i);
        if (term < 0 && term > prec)
        {
            term = abs(term);
        }
        suma += term;
        cout << suma << endl;
    }
    return suma;
}

double factorial(double num)
{
    double fact = 1;

    for (double i = 1;i <= num ;i++ )
    {
        fact *= i;
    }
    return fact;
}
