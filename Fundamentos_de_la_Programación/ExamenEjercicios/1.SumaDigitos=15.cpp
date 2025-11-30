#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void analizarSecuencia(int num);
bool sumaDigitos(int num);

int main(){
    int n;

    do
    {
        cout << "Introduzca una secuencia acabada en -1: ";
        cin >> n;

    } while (n < -1 && n == 0);

    analizarSecuencia(n);

return 0;

}
void analizarSecuencia(int num)
{
    cout << "Los numero capicuas de la secuencia son: ";
    while (num != -1)
    {
        if (sumaDigitos(num))
        {
            cout << num << " ";
        }
        cin >> num;
    }
}
bool sumaDigitos(int num)
{
    int suma = 0;
    int numDig = 0;
    int fakeN = num;

        while (fakeN != 0) // cu
        {
            fakeN /=10;
            numDig++;
        }

        int digito;
        fakeN = num;
        for (int i = 0;i < numDig ;i++ )
        {
            digito = fakeN % 10;
            suma += digito;
            fakeN /= 10;
        }

        if (suma == 15)
        {
            return true;
        }

    return false;

}

