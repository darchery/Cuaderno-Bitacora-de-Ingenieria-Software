#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool esAbundante(int num);


int main(){
    int num;
    int pos = 1;
    bool encontrado = false;
    cout << "Introduzca una secuencia acabada en cero: ";
    cin >> num;

    while (num != 0 && encontrado == false)
    {
        if (esAbundante(num))
        {
            encontrado = true;
            cout << "SI hay un numero abundante en la secuencia, "<< num << ", en la posicion "<< pos << endl;
        }
        pos++;
        cin >> num;
    }
    if (num == 0 && encontrado == false)
    {
        cout << "NO hay ningun numero abundaante en la secuencia" << endl;
    }
return 0;

}
bool esAbundante(int num)
{

    int suma = 0;

        for (int div = 1;div < num ;div++ )
        {
            if (num % div == 0)
            {
                suma += div;
            }
        }

        if (suma > num )
        {
            return true;
        }

    return false;
}
