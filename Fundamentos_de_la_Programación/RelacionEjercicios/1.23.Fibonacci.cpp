#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){

    int numFib; 
    int resfib=0;
    int Fib1=0;
    int Fib2=1;

    cout << "Introduce el n de la secuencia fibonacci que quieres obtener: " << endl;
    cin >> numFib;

    if (numFib < 0)
    {
        cout << "Introduce un numero mayor o igual que cero..." << endl;
    }
    else if (numFib==0)
    {
        cout << "Introduce un numero diferente a cero..." << endl;
    }
    else if (numFib==1)
    {
        resfib=Fib1;
        cout << "El numero " << numFib << " de la sucesion de Fibonacci es "<< resfib << endl;
    }
    else if (numFib==2)
    {   
        resfib=Fib2;
        cout << "El numero " << numFib << " de la sucesion de Fibonacci es "<< resfib << endl;
    }
    else{
        
        for (int i = 2; i < numFib; i++)
        { 
            resfib = Fib1 + Fib2;
            Fib1 = Fib2;
            Fib2 = resfib;
        }

        cout << "El numero " << numFib << " de la sucesion de Fibonacci es "<< resfib << endl;
    }
 
return 0;
 
}