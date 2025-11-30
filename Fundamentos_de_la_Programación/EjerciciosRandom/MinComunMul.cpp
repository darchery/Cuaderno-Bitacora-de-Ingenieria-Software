#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int mcm(int num1,int num2);

int main(){
    int n1, n2;
    int res;
    cout << "Introduzca 2 numeros par calcular su MCM: ";
    cin >> n1 >> n2;

    res = mcm(n1,n2);
    cout << "El MCM de " << n1 << " y " << n2 << " es " << res << endl;

return 0;

}

int mcm(int num1,int num2)
{
    int lcm;
    int aux;
    bool encontrado = false;

    if ( num1 < 0  || num2 < 0)
    {
        cout << "Introduzca numero mayores que positivos y mayores que 0..." << endl;
    }
    else
    {
        if (num2 > num1)
        {
            aux = num1;
            num1 = num2;
            num2 = aux;
        }
        lcm = num1;

        while (encontrado == false)
        {
            if (lcm%num1 == 0 && lcm%num2 == 0)
            {
                encontrado = true;
            }
            lcm++;
        }
        return lcm -1;
    }
}

