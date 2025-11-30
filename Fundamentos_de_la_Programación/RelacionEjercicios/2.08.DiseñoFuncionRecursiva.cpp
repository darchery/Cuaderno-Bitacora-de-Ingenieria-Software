#include <iostream>
#include <array>
#include <math.h>

// Sea A(n) el número de productos realizados al ejecutar la función p cuando se llama con el
// argumento n. Diseña la función recursiva de A(n).

using namespace std;

int p(int x);
int A(int n);

int main(){
    int x;
    cin >> x;
    cout << p(x);
return 0;

}

int p(int x)
{
    int res;
    if (x < 3)
    {
        res = x;
    }
    else
    {
        res = p(x-1) * p(x-3);
    }
    return res;
}

int A(int n)
{
    int res;
    if (n < 3)
    {
        res = 0;
    }
    else
    {
        res = 1 + A(n-1) + A(n-3);          /// ESTÁ IMITANTO EL NUMERO DE OPERACIONES QUE HACE EN int p, ASI QUE CUANDO HACER UN PRODUCTO O MAS
    }                                       /// SE CALCULA EL NUMERO TOTAL, AL SER RECURSIVO ESTE SE COMPORTA DE DE LAS MISMA MANERA QUE int p,
    return res;                             /// PEERO NO HACE PRODUCTO SINO QUE SUMA EL NUMERO DE VECES
}
