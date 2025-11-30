#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int calcularRaizEntera(int& numero, int n);

int main(){
    int numero, n;

    cout << "Introduzca el numero: ";
    cin >> numero;
    cout <<"\n";
    cout << "Introduzca el valor n: ";
    cin >> n;
    cout <<"\n";
    cout << "La raiz n-esima de "<< numero <<" es: " << calcularRaizEntera(numero, n) <<endl;

return 0;

}

// OBJETIVO: 2*3 = 2^3 = pow(2,3) si  2 = base y 3 = tenemos pow(base,n) y si numero < pow(base,n), base++
int calcularRaizEntera(int& numero, int n)
{
    int base = 2;
    int resulado;

    while (numero > pow(base,n))
    {
        resulado = base;
        base++;
    }

    return resulado;
}
