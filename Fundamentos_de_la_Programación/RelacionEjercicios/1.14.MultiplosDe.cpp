#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int num;
    
    cout << "Introduce el numero para ver si es multiplo de 3,4 o 5: " << endl;
    cin >> num;

    if (num%3==0)
    {
        cout << num << " es multiplo de 3"<< endl;
    }
        else
            cout << num << " no es multiplo de 3" << endl;

    if (num%4==0)
    {
        cout << num << " es multiplo de 4"<< endl;
    }
     else
            cout << num << " no es multiplo de 4" << endl;
    if (num%5==0)
    {
        cout << num << " es multiplo de 5"<< endl;
    } 
     else
            cout << num << " no es multiplo de 5" << endl;
    
    
    
 
return 0;
 
}