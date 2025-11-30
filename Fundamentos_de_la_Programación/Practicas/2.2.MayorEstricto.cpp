#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int n1,n2,n3;
    

    cout << "Introduce 3 numeros para ver si hay algun mayor estricto" << endl;
    cin >> n1 >> n2 >> n3;

    if (n1 > n2 && n1 >n3 )
    {
        cout <<"Mayor estricto: " << n1 << endl;
    }
    else if (n2 > n1 && n2 >n3)
    {
        cout <<"Mayor estricto: " << n2 << endl;
    }
     else if (n3 > n1 && n3 >n2)
    {
        cout <<"Mayor estricto: " << n3 << endl;
    }
    else
        cout << "No hay mayor estricto..." << endl;
    
 
return 0;
 
}