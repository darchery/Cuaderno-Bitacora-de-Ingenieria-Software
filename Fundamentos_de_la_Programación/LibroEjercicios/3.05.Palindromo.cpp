#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_TAMANO = 100;

char ponerAlReves(char cadena[]);
bool esPalindromo(char palabra[]);


int main(){

    char c[MAX_TAMANO];
    int n;

    cout << "Introduce la cadena terminada en punto: ";
    cin.get(c, MAX_TAMANO, '.');

    ponerAlReves(c);
    cout << "Cadena invertida: " << c << endl;

    cout <<"\n";

    cout << "Es un palindromo?" << endl;
    cout << boolalpha << esPalindromo(c);

    cout <<"\n";

    cout << "Introduce el numero acabado en 0: ";
    cin >> n;

    numeroAlReves(n);
    cout << "Cadena invertida: " << n << endl;

    return 0;

}

char ponerAlReves(char cadena[])
{
    int numCarac=0;
    char nuevaCadena[MAX_TAMANO];
    int cntNewCadena=0;
    int j;

    // CUENTA LOS CARACTERES DE LA PALABRA
    while (cadena[numCarac] != '\0')
    {
        numCarac++;
    }
        //PASA INVERTIDAMENTE LOS CARACTERES A UNA NUEVA CADENA
        for (int i = numCarac - 1; i >= 0 ; i-- )
        {
            nuevaCadena[cntNewCadena] = cadena[i];
            cntNewCadena++;
        }
            //LAS DEVUELVE A LA ANTIGUA CADENA
            for (j = 0; j < numCarac ; j++ )
            {
                cadena[j] = nuevaCadena[j];
            }
    return cadena[j];
}

bool esPalindromo(char palabra[])
{
    // HAY QUE  COMPARAR LA ANTIGUA CADENA CON LA CADENA INVERTIDA
    // Y RETURNEAR EL BOOL

    int numLetras=0;
    char nuevaPalabra[MAX_TAMANO];
    int cntNewPalabra=0;

    // CUENTA LOS CARACTERES DE LA PALABRA
    while (palabra[numLetras] != '\0')
    {
        numLetras++;
    }
        //PASA INVERTIDAMENTE LOS CARACTERES A UNA NUEVA CADENA
        for (int i = numLetras - 1; i >= 0 ; i-- )
        {
            nuevaPalabra[cntNewPalabra] = palabra[i];
            cntNewPalabra++;
        }
            numLetras=0;
            cntNewPalabra=0;

            if (palabra[numLetras] == nuevaPalabra[cntNewPalabra] )
            {
                return true;
            }
                else
                {
                    return false;
                }
}


