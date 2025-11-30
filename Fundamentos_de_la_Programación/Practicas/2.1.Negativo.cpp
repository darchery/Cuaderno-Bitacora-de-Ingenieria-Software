#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){

    int num;
    cout << "Introduzca un numero entero:" << endl;
    cin >> num;

    if (num < 0)
    {
        cout << num << " es un numero negativo" << endl;
    }
    else if (num >=0 )
    {
        cout << num << " no es un numero negativo" << endl;
    }
    else
        cout <<"Introduce un numero valido... " << endl;
 
return 0;
 
}