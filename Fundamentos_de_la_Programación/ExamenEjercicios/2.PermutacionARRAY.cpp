#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM1 = 11;
const int TAM2 = 4;

typedef array<int, TAM1> TNumeros;
typedef array<bool, TAM1> TTachadoNums;

typedef array<int, TAM2> TPermutacion;
typedef array<bool, TAM2> TTachadoPermut;

void leerArrays(TNumeros& numeros, TPermutacion& permutacion)
{
    cout << "Introduzca una permutacion de " << TAM2 << " elementos: ";
    for (int i = 0;i < TAM2 ;i++ )
    {
        cin >> permutacion[i];
    }

    cout << "Introduzca una lista de " << TAM1 << " elementos: ";
    for (int i = 0;i < TAM1 ;i++ )
    {
        cin >> numeros[i];
    }
}

void analizarRes(TTachadoPermut tachadoPermut, int& ocurrencias)
{
    bool aparecen = true;

    for (int index = 0 ;index < TAM2 && aparecen ;index++ )
    {
        if (!tachadoPermut[index])
        {
                aparecen = false;
        }
    }
        if (aparecen)
        {
            ocurrencias++;
        }
}

/*
Permutacion:
1 4 1 12
Vector:
12 1 1 4 1 7 14 1 12 12 4
*/


unsigned numOcurrencias(const TNumeros& numeros, const TPermutacion& permutacion, TTachadoNums tachadoNums, TTachadoPermut tachadoPermut)
{
    int ocurrencias = 0,limInf = 0, limSup = TAM2;
    bool pararBucle;
    int nIndex;

    // Ciclos de analisis, va a analizar la permutacion 11 veces en el array ya qye tiene 11 numeros
    for (int i = 0;i < TAM1 ;i++ )
    {
        tachadoPermut = {{}};
        pararBucle = false;
        nIndex = limInf;    // Asi está a la par por donde debe empezar

        // Ciclos, analizará el vector 4 veces como maximo, ya que la permutacion es TAM2 = 4
        for (int j = 0;j < TAM2 && !pararBucle;j++ )
        {
            tachadoNums = {{}};
            while (nIndex < limSup)
            {
                if (permutacion[j] == numeros[nIndex] && !tachadoNums[nIndex])
                {
                    tachadoPermut[j] = true;
                    tachadoNums[nIndex] = true;
                }
                nIndex++;
            }
            if (!tachadoPermut[j])
            {
                pararBucle = true;
            }
        }
        limInf++;   // Esto lo que hace es pasar de analizar el vector desde 0 a 4, de 1 a 5, y luego de 2 a 6 y así hasta 7 10
        limSup++;

        // Analisis del resultado, si todo el vector Permut está tachado eso quiere decir que hay una permutacion
        analizarRes(tachadoPermut, ocurrencias);
    }
    return ocurrencias;
}

int main(){
    TNumeros numeros;
    TPermutacion permutacion;
    TTachadoNums tachadoNums;
    TTachadoPermut tachadoPermut;

    leerArrays(numeros, permutacion);
    cout << "Numero de ocurrencias: " << numOcurrencias(numeros, permutacion, tachadoNums, tachadoPermut) << endl;;
return 0;

}


        /*bool aparecen = true;
        for (int index = 0 ;index < TAM2 && aparecen ;index++ )
        {
            if (!tachadoPermut[index])
            {
                aparecen = false;
            }
        }
        if (aparecen)
        {
            ocurrencias++;
        }*/
