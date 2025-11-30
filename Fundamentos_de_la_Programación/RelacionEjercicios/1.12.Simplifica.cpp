#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    
    int edad;
    cin >> edad;

    if (edad >= 65) 
    {
    cout << "Jubilado";
    } 
    else if (edad < 18) 
    {
    cout << "Menor de edad";
    }
    else if ((edad >= 18) && (edad < 65)) 
    {
    cout << "Activo";
    }



return 0;
 
}