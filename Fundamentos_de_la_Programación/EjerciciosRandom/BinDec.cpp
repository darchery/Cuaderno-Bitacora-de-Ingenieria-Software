#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int numBin;
    int numBinCout;
    int elevado=0;
    int numDec=0;

    cout << "Introduzca el numero binario: ";
    cin >> numBin;

    numBinCout = numBin;

    if (numBin==0)
    {
        cout <<" 0 en decimal es 0" << endl;
    }
    else
    {
        while(numBin > 0)
        {
            numDec += numBin%10*(pow(2,elevado));
            numBin /= 10;
            elevado++;
        }
        cout << "El numero " << numBinCout << " en decimal es " << numDec << endl;
    }
return 0;

}
