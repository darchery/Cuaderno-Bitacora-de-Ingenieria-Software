#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void compararDesplazamientos(string cadena1, string cadena2, int despla, int& coinci)
{
    int j = despla;

    for (int i = 0;i < int(cadena2.size()) && j < int(cadena1.size());i++ )
    {
        if (cadena2[i] == cadena1[j])
        {
            coinci++;
        }
        j++;
    }
}

void escribirCadena(string cadena1, string cadena2, int desplzamiento)
{
    cout << cadena1 << endl;
    for (int i = 0;i < desplzamiento ;i++ )
    {
        cout << " ";
    }
    cout << cadena2 << endl;
}

int main(){
    string cadena1 = "acbaabch", cadena2 = "aabghc";
    int coincidencias;

    for (int i = 0;i < int(cadena1.size()) ;i++ )
    {
        coincidencias = 0;
        compararDesplazamientos(cadena1,cadena2,i,coincidencias);
        escribirCadena(cadena1,cadena2,i);
        cout << "Con " << i << " desplazamientos hay " << coincidencias << " coincidencias" << endl;
        cout << endl;
    }
return 0;

}

/*

acbaabch
aabghc

acbaabch
 aabghc

acbaabch
  aabghc

acbaabch
   aabghc

acbaabch
    aabghc

acbaabch
     aabghc

acbaabch
      aabghc

acbaabch
       aabghc
*/
