#include <iostream>
#include <array>
#include <math.h>

/*
Una matriz de números enteros doblemente estocástica normalizada es aquella que
cumple las siguientes condiciones:

    1. Todos sus elementos son no negativos y menores que 100.
    2. La suma de los elementos de cada fila es igual a 100.
    3. La suma de los elementos de cada columna es igual a 100.

Diseña un algoritmo que lea de teclado una colección de números enteros con los
que rellenar una matriz cuadrada de tamaño NxN (siendo N una constante definida),
muestre por pantalla después el contenido de dicha matriz y finalmente indique si
dicha matriz es o no doblemente estocástica normalizada. Recuerda que en la
solución se valorará la eficiencia de la misma y el uso de diseño descendente.
*/

using namespace std;

const int N = 3;
const int TOPE = 100;

typedef array<int, N> TFilas;
typedef array<TFilas, N> TMatriz;

void leerMatriz(TMatriz& matriz)
{
    cout << "Introduce los numeros enteros para una matriz cuadrada de " << N << " x " << N << ": " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            cin >> matriz[i][j];
        }
    }
}

bool positivosMenores100(TMatriz& matriz)
{
    bool es = true;

    for (int i = 0;i < N && es;i++ )
    {
        for (int j = 0;j < N && es ;j++ )
        {
            if (matriz[i][j] < 0)
            {
                es = false;
            }
            else if (matriz[i][j] >= TOPE)
            {
                es = false;
            }
        }
    }
    return es;
}

bool sumaFilas(TMatriz& matriz)
{
    int suma;
    bool suma100 = true;

    for (int i = 0;i < N && suma100 ;i++ )
    {
        suma = 0;
        for (int j = 0;j < N && suma100 ;j++ )
        {
            suma += matriz[i][j];
        }
        //cout << "Suma Fila " << i << ": " << suma << endl;
        if (suma != TOPE)
        {
            suma100 = false;
        }
    }
    return suma100;
}

bool sumaColumnas(TMatriz& matriz)
{
    int suma;
    bool suma100 = true;
    int j = 0;

    while (j < N && suma100)
    {
        suma = 0;
        for (int i = 0;i < N ;i++ )
        {
            suma += matriz[i][j];
        }
        if (suma != TOPE)
        {
            suma100 = false;
        }
        j++;
    }
    return suma100;
}

bool doblementeEstocasticaNormalizada(TMatriz& matriz)
{
    bool esEstocastica = false;

    if (positivosMenores100(matriz) && sumaFilas(matriz) && sumaColumnas(matriz))
    {
        esEstocastica = true;
    }
    return  esEstocastica;
}

void escribirMatriz(TMatriz& matriz)
{
    cout << "El cuadrado magico para N = " << N << " es: " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N ;j++ )
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
/*
void escribirMatriz(TMatriz& matriz)
{
    int cnt = 0;

    cout << "La matriz introducida es: " << endl;
    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;j < N  ;j++ )
        {
            if (cnt >= N)
            {
                cnt = 0;
                cout << endl;
            }
            cout << matriz[i][j] << " ";
            cnt++;
        }
    }
}*/
int main(){
    TMatriz matriz1;

    leerMatriz(matriz1);
    escribirMatriz(matriz1);
    cout << endl;
    if (doblementeEstocasticaNormalizada(matriz1))
    {
        cout << "La matriz introducida SI es doblemente estocastica normalizada" << endl;
    }
    else
    {
        cout << "La matriz introducida NO es doblemente estocastica normalizada" << endl;
    }
return 0;

}
/*
20 30 50
55 -5 50
25 75 0
*/
