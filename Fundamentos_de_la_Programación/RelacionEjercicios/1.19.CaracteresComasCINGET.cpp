#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int caracteres=0;
    int comas=0;
    char frase;

    cout <<"Introduce un texto terminado en punto: ";
    cin.get(frase);

    while (frase!='.')
    {
        if (frase==',')
        {
            comas++;
        }
        caracteres++;
        cin.get(frase);
    }
    

    cout << "Numero de caracteres: " << caracteres << endl; 
    cout << "Numero de comas: " << comas  << endl;
    
    
return 0;
 
}