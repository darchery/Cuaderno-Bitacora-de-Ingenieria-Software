/*Write a program to eval the value of s for a real number x in the next series:
s = 1 + x + x^2/2! + x^3/3! + . . .
There must to be added only the first terms until the power is const int MAXPOW=10;. Use a loop and try to
simplify the calculations building the next power using the already calculated (multiplying it by x) and also do the
same with the factorial (multiplaying the previous factorial by i being i the loop index
*/

#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    double x;
    double sum = 1;
    int potencia = 1;
    int fact = 1;

    cout << "Introduzca el numero de veces que se sumara la serie: ";
    cin >> x;

    for (int i=1 ; i <= x ; i++)
    {
        cout << "Factorial 1: " << fact << endl;
        fact *= fact;
        sum += pow(x,potencia)/fact;
        cout << "Factorial 2: " << fact << endl;
        potencia++;
        fact++;
    }

    cout << "Resultado: " << sum << endl;
return 0;

}
