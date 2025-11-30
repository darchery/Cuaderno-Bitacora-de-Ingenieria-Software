/*
To know the last digit (base 10) of an integer number you have to take its modulus over 10: n % 10. To cut the last
digit, you have to divide the number by 10. Build a program that prints the digits of a integer number backwards,
for example, if you enter: 2021, it will print: 1202
*/

#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int n;
    int newN = 0;
    int cntDigits = 1;

    cout << "Introduzca un numero para darle la vuelta: ";
    cin >> n;

    int faken = n;
    while (faken >= 10)
    {d
        faken  /= 10;
        cntDigits++;
    }

    for (int i = 0; i < cntDigits ;i++ )
    {
        int digit = n % 10;                    // COGE EL DIGITO INDIVIDUALMENTE Y DESPUES
        newN = newN * 10 + digit;              // MULTIPLICA EL NUMERO ANTERIOR POR 10 PARA SUBIRLE DE GRADO SI ANTES HABIA UN 3 DESPUES HABRÁ UN 30
        n /= 10;                               // CORTA EL NUMERO POR ABAJO , PASA AL SIGUIENTE
    }                                          // SI EL INPUNT ES 123, COGERA EL 3 Y DESPUES HARÁ 0 + 3, LUEGO COGERA 2 Y HARA 3*10 + 2 = 32
                                               // Y POR ULTIMO COGERA EL 1 Y HARÁ 32*10 + 1 = 321
    cout << "Tu numero con los digitos invertidos es: " << newN << endl;
return 0;

}
// ANTIGUO ALGORITMO QUE NO FUNCIONA PARA 3 DIGITOS
/*
            newN += (n%10) * pow(10,cntDigitFake-1);
            n /= 10;
            cntDigitFake--;
*/
