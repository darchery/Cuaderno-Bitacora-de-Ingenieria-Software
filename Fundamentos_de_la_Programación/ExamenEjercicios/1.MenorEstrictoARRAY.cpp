#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 10;
typedef array<int, TAM> TArray;

void leerArray(TArray& vec)
{
    cout << "Introduzca una lista de " << TAM << " elementos: ";
    for (int i = 0;i < TAM ;i++ )
    {
        cin >> vec[i];
    }
}

bool seRepite(TArray& vec, int num)
{
    bool repite = false;
    int cnt = 0;

    for (int i = 0;i < TAM && !repite ;i++ )
    {
        if (num == vec[i])
        {
            cnt++;
        }

        if (cnt > 1)
        {
            repite = true;
        }
    }
    return repite;
}

void menorEstricto(TArray& vec, bool& found, int& menor)
{
    menor = vec[0];

    for (int i = 1;i < TAM ;i++ )
    {
        if (menor > vec[i])
        {
            menor = vec[i];
        }
    }

    if (!seRepite(vec, menor))
    {
        found = true;
    }
    else
    {
        found = false;
    }

}

int main(){
    TArray vec;
    bool found;
    int menor;

    leerArray(vec);
    menorEstricto(vec, found, menor);

    if (found)
    {
        cout << "Menor estricto: " << menor << endl;
    }
    else
    {
        cout << "No hay menor estricto" << endl;
    }
return 0;

}
