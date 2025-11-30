#include <iostream>
#include <array>
#include <math.h>
/*
*Cuando digo tachado digo poner en true la casilla*
Haremos lo siquiente:
1. Cogeremos y pondremos en false todas las casillas del array.
2. Tachamos el 1.
3. Tachamos los numeros pares, i % 2 == 0;
4. Tachamos los multiplos de 3, i % 3 == 0;
5. Tachamos los multiplos de estos numeros hasta que i >= sqrt(MAX)
*/
using namespace std;

const int MAX = 100;
typedef array<bool, MAX+1> TPrimos;

struct TLista {
    TPrimos primos;
    int N;
};

void leer(TLista& lista)
{
    do
    {
        cout << "Introduzca el limite para calcular los primos (> 0 y <= " << MAX << "): ";
        cin >> lista.N;
    } while (lista.N < 0 || lista.N > 100);
}

void inicializar(TLista& lista)
{
    lista.primos[1] = false;    // TACHAMOS EL 1
    for (int i = 2;i <= MAX ;i++ ) // AQUÍ PREPARA Y ""ESCRIBE"" LOS NUMERO DEL 1 AL 100
    {
        lista.primos[i] = true;
    }
}

void borrarMultiplos(TLista& lista, int num)
{
    for (int i =  2 * num;i <= lista.N ;i += num )  // SU FUNCIONAMINETO ES DE MANERA MULTIPLICA CADA NUMERO POR 2 Y LUEGO LO TACHA
    {                                               // SI ES 2 -> 2*2 = 4 TACHADO, LUEGO LE SUMA 2(num) -> 2+4 = 6 TACHADO,
        lista.primos[i] = false;                    // CUANDO ACABA CON 2 VUELVE A encontrarPrimos Y ASI CON EL 3, 5, 6, 7 HASTA LLEGAR N,
    }
}

void encontrarPrimos(TLista& lista)
{
    for (int i = 2;i <= sqrt(lista.N) ;i++ )    // AQUI REVISA LOS NUMEROS DESDE 2 HASTA SQRT(N)
    {
        borrarMultiplos(lista, i);              // Y AQUÍ BORRA TODOS SUS MULTIPLOS
    }
}

void escribirPrimos(TLista& lista)
{
    cout << "Los numeros primos menores o iguales que " << lista.N  << " son: ";
    for (int i = 1;i <= lista.N ;i++ )
    {
        if (lista.primos[i])
        {
            cout << i << " ";
        }
    }
}

void erastotenes(TLista& lista)
{
    inicializar(lista);
    encontrarPrimos(lista);
    escribirPrimos(lista);
}

int main(){
    TLista lista1;
    lista1.primos ={{}};

    leer(lista1);
    erastotenes(lista1);
return 0;

}


/*
bool primo(int num)
{
    bool esPrimo = true;

    for (int i = 2;i < num && esPrimo;i++ )
    {
        if (num % i == 0)
        {
            esPrimo = false;
        }
    }
    return esPrimo;
}

void erastotenes(TLista& lista)
{
    for (int i = 1;i <= lista.N ;i++ )
    {
        if (i == 1)
        {
            lista.primos[i] = true;
        }
        else if (i != 2)
        {
            if (!primo(i))
            {
                lista.primos[i] = true;
            }
        }
    }
}

*/
