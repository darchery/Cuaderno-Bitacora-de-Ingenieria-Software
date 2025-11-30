#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int n,a,mono;
    cout << "Introduce el valor del coeficiente y del polinomio: " << endl;
    cin>> a >> n;
    while (n>=0)
    {
        mono = n;
        n=n-1;
        cout <<  a  << 'x'<< '^' <<  mono << " + " ;
    }
    
return 0;
 
}