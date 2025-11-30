#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int num;

    cout <<"Introduce el numero para saber si tiene 3 dígitos: "  << endl;
    cin >> num;

    if ( (num/100 > 0 && num/100 < 10)  ||  (num >= -999 && num <0))
    {
        cout << num <<  " tienes 3 digitos" << endl;
    }
    else 
        cout << num << " no tiene 3 digitos" << endl;
return 0;
 
}