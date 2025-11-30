#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int num;
    int div = 1;
    int numPrimo = 1;
    int cntPrimo = 0;

    cout << "Introduzca el numero de primo que quieres que te imprima: ";
    cin >> num;

    while (num > 0)                 //SIMEPRE Y CUANDO NUM > 0
    {
        cntPrimo = 0;               //REINICIA EL CNTPRIMO, DIV Y NUMPRIMO PARA EL SIGUIENTE NUMERO "PRIMO" (PUEDE SERLO O NO)
        div = 1;
        numPrimo++;

        while (numPrimo >= div )    // MIENTRAS EL NUMERO SEA MAYOR O IGUAL QUE EL DIVISOR VA A IR DIVIDIENDO ENTRE SI Y SI ES DIVISIBLE
        {
            if (numPrimo%div == 0)  // SE LE SUMA AL CONTADOR
            {
                cntPrimo++;
            }
            div++;
        }

        if (cntPrimo == 2)          // PARA QUE SEA PRIMO OBVIAMENTE TIENE QUE DIVIDIRSE 2 VECES, ENTRE 1  Y SI MISMO
        {
            num--;                  // SI LO ES LE RESTA UNO A NUM PARA HACER EL SIGUIENTE CICLO, SI NO FUERA PRIMO NO RESTARIA NADA A NUM
        }
    }                               // Y ESE CICLO NO SERVIRIA

    cout  << "Numero primo: " << numPrimo << endl;
return 0;

}
