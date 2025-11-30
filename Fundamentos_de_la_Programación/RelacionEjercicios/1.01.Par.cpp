#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int num;
    
    cout << "Introduce el numero para ver si es par: " << endl;
    cin >> num;

    if (num%2==0)
    {
        cout << num << " es par" << endl;
    }
    else   
        cout << num << " no es par" << endl;
    
return 0;
 
}