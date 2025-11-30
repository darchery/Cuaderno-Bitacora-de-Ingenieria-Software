#include <iostream>
using namespace std;

void leerPrimo(int& n)
{
    do
    {
        cout << "Introduzca un numero(>1): ";
        cin >> n;
    } while (n <= 1);
}

bool esPrimoRec (int num, int divisor)
{
    bool primo = true;

    if ((num == 2 || divisor == num) && primo == true)      /// CASO BASE CUANDO N ==2, O EL DIVISOR SEA IGUAL A N
    {                                                       /// SIEMPRE Y CUANDO EL NUMERO SIGA SIENDO PRIMO
        primo = true;
    }
    else if (num % divisor == 0)                            /// SI ALGUN NUM DIVIDE ENTRE DIVISOR EL IF PARA Y PONE EN FALSE EL BOOL
    {
        primo = false;
    }
    else                                                    /// SIGUE ANALIZANDO EL NUMERO
    {
        primo = esPrimoRec(num,divisor+1);

    }
    return primo;

    /*
    bool res;

    if (div > sqrt(n)) {
        s = true;
    } else if (n % div == 0) {
        res = false;
    } else {
        res = esPrimoRec(n,div+1);
    }
return res;
    */
}

int main() {
    int n;

    leerPrimo(n);
    if (esPrimoRec(n,2))
    {
        cout << n << " es primo" << endl;
    }
    else
    {
        cout << n << " NO es primo" << endl;
    }
    return 0;
}
