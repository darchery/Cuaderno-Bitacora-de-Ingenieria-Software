#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const double pi=3.1416; 

int main(){
    
    int ang, mins, segs;
    float rads;
    /* EQUIVALENCIAS
        1. 180º = pi
        2. 1 min = 1º/60 == > 60 mins = 1º 
        3. 1 seg = 1/60 == > 60 segs = 1 minuto 
    */

    cout << "Introduce los grados, minutos y segundo: " << endl;
    cin >> ang >> mins >> segs;

    rads= (ang*pi)/180.0 + (((mins*1.0/60.0)*pi)/180.0) + ((((segs*1.0/60.0)/60.0)*pi)/180.0);
    // De grads a rads --- de mins a grads y de grads a rads ---- de segs a mis , de mins a grads y de grads a rads
    cout <<"Resultado sumado en radianes: " << rads  << endl;
return 0;
 
}