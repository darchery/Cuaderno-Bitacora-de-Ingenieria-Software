#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){

    int num;
    int den;
    bool encontrado=false;
    

    cout << "Introduce la fraccion, primero el numerador y segundo el numerardor(separado por espacios): ";
    cin >> num >> den;

    int denIni= den;
    int numIni= num;
    int min=num;

   if (num > 0 && den > 0 && num!=den)
   {
        if ( num < den)
        {
            int aux = num;
            num = den;
            den = aux;
        }
        while (encontrado == false && min >= 1)
        {
            cout << "min: " << min << " num: " << num << " den: " << den << endl; 

            if (min%den==0 && min%num==0)
            {
                encontrado=true;
            }
            min--;
                 
        }

   }
   else
   {
    cout << "ERROR" << endl;
   }
   
    cout << "La fraccion " << numIni << " / " << denIni << " simplificada queda como " << num/min << " / " << den/min << endl;
    
 
return 0;
 
}