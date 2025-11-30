#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int x,y;
    
    cout << "Introduce los 2 numeros para ver si son divisibles entre ellos: " << endl;
    cin >> x >> y;

    if (x%y==0)
    {
        cout << x << " es divisor de " << y << endl;
    }
    else if (y%x==0)
    {
        cout << y << " es divisor de " << x << endl;
    }
    else
        cout << "No son divisores ninguno del otro" << endl;
    
    
return 0;
 
}