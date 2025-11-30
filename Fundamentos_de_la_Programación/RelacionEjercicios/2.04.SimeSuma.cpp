#include <iostream>
#include <array>
#include <math.h>

/*
Escribe un programa que acepte como entrada desde teclado un número natural mayor que cero
y dé como salida el resultado de sumar dos a dos los dígitos que aparecen en posiciones
simétricas respecto al dígito central dentro del número dado como entrada.*/

using namespace std;

int contarDigitos(int num)
{
    int numDigitos = 0;
    while (num != 0)
    {
        numDigitos++;
        num /= 10;
    }
    return numDigitos;
}

void sumarDigitosSimetricos(int num)
{
    int cntDigits = contarDigitos(num);
    int N = num;                                // COPIA PARA EL BUCLE DEL numSup
    int fakeN = num;
    int ciclos = contarDigitos(num) - 1;        // PARA CONTAR LOS CICLOS EN LO QUE VAMOS A REDUCIR EL NUMERO
    int cicloSup = ciclos;                      // UN SUBCICLO PARA ELEGIR EL NUMERO SUPERIOR
    int numSup, numInf;
    int imp = 1;                                // PARA COUT LOS CICLOS COMO RESULTADO

    for (int i = 0;i < ciclos ;i++ )
    {
        numInf = num % 10;                      // LIMITE INFERIOR

        while (cicloSup >= 1)                   // LIMETO SUPERIOR
        {
            fakeN /= 10;
            numSup = fakeN % 10;
            cicloSup--;
        }
        cout << imp <<" ciclo: " << numSup << " + " << numInf << " = " << numSup + numInf << endl;       // COUT EL RESULTADO

        ciclos -= 1;                // HACEMOS RESTE DE VARIABLES Y AJUSTE DE ESTAS
        cicloSup = ciclos;
        num /= 10;
        fakeN = N;
        // cout << "Numero: " << num << endl; ESTA ES LA CLAVE, SIEMPRE EL BUCLE ACABA EN EL CENTRO,
        // POR LO TANTO APROVECHAMOS ESTO PARA SACAR EL DIGITO DEL CENTRO
        imp++;
    }

    if (cntDigits % 2 != 0)        // SI ES IMPAR IMPRIME EL DIGITO DEL CENTRO
    {
        cout << imp << " ciclo: " << num % 10 << endl;
    }
}

// HAY UNA MANERA MAS EFICIENTE QUE HAY EN LA RELACION COMPLETA SOLUCIONADA

int main(){
    int n;

    cout << "Introduzca un numero(>0): ";
    cin >> n;

    if (n <= 0)
    {
        cout << "ERROR: no estan permitidos numeros menores que cero" << endl;
    }
    else
    {
        sumarDigitosSimetricos(n);
    }

return 0;

}

// 12345, 1º 1 + 5 = 6, 2º 2 + 4 = 6 SE HACEN 2 CICLOS PORQUE 5 / 2 = 2
// 123456, 1º 1 + 6 = 7, 2º 2 + 5 = 7, 3º 3 + 4 = 7 SE HACEN 3 CICLOS PORQUE 6 / 2 = 3



/*void esImpar(int num)
{
    int cnt = contarDigitos(num);
    int numSup, numInf;

    int N = num;
    int fakeN = num;

    int ciclos = contarDigitos(num) - 1;
    int cicloSup = contarDigitos(num) - 1;

    int imp = 1;

    for (int i = 0;i < ciclos ;i++ )
    {
        numInf = num % 10;                      // LIMITE INFERIOR

        while (cicloSup >= 1)                   // LIMITE SUPERIOR
        {
            fakeN /= 10;
            numSup = fakeN % 10;
            cicloSup--;
        }

        cout << imp <<" ciclo: " << numSup << " + " << numInf << " = " << numSup + numInf << endl;
        ciclos -= 1;
        cicloSup = ciclos;
        num /= 10;
        fakeN = N;
        // cout << "Numero: " << num << endl; ESTA ES LA CLAVE, SIEMPRE EL BUCLE ACABA EN EL CENTRO,
        // POR LO TANTO APROVECHAMOS ESTO PARA SACAR EL DIGITO DEL CENTRO
        imp++;
    }
}
*/

