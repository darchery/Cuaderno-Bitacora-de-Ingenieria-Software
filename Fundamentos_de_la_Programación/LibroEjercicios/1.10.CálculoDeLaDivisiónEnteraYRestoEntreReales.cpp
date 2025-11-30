#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int a,b,n;
    cin >> a >> b;
    n=a/b;
    if (((b*n) <= a) and (a < (b*n+b)))
    {
        cout<< "Yes"<<endl;
    }
    else
        cout << "No"<<endl;

    cout << n << endl;

    if (a%b==(a-b*n))
    {
        cout<< "Yes"<<endl;
    }
    else
        cout << "No"<<endl;    
    
    cout << a%b << endl;
return 0;
 
}