#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool mod24(int numero1);
bool filtroDivisorPrimo(int numero2);

int main(){
    int n;

    cout << "Introduzca un numero y veras si cumple la condicion mod24=1: ";
    cin >> n;

   // while (n != 0)
    //{
        //cout << boolalpha<<mod24(n) << endl;

        if (mod24(n)==true)
        {
            cout << "Cumple la condicion y el modulo de tu numero respecto a 24 es igual a 1"<< endl;
        }
            else
            {
                cout << "No cumple la condicion" << endl;
            }

        cout << "\n";

        if (filtroDivisorPrimo(n)==true)
        {
            cout <<n<<" es primo"<< endl;
        }
            else
            {
                cout <<n<<" NO es primo"<< endl;
            }

    //cout << "Introduce otro numero: ";
    //cin >> n;

    //}
return 0;

}

bool mod24(int numero1)
{
    if (numero1*numero1%24==1)
    {
        return true;
    }
        else
        {
            return false;
        }
}
bool filtroDivisorPrimo(int numero2)
{
                            // CONDICIONES: ES PRIMO SI 1. NO SE PUEDE DIVIDIR ENTRE 2 Y RAIZ DE N, (2 Y EL MISMO)
    int divisores =2;       // DE 2 sqrt(N)
    int cntDivisores=0;     // Si es mas de 0 no es primo, a no ser que sea 2
    int tope = sqrt(numero2);

    while (divisores >= 2 && divisores <= tope)
    {

        if (numero2%divisores == 0)
        {
            cntDivisores++;
        }
        divisores++;
    }

        if (cntDivisores == 0 )
        {
            return true;
        }
            else
            {
                return false;
            }
}
