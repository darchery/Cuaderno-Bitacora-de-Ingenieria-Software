#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void trianguloRectanEntero(int& k);

int main(){
    int k;

    cout << "Introduce el numero par o impar con el que se haran los TRE (triangulo rectangulo entero): ";
    cin >> k;
    trianguloRectanEntero(k);

return 0;

}

void trianguloRectanEntero(int& k)
{
    int a,b,c;

    for (int i = 1; i <= k; i++)
    {
        if (i%2!=0)
        {
            a = 2*i+1;
            b = 2*i*(i+1);
            c = i+1;
            cout << "El TRE numero "<< i <<" se conforma por: " << a << ", "<<b << " y " << c << endl;
        }
            else if (i%2==0)
            {
                a = 2*i;
                b = i*i-1;
                c = i*i+1;
                cout << "El TRE numero "<< i <<" se conforma por: " << a << ", "<<b << " y " << c << endl;
            }
    }

}


