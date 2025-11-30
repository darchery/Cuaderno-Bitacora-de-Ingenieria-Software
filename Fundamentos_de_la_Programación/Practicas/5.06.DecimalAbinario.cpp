#include <iostream>
using namespace std;

void leerN(int& n)
{
    do
    {
        cout << "Introduzca un numero(>=0): ";
        cin >> n;
    } while (n < 0);
}

void decimalAbinario (int n)
{
    if (n == 0)
    {

    }
    else
    {
        // cout << n%2; SI PUSIERA ESTO AQUÍ TAMBIÉN SE IMPRIMIRIA PERO AL REVES,           EJ: 23, 11101
        decimalAbinario(n/2);           /// LLAMA AL PROGRAMA TANTAS VECES SEA NECESARIA    EJ: 23, 10111
        cout << n % 2;                  /// Y CUANDO DEJA DE LLAMARLO COUTEAS LOS RESTOS AL REVES
    }                                   /// QUE POR LA NATURALEZA DEL CALCULO A MANO LOS PONE EN ORDEN

    /*
    void decimalABinario(int n){
        if (n/2 != 0) {
            decimalABinario(n/2);
        }
        cout << n%2;
    }
    */
}

int main() {
    int n;

    leerN(n);
    cout << "El numero " << n << " en binario es: ";
    decimalAbinario(n);
    return 0;
}
