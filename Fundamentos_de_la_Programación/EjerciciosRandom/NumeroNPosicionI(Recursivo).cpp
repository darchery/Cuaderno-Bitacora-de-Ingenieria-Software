#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int digito(int N, int i)
{

    int res;
    if (i==1)
    {
        res = N % 10;               // SI POS = 1 EL DIGITO ES EL PRIMERO
    }
    else
    {
        res = digito(N/=10,i-1);    // AQUI VA A IR RECURSIVAMENTE REDUCIENDO EL NUMERO EN DIFERENTES BUCLES RECURSIVOS
    }                               // EJ: 1234 3, 1º else res = dig(123,3-1=2), 2º else res = dig(12,2-1=1), 3º if res = 12 % 10 = 2 porque i = 1
    return res;
}

int main(){
    int N, i;

    do
    {
        cout << "Introduca un numero y una posicion de este: ";
        cin >> N >> i;
    } while (N < i && N <= 0 && i <= 0);

    cout << "La posicion " << i << " del numero " << N << " es " << digito(N,i) << endl;

return 0;

}
