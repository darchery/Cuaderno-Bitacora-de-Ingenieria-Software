#include <iostream>
#include <array>
#include <math.h>
#include <string.h>

using namespace std;

int main(){

    int dec, decCout, longString, cntBinInver=0;
    char bit;
    string bin="";
    string binInvertido="";

    cout << "Introduce el numero decimal: "  << endl;
    cin >> dec;

    decCout = dec;

    if (dec==0)
    {
        bin = '0';
    }
    else
    {
        //CALCULA EL NUMERO BINARIO AL REVES
        while (dec > 0)
        {
            bit= dec%2 +'0'; // PONE EL 0 O EL 1 EN CHAR Y LO ALMACENA EN UN STRING
            bin += bit;
            dec/=2; // PASA AL SIGUIENTE NUMERO
        }
        longString = bin.length();

        // LO INVIERTE Y LO IMPRIME

        cout << "El numero " << decCout << " en binario es ";
        for (int i = longString; i >= 0;i--)
        {
            binInvertido[cntBinInver] = char(bin[i]);
            cout << binInvertido[cntBinInver];
            cntBinInver++;
        }
    }

return 0;

}
