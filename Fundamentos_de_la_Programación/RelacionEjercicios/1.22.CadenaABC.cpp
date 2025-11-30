#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){

    char cadena[20];
    bool encontrado= false;
    
    cout << "Introduce la cadena para revisar si abc pertenece a esta: "  << endl;
    cin.getline(cadena,20,'.');

    for (int i = 0; i < 20; i++)
    {
        if (cadena[i]=='a' && cadena[i+1]=='b' && cadena[i+2]=='c')
        {
                encontrado = true;
        }
    }

    if (encontrado)
    {
        cout << "abc HA sido econtrado en la cadena" << endl;
    }
    else{
        cout << "abc NO HA sido encotrado en la cadena" << endl;
    }
    
return 0;
 
}



    
   
    