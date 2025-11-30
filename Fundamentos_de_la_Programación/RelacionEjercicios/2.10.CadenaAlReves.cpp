#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_TAMANO = 100;

void cadenaInversa(char cadena[]);

int main(){
    char c[MAX_TAMANO];

    cout << "Introduzca la cadena de caracteres acabada en punto: ";
    cin.getline(c,MAX_TAMANO,'.');

    cadenaInversa(c);
    cout << "La cadena inversa es: " << c << endl;

return 0;

}

void cadenaInversa(char cadena[])
{
    int cntLetras = 0;

    while (cadena[cntLetras] != '\0') //EL \'0' SIGNIFICA QUE EL ARRAY ESTÉ VACIO
    {
        cntLetras++;                   //CUENTA LAS LETRAS
    }

        char newCadena[MAX_TAMANO]; // PREPARA UNA NUEVA CADENA
        int cntNew = 0;

        for (int i = cntLetras-1;i >= 0 ;i-- ) // PONE EN LA ANTIGUA CADENA INVERTIDA EN LA NUEVA
        {
            newCadena[cntNew] = cadena[i];
            cntNew++;
        }

            int j;  //NUEVO CONTADOR CADENA ANTIGUA

            for (int j = 0; j < cntLetras ; j++ ) // PASA LA CADENA INVERTIDA DESDE LA CADENA NUEVA A LA ANTIGUA
            {
                cadena[j] = newCadena[j];
            }
}
