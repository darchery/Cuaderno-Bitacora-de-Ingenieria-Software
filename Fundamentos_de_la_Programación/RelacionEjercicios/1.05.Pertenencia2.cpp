#include <iostream>
#include <array>
#include <math.h>

using namespace std;

/*
(x>=1 && x<=3)||(x>=7 && x<=9)
*/
 
int main(){
    int N=6;
    int x[N]={1,2,3,7,8,9};
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