#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int mcdEuclideo(int numero1 ,int numero2);

int main(){
    int n1, n2;

    cout << "Introduzca 2 numeros separados por espacios para calcular su MCD: ";
    cin >> n1 >> n2;

    if ( n1 < 0  || n2 < 0)
    {
        cout << "Introduzca numero mayores que positivos y mayores que 0..." << endl;
    }
        else{
                cout << "El mcd de " << n1 << " y " << n2 << " es " << mcdEuclideo(n1,n2) << endl;
        }



return 0;

}

int mcdEuclideo(int numero1 ,int numero2)
{
    bool mcdEncontrado = false;
    int res = 1;

    while (mcdEncontrado == false)
    {
        if (numero2 > numero1)
        {
            numero2 = numero2 -numero1;
        }
            else if (numero1 > numero2)
            {
                numero1 = numero1 -  numero2;
            }
                else if (numero2 == numero1)
                {
                    res = numero1;
                    mcdEncontrado = true;
                }
    }
    return res;
}

