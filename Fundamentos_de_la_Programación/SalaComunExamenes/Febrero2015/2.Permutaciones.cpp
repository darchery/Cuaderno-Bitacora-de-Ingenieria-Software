#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM1 = 11;
const int TAM2 = 4;
typedef array<int, TAM1> TNumeros;
typedef array<int, TAM2> TPermutacion;
typedef array<bool, TAM1> TTachado;

bool hayOcurrencia(const TNumeros& numeros, const TPermutacion& permutacion, int inicio, int fin)
{
    TTachado tachado = {{}};
    bool siHay = true;
    bool found;

    for (int i = 0;i < TAM2 && siHay ;i++ )
    {
        found = false;
        for (int j = inicio;j < fin && siHay && !found;j++ )
        {
            if (numeros[j] == permutacion[i] && !tachado[j])
            {
                found = true;
                tachado[j] = true;
            }
        }
        if (!found)
        {
            siHay = false;
        }
    }
    return siHay;
}

unsigned numOcurrencias(const TNumeros& numeros, const TPermutacion& permutacion)
{
    unsigned ocurrencias = 0;

    for (int i = 0;i < TAM1 - TAM2 ;i++ )
    {
        if (hayOcurrencia(numeros, permutacion,i,i+4))
        {
            ocurrencias++;
        }
    }
    return ocurrencias;
}

int main(){
    TNumeros numeros;
    TPermutacion permutacion;
    unsigned ocurencias;

    cout << "Introduzca la permutacion  de " << TAM2 << " elementos: ";
    for (int i = 0;i < TAM2 ;i++ )
    {
        cin >> permutacion[i];
    }
    cout << endl;
    cout << "Introduzca una lista de numeros de " << TAM1 << " elementos: ";
    for (int i = 0;i < TAM1;i++ )
    {
        cin >> numeros[i];
    }
    cout << endl;

    ocurencias = numOcurrencias(numeros,permutacion);
    if (ocurencias == 0)
    {
        cout << "No hay ocurrencias" << endl;
    }
    else
    {
        cout << "Hay " << ocurencias << " ocurrencias" << endl;
    }
return 0;

}
