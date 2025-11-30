/*
Un número se dice que es perfecto si su valor coincide con la suma de sus divisores sin contar
al propio número. Así, 6 es perfecto porque 6 = 1 + 2 + 3 y 28 también lo es porque 28 = 1 + 2
+ 4 + 7 + 14. Diseña un algoritmo que muestre por pantalla el siguiente número perfecto
después del 28.
*/
// CALCULA EL NUMERO PERFECTO, SI PONES 1 SALE 6 SI PONES 2 SALE 28 ETC
#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int num;
    int numPer = 1;
    int sum = 0;
    int div = 1;

    cout << "Introduzca el numero para calcular su respectivo numero perfecto: ";
    cin >> num;
    int fakeNum =  num;

    if ( num < 0)
    {
        cout << "Introduzca numeros mayores que cero..." << endl;
    }
    else
    {
        while (num > 0)
        {
            div = 1;
            sum = 0;
            numPer++;

            while (numPer > div)
            {
                if (numPer%div == 0)
                {
                    sum += div;
                }
                div++;
            }

            if (numPer == sum)
            {

                num--;
            }
    }
    cout << "El numero perfecto " << fakeNum << " es " << numPer << endl;

    }
return 0;

}

/*
 for (int div = 1; numPer >= div ;div++)
            {
                if (numPer%div==0)
                {
                    sum += div;
                }
*/
    // ESTE CALCULA SI ES PERFECTO O NO
/*
    int n;
    int sumDiv = 0;

    cout << "Introduzca un numero para ver si es perfecto: ";
    cin >> n;
    for (int i = 1;i < n ;i++ )
    {
        if (n%i == 0)
        {
            sumDiv += i;
        }
    }

    if (sumDiv == n)
    {
        cout << "Es un numero perfecto" << endl;
    }
    else{
        cout << "No es un numero perfecto" << endl;
    }
*/
