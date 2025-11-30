#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int n;
    int numPrimo = 2;
    int suma = 0;
    int div = 1;
    int cntPrimo = 0;

    cout << "Numero de primos que quieres que sume: ";
    cin >> n;

    while (n > 0)
    {
        cntPrimo = 0;
        div = 1;
       /* for (int div = 1; numPrimo >= div ;div++ )
        {
            if (numPrimo%div == 0)
            {
                cntPrimo++;
            }
        }
        */
        while (numPrimo >= div)
        {
            if (numPrimo%div == 0)
            {
                cntPrimo++;
            }
            div++;
        }
        if (cntPrimo == 2)
        {
            suma += numPrimo;
            n--;
        }
        numPrimo++;
    }


    cout <<"Resultado: "<< suma << endl;
return 0;

}
