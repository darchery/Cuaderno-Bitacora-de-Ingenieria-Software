#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int UMBRAL = 4;

int numeroRepeticiones(string codigo, char letra,int posAct)
{
    int repes = 0;

    for (int i = posAct;i < int(codigo.size()) && codigo[i] == letra;i++ )
    {
        repes++;
    }
    return repes;
}

char charToInt(int numero)
{
    return '0' + numero;    // esto lo consigue ya que imagaina que numero = 4, '0' = 48 -> 48 + 4 = 52, 49 = '1', 50 = '2', 51 = '3' y 52 = '4';
}

void comprimir(string codigo, string& sol)
{
    for (int i = 0;i < int(codigo.size()) ;i++ )
    {
        if (numeroRepeticiones(codigo,codigo[i],i) < 4)
        {
            sol += codigo[i];
        }
        else if (numeroRepeticiones(codigo,codigo[i],i) >= 4)
        {
            sol += codigo[i];
            sol += '/';
            sol += charToInt(numeroRepeticiones(codigo,codigo[i], i));
            i += numeroRepeticiones(codigo,codigo[i], i);
        }
    }
}

void escribirCodigo(string codigo)
{
    for (int i = 0;i < int(codigo.size()) ;i++ )
    {
        cout << codigo[i];
    }
}

int main(){
    string codigo;
    string sol;

    cout << "Introduzca un codigo para comprimir: " << endl;
    getline(cin,codigo);
    comprimir(codigo,sol);
    cout << "Codigo comprimido: " << endl;
    escribirCodigo(sol);
return 0;

}

// abcaaaaaaadbbbbbbdddvvvvxxaaaaaaaaccc
