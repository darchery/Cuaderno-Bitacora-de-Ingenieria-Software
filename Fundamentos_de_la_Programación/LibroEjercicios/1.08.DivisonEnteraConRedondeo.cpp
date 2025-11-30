#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    float a, b;
    float div;

    cout << "Introduce 2 numeros para realizar la division: "<<endl;
    cin >> a >> b;
    div= a/b;
    cout << div<<endl;
    cout << div-int(div)<<endl;

    if ((div-int(div)) < 0.5 )
    {
        cout << int(div)<< endl; 
    }
    else
        cout << round(div);

return 0;
 
}