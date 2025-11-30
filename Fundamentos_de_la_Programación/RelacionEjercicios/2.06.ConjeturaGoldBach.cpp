#include <iostream>
#include <array>
#include <math.h>

/*
La conjetura de Goldbach dice que todo número par mayor que 2 tiene la propiedad de que es
la suma de dos números primos. Diseña un algoritmo que compruebe si dicha conjetura es
cierta para todos los números pares comprendidos entre dos números leídos por teclado.*/

using namespace std;
//Nueva filosofia: separar las cosas en pequeños programas sencillos, pero necesitamos unirlos bien.

// OBJETIVOS: necesitamos un rango de numeros, por ejemplo desde 3 a 12, y solo analizar los pares de este, es decir 4, 6 , 8 , 10 y 12
//la conjetura se basa en que cualquier numero par puede ser descompuesto en 2 numeros primos
// Necesitamos un programa que  vea si el limite inferior es par, necesitamos ir sumando numeros primos y comprobar que estos 2 sumandos suman el limite inferior

bool cumpleConjetura(int num);
bool esPrimo(int num);
void analizarIntervalo(int limInf, int limSup);

int main(){
    int inf, sup;

    do
    {
        cout << "Introduzca el limite inferior: ";
        cin >> inf;
        cout << "\n";
        cout << "Introduzca el limite superior: ";
        cin >> sup;
    } while (inf > sup || inf < 0 || sup < 0);

    analizarIntervalo(inf,sup);
return 0;

}

void analizarIntervalo(int limInf, int limSup)
{
    bool cumple = false;
    for (int i = limInf;i <= limSup ;i++ )
    {
        if (i % 2 == 0 && cumpleConjetura(i))
        {
            cumple = true;
        }
    }
    if (cumple == true)
    {
        cout << "Todos los pares cumplen la conjentura" << endl;
    }
    else
    {
        cout << "No la cumplen" << endl;
    }
}

bool cumpleConjetura(int num)
{
    bool conjeOk = false;

    while (conjeOk == false)
    {
        for (int n1 = 1;n1 < num ;n1++ )
        {
            for (int n2 = 1;n2 < num ;n2++ )
            {
                if (esPrimo(n1) && esPrimo(n2) &&  n1 + n2  == num  )
                {
                    cout << n1 << " + " << n2 << " = " << num << endl;
                    conjeOk = true;
                }
            }
        }
    }
    return conjeOk;
}

bool esPrimo(int num)
{
    bool primo = true;

    for (int div = 2;div < num ;div++ )
    {
        if (num % div == 0)
        {
            primo = false;
        }
    }
    if (num == 1)
    {
        primo = false;
    }
    return primo;
}
