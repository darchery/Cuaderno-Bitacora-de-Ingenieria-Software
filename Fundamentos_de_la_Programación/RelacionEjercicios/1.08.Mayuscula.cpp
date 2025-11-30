#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    char c;
    cout << "Intoduce la letra para ver si es mayuscula: " << endl;
    cin >> c;

    if ( c >='A' && c <='Z')  // OR (c >=65 && c <=90) || (c=='Ñ')
    {
        cout << "Es una mayuscula" << endl;
    }
    else
        cout << "No es una mayuscula" << endl;

return 0;
 
}