#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool esPerfecto(int num);
void imprimirDivisores(int num);
int main(){
    int n;

    cout << "Introduzca un numero para ver si es perfecto: ";
    cin >> n;

    if (esPerfecto(n))
    {
        cout << "El numero " << n << " ES perfecto" << endl;
    }
    else
    {
        cout << "El numero " << n << " NO perfecto" << endl;
    }
return 0;

}

bool esPerfecto(int num)
{
    int sumDiv = 0;
    for (int div = 1;div < num ;div++ )
    {
        if (num % div == 0)
        {
            sumDiv += div;
            cout << "Divisores: " << div << endl;
        }
    }

    if (sumDiv == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}
