#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){

    int x,y;

    cout << "Introduce los numeros para ver si son individualmente menores que 10: "  << endl;
    cin >> x >> y;

    if ( x < 10 && y < 10 )
    {
        cout << x << " y " << y << " son mas pequenos que 10" << endl;
    }
    else if (x > 10 && y < 10 )
    {
        cout << "Solo "<< y << "  es mas pequeno que 10" << endl;
    }
    else if (x < 10 && y >10)
    {
        cout << "Solo "<< x << "  es mas pequeno que 10" << endl;
    }
    else if (x > 10 && y > 10 )
    {
        cout << x << " y " << y << " no son mas pequenos que 10" << endl;
    }
     
return 0;
 
}