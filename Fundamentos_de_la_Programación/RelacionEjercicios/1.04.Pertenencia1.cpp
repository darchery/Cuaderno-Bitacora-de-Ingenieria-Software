#include <iostream>
#include <array>
#include <math.h>

using namespace std;

/*
X>=3 && X<=7
*/
 
int main(){

    int N=5;
    int x[N]={3,4,5,6,7};
    int num;
    int counter=0;

    cout << "Introduce un numero a ver si está en la lista: " << endl;
    cin >> num;

    for (int i = 0; i < N  ; i++)
    {
        if (num==x[i])
        {
            counter++;
        }
    }
    if (counter >= 1)
    {
        cout << num << " pertenece a el conjunto x" << endl;
    }
    else
        cout << num << " no pertenece a el conjunto x" << endl;
    
    
return 0;
 
}