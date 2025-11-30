#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 5;
typedef array<int, MAX> TArray;
typedef array<bool, MAX> TAnalizados;

void leerArray(TArray& val)
{
    cout << "Introduzca " << MAX << " numeros enteros: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cin >> val[i];
    }
}

int tope(TArray& val)
{
    int top = val[0];

    for (int i = 0;i < MAX ;i++ )
    {
        if (top < val[i])
        {
            top = val[i];
        }
    }
    top++;
    return top;
}

/// EL PROBLEMA ACUTAL ES QUE SI LLEGA AL PRIMER VALOR YA NO SE ACTUALIZA EL BUCLE POR LO TANTO SE PARÁ AHI Y REPITE EN BUCLE LA POSICION DEL PRIMER NUMERO
/// SI POR OTRO LADO EL PRIMER NUMERO SALE EL ULTIMO PUES TODO FUNCIONA BIEN, PERO HAY QUE ARREGLARLO
int calcMin(TArray& val, TAnalizados& analizado)
{
    int minimo = tope(val); // CON ESTE TOP NUNCA OCURRIRÁ EL ERROR ANTERIOR
    int indiceMin;
    for (int i = 0;i < MAX ;i++ )
    {
        if (minimo > val[i] && !analizado[i])
        {
            minimo = val[i];
            indiceMin = i;
        }
    }
    analizado[indiceMin] = true;                /// USAMOS ESTE ARRAY DE BOOLS PARA TACHAR LOS NUMEROS YA USADOS
    /*cout << "Minimo: " << minimo << endl;
    cout << "Tachados: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cout << boolalpha << analizado[i] << " ";
    }
    cout << endl;*/
    return indiceMin;
}

void calcularInd(TArray& val, TArray& ind, TAnalizados& analizado)
{
    /// EN CADA CICLO PONE EL NUEVO MINIMO EN LA POSICION CORRESPONDIENTE DE ARRAY IND
    for (int i = 0;i < MAX ;i++ )
    {
        /*cout << endl;
        cout << "Ciclo " << i << ": " << endl;*/
        ///CALCULAR MINIMO
        ind[i] = calcMin(val, analizado);
        /*cout << "Indice min: " << ind[i]  << endl;*/
    }
}

void escribir(TArray& ind)
{
    cout << "El orden de los indices es: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cout << ind[i] << " ";
    }
}

int main(){
    TArray val, ind;
    TAnalizados analizado = {{}}; /// TODAS SERAN FALSE

    leerArray(val);
    calcularInd(val, ind, analizado);
    escribir(ind);
return 0;

}

/*
for (int i = 0;i < MAX ;i++ )
    {
        cout << "Ciclo " << i << ": " << endl;
        ///CALCULAR MINIMO
        for (int j = 0;j < MAX && i != 0;j++ )
        {
            if (minimo > val[j] && ind[i-1] != j)
            {
                minimo = val[j];
                ind[i-1] = j;
                cout << "IND" << "[" << i-1 << "]: " << ind[i-1] << endl;
                cout << "Min: " << minimo << endl;
                cout << "Min IND: " << j << endl;
            }
        }
    }
*/
