#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int a, b;

    cout << "Introduce el argumento y la base del logaritmo entre espacios: " << endl;
    cin >> a >> b;

    if ( a < 1 || b <= 1)
    {
        cout <<"Introduce unos valores correctos..." << endl;
    }
    else {
        cout <<"Logaritmo  en base " << b << " de " << a <<" es " << logb(a) <<endl;
    }
    
    // PARTE ENTERA DE UN REAL R SI N <= R < N+1
 
return 0;
 
}