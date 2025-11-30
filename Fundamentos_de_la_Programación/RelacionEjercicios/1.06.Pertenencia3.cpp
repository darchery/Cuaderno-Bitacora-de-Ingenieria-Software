#include <iostream>
#include <array>
#include <math.h>

using namespace std;
/*
(x>=3 && x<=4) || (x>=6 && x<=9)
*/
 
int main(){
    int Nx=5, Ny=4;
    int x[Nx]={3,4,6,8,9};
    int y[Ny]={6,7,8,3};

    int num;
    int counterx=0, countery=0;
    cout << "Introduce un numero a ver si esta en la lista: " << endl;
    cin >> num;
    for (int i = 0; i < Nx  ; i++)
    {
        if (num==x[i])
        {
            counterx++;
        }
    }
    for (int j = 0; j < Ny; j++)
    {
        if (num==y[j])
        {
            countery++;
        }
    }
    
    if ((counterx == countery) && (counterx!=0) && (countery!=0))
    {
        cout << num << " pertenece a el conjunto x e y" << endl;
    }
    else
        cout << num << " no pertenece a el conjunto x e y" << endl;
     
return 0;
 
}