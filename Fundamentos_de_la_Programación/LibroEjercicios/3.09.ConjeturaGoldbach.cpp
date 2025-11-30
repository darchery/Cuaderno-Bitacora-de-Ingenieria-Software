#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool descomponer(int numPar);

int main(){
    int n;
    int k = 0;
    bool seCumpleHastaK = true;

    cout << "Introduzca el numero par para descomponerlo en 2 numero primos: ";
    cin >> n;

    while (seCumpleHastaK && k <= n)
    {
        k += 2; //siguiente par;

            if (descomponer(n) == false)
            {
                seCumpleHastaK = false;
            }
    }
        if (descomponer(n)==true)
        {
            cout << n << " se puede descomponer en 2 numeros primos" << endl;
        }
            else
            {
                cout << n << " NO se puede descomponer en 2 numeros primos" << endl;
            }

return 0;

}
bool descomponer(int numPar)
{
    // NECESITAMOS QUE SUMANDO 1 Y SUMANDO 2 SEAN NUMERO PRIMOS Y QUE SE VERIFIQUE SI SON LA SUMA DE EL NUMERO PAR
    // SI LO ES SE PARA EL BUCLE YA QUE VA CON WHILE FALSE
    // Y QUE VAYAN AVANZANDO LOS PRIMOS

    bool conseguido = false;
    int sumando1=0;
    int sumando2=0;

    while (conseguido==false)
    {
        for (int i = 0;i <= sumando1 ; i++ )
        {


            if (sumando1 + sumando2 == numPar)
            {
                return true;
            }
                else
                {
                    return false;
                }
        }


    }



}

