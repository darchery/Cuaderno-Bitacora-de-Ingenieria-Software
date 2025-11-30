#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool numeroNarcisista(int& num);

int main(){
    int num;

    cout << "Introduzca un numero para ver si este es narcisista: ";
    cin >> num;

    cout << numeroNarcisista(num) << endl;

    if (numeroNarcisista(num))
    {
        cout << "El numero " << num << " SI es un numero narcisista" << endl;
    }
    else
    {
        cout << "El numero " << num << " NO es un numero narcisista" << endl;
    }
return 0;

}

bool numeroNarcisista(int& num)
{
    int fakeNum = num;
    int numDigitos;
    int res = 0;

    /*while (fakeNum > 10)
    {
        fakeNum /= 10;
        numDigitos++;
    }

    */
    numDigitos = 0;
    while (fakeNum != 0)
    {
        fakeNum /= 10;
        numDigitos++;
    }

    cout << numDigitos << endl;

    int digito;
    fakeNum = num;
    for (int i = 0;i < numDigitos ;i++ )
    {
        digito = fakeNum % 10;
        cout << "Res: " << res << " + " << pow(digito,numDigitos) << endl;
        res += pow(digito,numDigitos);
        cout << "Resultado despues: " << res << endl;
        fakeNum /= 10;
        cout << "Digito: " << digito << endl;
     }


    if (res == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}
