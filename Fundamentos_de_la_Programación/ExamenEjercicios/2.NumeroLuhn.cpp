#include <iostream>
#include <array>
#include <math.h>

// 49927398716 es Luhn num

using namespace std;

bool esNumLuhn(long long num);
long long invertirNum(long long num);

int main(){
    long long num;

    cout << "Introduzca un numero para ver si es un numero de Luhn: ";
    cin >> num;

    if (esNumLuhn(num))
    {
        cout << num << " ES un numero de Luhn" << endl;
    }
    else
    {
        cout << num << " NO un numero de Luhn" << endl;
    }

return 0;

}
// ES NUMERO DE LUHN SI:
// 0. PRIMERO INVERTIMOS EL NUMERO
// 1. MULTIPLICA POR 2 LOS DIGITOS DE LAS POSICIONES PARES EMPEZANDO POR LAS CIFRAS MÁS PEQUEÑAS Y LAS SUMAS(SIENDO MULTIPLICADAS POR 2 PREVIAMENTE)
// 2.1 HACER QUE SI EL NUMERO ES TIENE 2 CIFRAS HAY QUE SUMARSELAS
// 2. SUMA LOS NUMERO DE LAS POSICIONES IMPARES, EMPEZANDO POR LAS CIFRAS MÁS PEQUEÑAS
// 3. LOS SUMAS
// 4. LE HACES EL MODULO A LA SUMA ENTRE 10 Y SI EL RESULTADO ES 0 EL NUMERO ES CORRETO


bool esNumLuhn(long long num)
{
    int sumPosPar = 0;
    int sumPosImp = 0;
    int pos = 1;
    long long numInver = invertirNum(num);
    int mayorQueDiez;

    while (numInver != 0)
    {
        if (pos % 2 == 0)
        {
            if (((numInver % 10)*2) > 10 )
            {
                mayorQueDiez = (numInver % 10)*2;       // ESTE BLOQUE LO QUE HACE ES ASIGNAR A LA NUEVA VARIABLE EL NUMERO MAYOR DE 10 (2 CIFRAS)
                while (mayorQueDiez != 0)
                {
                    sumPosPar += mayorQueDiez % 10;     // AQUI COGE UN DIGITO Y LO SUMA AL COUNTER
                    mayorQueDiez /= 10;                 // LO REDUCE Y REPITE EL BUCLE SOLO 1 UNA VEZ ( SE PODRIA HACER CON UN FOR SIEMPRE VAN A SER 2)
                }
            }
            else
            {
                sumPosPar += (numInver % 10)*2;         // Y AQUÍ SI ES MENOR DE 10 LO SUMA NORMAL
            }
        }

        else if (pos % 2 != 0)                          // AQUI SI LA POS ES IMPAR SE SUMAN SIMPLEMENTE LOS DIGITOS (ES MEJOR HACERLO CON UN ELSE)
        {

            sumPosImp += numInver % 10;
        }
        pos++;
        numInver /= 10;
    }

    if ((sumPosImp + sumPosPar) % 10 == 0)              // POR ULTIMO LOS SUMA Y HACE EL MODULO Y DESPUES SI ES = 0 DEVUELVE TRUE Y ES UN LUHN NUMBER
    {
        return true;
    }
    else
    {
        return false;
    }

}

long long invertirNum(long long num)
{
    long long numInver = 0;

    while (num != 0)
    {
        numInver *= 10;         // CREA EL NUEVO NUMERO INVERTIDO Y AUMENTA EN CADA CICLO POR 10, ES DECIR SI HAY 3 CICLOS SE CREA UN NUMERO DE 3 CIFRAS
        numInver += num % 10;   // COGE EL ULTIMO DIGITO DE DEL NUMERO Y LO SUMA PONIENDOLO AL PRINCIPIO SIEMPRE POR LA MECANICA DE EN CADA CICLO MULTIPLICAR POR 10
        num /= 10;              // Y POR ULTIMO CORTA EL DIGITO USADO
    }
    return numInver;
}
