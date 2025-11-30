#include <iostream>
#include <array>
#include <math.h>

using namespace std;

 
int main(){
    char c;
    cout << "Intoduce la letra para ver si es una letra: " << endl;
    cin >> c;

    if ( (c >=65 && c <=90) or (c >=97 && c <=122) ) // (c >='A' && c <='Z') or (c >='a' && c <='z') )
    {
        cout << c << " es una letra" << endl;
    }
    else
        cout << c << " no es una letra" << endl;
    
    
return 0;
 
}