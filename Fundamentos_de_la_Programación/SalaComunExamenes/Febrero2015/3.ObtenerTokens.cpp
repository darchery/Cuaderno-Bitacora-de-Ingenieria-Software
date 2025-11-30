#include <iostream>
#include <array>
#include <math.h>

/// No esta correto, no entiendo que pide el ejercicio

using namespace std;

const int MAX = 50;

struct InfoTokens {
    string subcadena;
    int apariToken = 0;
};

typedef array<InfoTokens, MAX> TTokens;

struct TLista {
     TTokens tokens;
     int tam = 0;
};

bool esSeparador(const string& separadores, char c)
{
    bool siEs = false;

    for (int i = 0;i < int(separadores.size()) && !siEs;i++ )
    {
        if (c == separadores[i])
        {
            siEs = true;
        }
    }
    return siEs;
}

void obtenerTokens(const string& cadena, const string& separadores, TLista& lista)
{
    for (int i = 0;i < int(cadena.size());i++ )
    {
        if (!esSeparador(separadores,cadena[i]))
        {
            lista.tokens[lista.tam].subcadena += cadena[i];
        }
        else
        {
            lista.tokens[lista.tam].apariToken++;
            lista.tam++;
        }
    }
}

void escribirTokens(TLista& lista)
{
    for (int i = 0;i <= lista.tam ;i++ )
    {
        cout << "{" << lista.tokens[i].subcadena << "," << lista.tokens[i].apariToken << "}";
    }
}

int main(){
    TLista lista;
    string cadena, separadores;

    cout << "Introduzca la cadena: " << endl;
    getline(cin, cadena);
    cout << "Introduzca los separadores: ";
    getline(cin, separadores);
    cout << endl;
    obtenerTokens(cadena,separadores,lista);
    escribirTokens(lista);
return 0;

}
