#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int nk;
    char arma;
    while (nk!=0)
    {
        cout << "Introduce los kmc que quieres destruir y el arma que quieres usar para ver su precio respectivamente: " << endl;
        cin >> nk >> arma;
        if (arma=='n')
        {
            cout << "Precio arma nuclear para " << nk << " kilometros cuadrados es: " << nk*600 << " euros" << endl;
        }
        else if (arma=='c')
        {
            cout << "Precio arma nuclear para " << nk << " kilometros cuadrados es: " << nk*1800 << " euros" << endl;
        }
        else if (arma=='q')
        {
            cout << "Precio arma nuclear para " << nk << " kilometros cuadrados es: " << nk*0.6 << " euros" << endl;
        }
    }
return 0;
 
}