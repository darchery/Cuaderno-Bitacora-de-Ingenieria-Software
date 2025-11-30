#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int const MAX = 20;
int const LETRAS = 26;
typedef array<int, LETRAS> TFrecuencia;
typedef array<char, MAX> TArray;

struct TLista {
    TArray caracteres;// caracteres almacenados (consecutivos desde índice 0)
    int numCaracteres;// numero de caracteres almacenados
};

void leerCalcFrec(TLista& lista, TFrecuencia& frecuencia)
{
    char c;
    cout << "Introduzca una secuencia de letras mayusculas (salto de linea para terminar y como maximo " << MAX << " letras): ";
    cin.get(c);
    for (int i = 0;i < MAX && c != '\n' ;i++ )
    {
        lista.caracteres[i] = c;
        lista.numCaracteres++;
        cin.get(c);
    }

    for (int i = 0;i < lista.numCaracteres ;i++ )
    {
        frecuencia[lista.caracteres[i] - 'A']++;
    }

}

void modaCadena(/*TLista& lista,*/ bool& modaFound, char& moda, TFrecuencia& frecuencia)
{
    int frecMayor = 0;
    modaFound = false;

    for (int i = 0;i < LETRAS ;i++ )
    {
        if (frecMayor < frecuencia[i])
        {
            frecMayor = frecuencia[i];
            moda = char(i + 'A');
            modaFound = true;
        }
        else if (frecMayor == frecuencia[i])
        {
            modaFound = false;
        }
    }

    if (modaFound)
    {
        cout << "La moda es: " << moda << endl;
    }
    else
    {
        cout << "No hay moda" << endl;
    }
}

int main(){
    TLista lista1;
    lista1.numCaracteres = 0;
    TFrecuencia frecuencia = {{0}};
    bool modaFound = false;
    char moda;

    leerCalcFrec(lista1, frecuencia);
    modaCadena(/*lista1,*/ modaFound, moda, frecuencia);
return 0;

}
/*
void leerCalcFrec(TLista& lista, TFrecuencia& frecuencia)
{
    char c;
    cout << "Introduzca una secuencia de letras mayusculas (salto de linea para terminar y como maximo " << MAX << " letras): ";
    cin.get(c);

    while (c != '\n' && lista.numCaracteres < MAX)
    {
        if (c >= 'A' && c <= 'Z')
        {
            frecuencia[c - 'A']++;
        }
        lista.numCaracteres++;
        cin.get(c);
    }
}*/

/*  PARA CHEQUEAR QUE SE GUARADAN LAS FRENCUENCIAS
    for (int i = 0;i < LETRAS ;i++ )
    {
        cout << char(i + 'A') << ": " << frecuencia[i] << endl;
    }
*/

