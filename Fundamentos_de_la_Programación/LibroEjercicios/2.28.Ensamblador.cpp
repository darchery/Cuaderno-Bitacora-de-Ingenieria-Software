#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    char operador;
    int num;
    int res=0;
    int resDivMul=1;

    cout << "Introduzca el operador y los valores: " << endl;
    cin >> num >> operador;

    while (operador != '.')
    {
        cin >> num;

        if(operador =='+')
        {
            res += num;
        }
        else if (operador == '-')
        {
            res = res + num;
        }
        else if (operador == '*')
        {
            resDivMul *= num;
            res = resDivMul;
        }
        else if (operador == '/')
        {
            resDivMul /= num;
            res = resDivMul;
        }
    }

    cout << "Resultado: " << res << endl;
return 0;

}


