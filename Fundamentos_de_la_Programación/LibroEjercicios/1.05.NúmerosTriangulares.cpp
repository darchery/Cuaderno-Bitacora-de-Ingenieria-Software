#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int n,z=0,i=0,nt;
    cout << "Enter a number: "<<endl;
    cin >>n;
    while (n>=z)
    {
        i++;
        z= ((i*i+i)/2);
    }
    nt = ((n*n+n)/2);
    if (nt==z)
    {
        cout << "Es un numero triangular"<<endl;
    }
    else
        cout << "No lo es"<<endl;
        
    
    return 0;
 
}