#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool esDiabolico(int num);

int main(){
    int n;

    do
    {
        cout << "Introduzca un numero (>=): ";
        cin >> n;

    } while (n <= 0);

    if (esDiabolico(n))
    {
        cout << n << " ES un numero diabolico" << endl;
    }
    else
    {
        cout << n << " NO un numero diabolico" << endl;
    }
return 0;

}

bool esDiabolico(int num)
{
    bool tres6 = false;
    int dig;
    int nextDig = num;

    while (num != 0 && tres6 == false )
    {
        dig = num % 10;                     // COGE EL ULTIMO DIGITO DEL NUMERO
        if (dig == 6)                       // SI ESTE ES 6
        {
            nextDig /= 10;                  // CORTA EL NUMERO POR EL ULTIMO DIGITO
            dig = nextDig % 10;             // Y DEPUES COGE EL NUEVO ULTIMO NUMERO
            if (dig == 6)                   // SI ESTE ES 6 LLEVAMOS 2 CONSECUTIVOS, VEAMOS SI EL TERCERO
            {
                nextDig /= 10;              // CORTAMOS NUEVAMENTE EL NUMERO POR EL ULTIMO DIGITO
                dig = nextDig % 10;         // Y VOLVEMOS A COGER EL SIGUIENTE DIGITO
                if (dig == 6)               // Y SI ES ESTE 6 TENEMOS TRES 6 CONSECUTIVOS
                {                           // PONEMOS EL BOOL EN TRUE Y RETURNAMOS TRUE
                    tres6 = true;
                    return true;
                }
            }
        }
        nextDig = num / 10;                 // SI NO HAY NINGUN 6 O HA HABIDO 1 O 2 Y NO HA LLEGADO AL TERCERO SE AVANZA A LA SIGUIENTE CIFRA
        num /= 10;                          // EJ: 316166, AVANZARIAN LOS IFS HASTA 66 CUANDO ENCUENTRE EL 1 SALE DEL BUCLE Y CONTINUA CON 31616
    }
    return false;
}
