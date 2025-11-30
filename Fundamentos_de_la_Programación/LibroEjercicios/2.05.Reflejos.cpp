#include <iostream>
#include <array>
#include <math.h>
#include <unistd.h>


using namespace std;



int main(){

    cout << "Pusla una tecla lo más rápido que puedas!" << endl; 
    while (cin.get()!='q')
    {
        cout << "*"<< flush;
    }
    
return 0;
 
}