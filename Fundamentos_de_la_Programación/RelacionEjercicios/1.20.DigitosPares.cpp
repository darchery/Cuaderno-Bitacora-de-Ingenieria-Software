#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int numero;
    int digPar=0;
    cout << "Introduce un numero para ver cuantos digitos pares tiene: " << endl;
    cin >> numero;

    if (numero  < 0)
    { 
        cout << "Introduce un numero valido" << endl;
    }
    else{

    while (numero > 0) 
    {
        if ((numero%10)%2 == 0) // ultimo digito
        {
            digPar++;
        }
        numero/=10;
    }
    cout << "Hay " << digPar << " digitos pares" << endl;

    }

return 0;
 
}