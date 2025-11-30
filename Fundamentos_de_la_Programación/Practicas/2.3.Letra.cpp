#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    char c;

    cout << "Introduzca una letra: " << endl;
    cin >> c;

    if ((c >='A' && c<='Z') || (c >='a' && c<='z'))
    {
        cout << c <<" es una letra" << endl;
    }
    else if (c=='.')
    {
        cout << c << " es un punto" << endl;
    }
    else
        cout << "Error" << endl;
    
    
 
return 0;
 
}