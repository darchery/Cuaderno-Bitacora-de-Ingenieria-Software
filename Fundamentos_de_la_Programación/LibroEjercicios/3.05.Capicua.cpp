#include <iostream>
#include <array>
#include <math.h>

using namespace std;


int numeroAlReves(int numero);
bool esCapicua(int num);

int main(){

    int n;

    cout << "Introduce el numero: ";
    cin >> n;

    cout << "Cadena invertida: " <<  numeroAlReves(n) << endl;

    cout << "Es capicua?" << endl;
    cout << boolalpha << esCapicua(n);

    return 0;
}

int numeroAlReves(int numero)
{
    int newNumero=0;
    int numeroCifras=0;
    int numero1 = numero;

    while (numero > 0)
    {
        numero /= 10;
        numeroCifras++;
    }

        while (numeroCifras >= 1)
        {
            /*cout << "Numero de cifras: " << numeroCifras << endl;
            cout <<"Numero final:" << newNumero << endl;
            cout <<"Numero:" << numero1 << endl;
            cout <<"Ultima cifra: " << numero1%10 << endl;
            */
            newNumero += (numero1%10) * pow(10,numeroCifras-1);
            numero1 /= 10;
            numeroCifras--;

        }
        return newNumero; //EL PROGRAMA FUNCIONA PERO NO PARA LOS DE 3 cifras
}

bool esCapicua(int num)
{
    int numeroAlreves = numeroAlReves(num);

    if (num == numeroAlreves)
    {
        return true;
    }
    else
    {
        return false;
    }
}
