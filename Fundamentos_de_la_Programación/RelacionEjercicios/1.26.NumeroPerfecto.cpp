#include <iostream>
#include <array>
#include <math.h>
#include <ctime>

using namespace std;
 
int main(){
     int n,divisor=1;
     int suma=0;

     cout << "Introduce un numero para ver si es un numero perfecto: "<< endl;
     cin >> n ;

     while (n > divisor)
     {
        if (n%divisor==0)
        {
            suma+=divisor;
        }
        divisor++;
     }
     
     if (n==suma)
     {
        cout << "Es un numero perfecto" << endl;
     }
     else
     {
        cout << "No es un numero perfecto" << endl;
     }
     
return 0;
 
}