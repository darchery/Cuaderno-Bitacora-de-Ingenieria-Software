#include <iostream>
#include <array>
#include <math.h>
#include <ctime>

using namespace std;
 
int main(){

    int numeroAdivinar = 0;
    int max,min,newMax,newMin;
    char operador;
    
    cout << "Introduce en que rango esta tu valor y tambien tu valor (que lo adivinare ;) )" << endl;
    cin >>  min >> max; 

    numeroAdivinar = min + rand() % (max+1-min);

    while (operador!='=')
    {
        cout <<"\n";

        cout << numeroAdivinar << endl;

        cout <<"Es mayor o menor, es tu numero?." << endl;


        cin >> operador; 

        cout <<"\n";

        if (operador == '>')
        {
            newMin= numeroAdivinar;
            srand((unsigned)time(0));
            numeroAdivinar=0;
            numeroAdivinar = newMin + rand() % (max+1-newMin);
        }

        if (operador == '<')
        {
            newMax= numeroAdivinar;
            srand((unsigned)time(0));
            numeroAdivinar=0;
            numeroAdivinar = min + rand() % (newMax+1-min);
        }

        srand((unsigned)time(0));
    }
    
    cout << "Por fin lo adivine!. Uff me costo mucho :/" << endl;

    
return 0;
 
}