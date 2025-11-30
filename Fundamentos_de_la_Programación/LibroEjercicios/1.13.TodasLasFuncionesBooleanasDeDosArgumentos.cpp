#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int a,b;
    cout <<"Introduce 0(false) o 1(true) para ver la reaccion de la puerta AND: "<<endl;
    cin >>a >> b;
    
    if (a==b and a+b==2)
    {
        cout << "True" <<endl;
    }
    else
    {
        cout << "False" << endl;
    }
    
    
 
return 0;
 
}