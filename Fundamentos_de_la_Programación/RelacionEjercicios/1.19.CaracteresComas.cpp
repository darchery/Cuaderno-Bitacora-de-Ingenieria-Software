#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int caracteres=0;
    int comas=0;
    string frase ={"Este, aunque sencillo, es un ejemplo interesante."};

    for (int i = 0; i < frase.length(); i++)
    {
        if (frase[i]==',' )
        {
            comas++;
        }
        caracteres++;

        if (frase[i]=='.')
        {
            caracteres--;
        }
        
    }

    cout << "Numero de caracteres: " << caracteres << endl; 
    cout << "Numero de comas: " << comas  << endl;
    
    
return 0;
 
}