#include <iostream>
#include <array>
#include <math.h>

/*Escriba un programa que tome como entrada desde teclado dos números naturales (mayores
que cero) "N" e "i", e imprima en pantalla el dígito que ocupa la posición i-ésima del número
N. Si i es mayor que el número de dígitos de N, se escribirá en pantalla -1. Por ejemplo, para N
= 25064 e i = 2, el resultado es el dígito 6, y para i = 7, el resultado es -1*/

// SE PUEDE OPTIMIZAR PONIENDO MENOS COSAS EN EL MAIN, CONVIERTIENDO EL VOID EN INT Y DEVOLVER EL RESULTADO EN UNA VARIABLE
// USANDO EL IF ELSE DEL MAIN EN EL INT PARA DEVOLVER EL RESULTADO, HABRÍA QUE CAMBIAR EL VOID Y EL MAIN
using namespace std;

int contarDigitos(int N);
void analizarNumero(int N, int i);

int main(){
    int N, i, numDigitos;

    do
    {
        cout << "Introduzca un numero y una posicion dentro de el mismo: ";
        cin >> N >> i;
    } while (N <= 0);

    numDigitos = contarDigitos(N);

    if (i > numDigitos)
    {
        cout << -1 << endl;
    }
    else
    {
        analizarNumero(N,i);
    }
return 0;

}

void analizarNumero(int N, int i)
{
    int fakeN = N;
    for (int ciclos = 1;ciclos <= i  ;ciclos++ )
    {
        if (i == ciclos)
        {
            cout << "El posicion " << i << " del numero " << N << " es " << fakeN % 10 << endl;
        }
        fakeN /= 10;
    }
}

int contarDigitos(int N)
{
    int digitos = 0;
    while (N != 0)
    {
        N /= 10;
        digitos++;
    }
    return digitos;
}

/*
int main(){
    int N, i;
    int numDigitos=1;
    bool encontrado = false;

    cout << "Introduzca un numero y una posicion dentro de el mismo: ";
    cin >> N >> i;
    int fakeN = N;


        while (fakeN >= 10 && encontrado == false)
        {
            fakeN /= 10;
            numDigitos++;

            if ( numDigitos == i)
            {
                fakeN %= 10;
                encontrado = true;
                cout << "La posicion " << i << " del numero " << N << " es " << fakeN << endl;
            }
            if (i > numDigitos)
            {
            encontrado = true;
            cout << -1 << endl;
            }
        }
return 0;
}
*/

