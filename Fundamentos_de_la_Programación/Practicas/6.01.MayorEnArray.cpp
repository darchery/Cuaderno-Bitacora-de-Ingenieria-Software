#include <iostream>
#include <array>

using namespace std;

const int TAM = 10;
typedef array<int, TAM> TMayor;

void leerV(TMayor& v)
{
    cout << "Introduzca " << TAM << " numeros enteros: ";
    for (int i = 0;i < TAM ;i++ )
    {
        cin >> v[i];
    }
}

int mayorV(TMayor& v)
{
    int mayor = v[0];
    for (int i = 1;i < TAM ;i++ )
    {
        if (mayor < v[i])
        {
            mayor = v[i];
        }
    }
    return mayor;
}

int main()
{
    TMayor v1;

    leerV(v1);
    cout << "El mayor del vector es: " << mayorV(v1) << endl;
    return 0;
}

