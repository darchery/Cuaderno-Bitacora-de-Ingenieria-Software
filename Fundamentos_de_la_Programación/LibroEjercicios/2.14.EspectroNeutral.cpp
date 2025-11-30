#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    float r,Bx,By;
    int x,y;
    cout << "Introduce el valor del radio: " << endl;
    cin >> r;
    cout << "E introduce las coordenadas: " << endl;
    cin >> x >> y ;
    
    if (r*r > x*x +y*y)
    {
        Bx = x+1;
        By = y;  
        cout << "La base B se conforma con B(" << Bx << "," << By << ")" << endl;
    }
    else if (r*r == x*x + y*y)
    {
        Bx = x+1;
        By = y-1;  
        cout << "La base B se conforma con B(" << Bx << "," << By << ")" << endl;
    }
    else if (r*r < x*x + y*y)
    {
        Bx = x;
        By = y-1;  
        cout << "La base B se conforma con B(" << Bx << "," << By << ")" << endl;
    }
    else
        cout << "Escribe el formato correto" << endl;
    
return 0;
 
}