#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool esPerfecto(int num)
{
    bool perfecto;
    int suma = 0;

    for (int i = 1;i < num ;i++ )
    {
        if (num % i == 0)
        {
            suma += i;
        }
    }
    if (num == suma)
    {
        perfecto = true;
    }
    else
    {
        perfecto = false;
    }
    return perfecto;
}

int mayorPerfecto(int sec)
{
    int mayor = 0;

    while (sec != 0)
    {
        if (esPerfecto(sec) && mayor < sec)
        {
            mayor = sec;
        }
        cin >> sec;
    }
    return mayor;
}

int main(){
    int sec;
    int mayor;

    cout << "Introduzca una secuencia de enteros positivos acabada en 0: ";
    cin >> sec;
    mayor = mayorPerfecto(sec);

    if (mayor == 0)
    {
        cout << "No hay perfecto en la secuencia" << endl;
    }
    else
    {
        cout << "El mayor perfecto de la secuencia es: " << mayor << endl;
    }
return 0;

}
