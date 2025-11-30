#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    /* 
    int n;
    cout << "Introduce un numero para verificar que esta en la secuencia: " << endl;
    cin >> n;
    int secuencia[20];
    int i=0;
    bool encontrado=false;

    if (n==0)
    {
        cout << "Introduce un numero diferente de 0..." << endl;
    }
    else{

        //INTRODUCIMOS SECUENCIA
        cout << "Introdue la secuencia terminada en 0: " << endl;
        cin >> secuencia[i];

        while (secuencia[i]!=0)
        {
            i++;
            cin >> secuencia[i];
        }
        //ANALIZAMOS LOS DATOS
        for (int i = 0; (i < 20) && (encontrado=false); i++)
        {
            if (secuencia[i]==n)
            {
                encontrado=true;
            }
        }
        //DAMOS LA CONCLUSION
        if (encontrado) 
        {
            cout << n << " esta en la secuencia" << endl;
        }
        else 
        {
            cout << n << " no esta en la secuencia" << endl;
        }
        
        
    }
    */

    
    int numBuscar, sec;
    cout << "Introduce un numero para verificar que esta en la secuencia: " << endl;
    cin >> numBuscar;
    bool encontrado=false;

    if (numBuscar==0)
    {
        cout << "Introduce un numero diferente de 0..." << endl;
    }
    else{

        //INTRODUCIMOS SECUENCIA
        cout << "Introdue la secuencia terminada en 0: " << endl;
        cin >> sec;

        while (sec!=0 && !encontrado)
        {
            if(sec==numBuscar)
            {
                encontrado=true;
            }
            else{
                cin >> sec;
            }
        }
        //DAMOS LA CONCLUSION
        if (encontrado) 
        {
            cout << numBuscar << " esta en la secuencia" << endl;
        }
        else 
        {
            cout << numBuscar << " no esta en la secuencia" << endl;
        }
        
        
    }
    
    
    
return 0;
 
}