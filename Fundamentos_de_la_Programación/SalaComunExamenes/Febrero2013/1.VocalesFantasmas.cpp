#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int LETRAS = 5;
typedef array<int, LETRAS> TFrecuenciaVocales;

const string VOCALES = "AEIOU";

const int MAX_PALS_DIST = 15;
typedef array<string, MAX_PALS_DIST> TTexto;

struct TLista {
    TTexto texto;
    int tamTexto = 0;
    string patronCons;
    string partronReducido;
    int tamPat = 0;
};

bool esta(TLista& lista,string palabra ,int posAct)
{
    bool siEsta = false;

    for (int i = posAct - 1;i >= 0 && !siEsta ;i-- )
    {
        if (palabra == lista.texto[i])
        {
            siEsta = true;
        }
    }
    return siEsta;
}

bool esVocal(char letra)
{
    bool siEs = false;

    for (int i = 0;i < int(VOCALES.size()) && !siEs;i++ )
    {
        if (letra == VOCALES[i])
        {
            siEs = true;
        }
    }
    return siEs;
}

void reducirPatron(TLista& lista)
{
    string aux;

    for (int i = 0;i < int(lista.patronCons.size()) ;i++ )
    {
        if (!esVocal(lista.patronCons[i]))
        {
            aux = lista.patronCons[i];
            lista.partronReducido += aux;
            lista.tamPat++;
        }
    }
}

void inicializar(TLista& lista, string palabra)
{
    lista.patronCons = palabra;
    reducirPatron(lista);
}

void contieneConsonantesSeguidas(const TLista& lista ,bool& siEs ,string palabra, int indexPal)
{
    int indexPat = 1;
    bool stop = false;

    for (int i = indexPal + 1 ;i < int(palabra.size()) && indexPat <= lista.tamPat && !siEs && !stop;i++ )
    {
        if (!esVocal(palabra[i]) && lista.partronReducido[indexPat] != palabra[i])
        {
            stop = true;
        }
        else if (lista.partronReducido[indexPat] == palabra[i] && !esVocal(palabra[i]) && !stop)
        {
            indexPat++;
        }
    }

    // Si indexPat = tamPat es que se han encontrado todos
    if (indexPat == lista.tamPat  && !stop)
    {
        siEs = true;
    }
}

bool asociadoVocalesFantasmas(const TLista& lista, string palabra)
{
    bool siEs = false;

    for (int i = 0;i < int(palabra.size()) && !siEs;i++ )
    {
        if (lista.partronReducido[0] == palabra[i])
        {
            contieneConsonantesSeguidas(lista ,siEs, palabra, i);
        }
    }
    return siEs;
}

// Falta controlar que tengan las mismas vocales, pero este subprograma no funciona, cuando en otros programas si funciona
// Problema anterior: el array que contaba las vocales  no se reiniciaba en cada bucle

void frecuenciaVocales(TFrecuenciaVocales& frec, string palabra)
{
    for (int i = 0;i < int(palabra.size()) ;i++ )
    {
        if (esVocal(palabra[i]))
        {
           for (int j = 0;j < LETRAS;j++ )
           {

               if (palabra[i] == VOCALES[j])
               {
                    frec[j]++;
               }
           }
        }
    }
}

void escribirRes(const TLista& lista)
{
    cout << "El numero de palabras asociadas por vocales fantasmas con el patron " << lista.patronCons << " es " << lista.tamTexto << endl;
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << "Palabras n. " << i + 1 << " : " << lista.texto[i] << endl;
    }
}

int main(){
    TFrecuenciaVocales frecVocPatron = {{}};
    TFrecuenciaVocales frecVoc;
    TLista lista;
    string palabra;

    cout << "Introduzca un texto acabado en FIN, donde la primera palabra sera el patron a comparar: " << endl;
    cin >> palabra;
    inicializar(lista,palabra);
    frecuenciaVocales(frecVocPatron,palabra);
    while (palabra != "FIN")
    {
        frecVoc = {{}};
        frecuenciaVocales(frecVoc,palabra);
        if (!esta(lista,palabra,lista.tamTexto) && asociadoVocalesFantasmas(lista, palabra) && palabra != lista.patronCons && frecVoc == frecVocPatron)
        {
            lista.texto[lista.tamTexto] = palabra;
            lista.tamTexto++;
        }
        cin >> palabra;
    }
    escribirRes(lista);
return 0;

}
