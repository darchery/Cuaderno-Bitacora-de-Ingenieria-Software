#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){

   /* bool test;
    int N=1;
    test = true;
    for (int contador= 1;contador<=N;contador++) {
        test = !test;
    }
    cout << test; */
    // ES TRUE SI N ES IMPAR Y FALSE SI N ES PAR
    
    bool test;
    int N;
    test = N %2 ==0;
    
    for (int contador= 1;contador<=N;contador++) {
    test = !test;
    }
    cout  << test;

    //SERA TRUE SI N ES PAR Y SERA FALSE SI N ES IMPAR
return 0;
 
}
