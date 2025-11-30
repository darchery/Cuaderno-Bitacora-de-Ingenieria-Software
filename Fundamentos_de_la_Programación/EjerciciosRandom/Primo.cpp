#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int divisors=1;
    int primo;
    int count = 0;

    cin >> primo;

    while (divisors < primo)
    {
        if (primo%divisors==0 )
        {
           count++; 
        }
        divisors++;
    }

    if (count <= 1)
    {
        cout << primo << " es primo" << endl;
    }
    else
        cout << primo << " no es primo" << endl;
    
    
return 0;
 
}