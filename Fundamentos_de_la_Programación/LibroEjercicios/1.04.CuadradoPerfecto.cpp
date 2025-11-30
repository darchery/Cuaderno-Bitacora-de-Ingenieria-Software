#include <iostream>
#include <math.h>
#include <array>

using namespace std;
 
int main(){
    int n,m;
    cout << "Enter a number to check if its a perfect square: "<<endl;
    cin >> m;
    n=sqrt(m);
    if (m==n*n)
    {
        cout << "It's  a perfect square"<<endl;
    }
    else
        cout << "It is not"<<endl;

return 0;
 
}
