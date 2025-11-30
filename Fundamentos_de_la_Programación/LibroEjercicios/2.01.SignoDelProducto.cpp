#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int n,m;
    cin >> n  >> m;
    if ((n<0 and m>0) or (n>0 and m<0))
    {
        cout << "Negative" << endl;
    }
    else
    {
        cout << "Positive" << endl;
    }
return 0;
 
}