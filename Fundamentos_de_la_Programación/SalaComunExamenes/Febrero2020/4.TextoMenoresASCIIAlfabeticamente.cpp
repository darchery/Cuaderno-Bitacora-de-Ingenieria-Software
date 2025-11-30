#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_PAL_DIST = 15;
typedef array<string, MAX_PAL_DIST> TTexto;

struct TLista {
    TTexto texto;
    int asciiPatron;
    int tamTexto = 0;
};

bool esta(const TLista& lista, string palabra, int posAct)
{
    bool siEsta = false;

    for (int i = posAct - 1;i >= 0 && !siEsta ;i-- )
    {
        if (lista.texto[i] == palabra)
        {
            siEsta = true;
        }
    }
    return siEsta;
}

int tamASCII(string palabra)
{
    int suma = 0;

    for (int i = 0;i < int(palabra.size()) ;i++ )
    {
        suma += palabra[i];
    }
    return suma;
}

int tamMenor(int x, int y)
{
    int menor = x;

    if (x > y)
    {
        menor = y;
    }
    return menor;
}

bool menorAlfabe(string palTexto ,string palabra)
{
    // SE ANALIZA SOLO CON EL TAMA�O DE LA PALABRA MENOR
    int minimaDistancia = tamMenor(palabra.size(),palTexto.size());

    for (int i = 0;i < minimaDistancia ;i++ )
    {
        // Si es menor, es menor alfabeticamente
        if (palabra[i] < palTexto[i])
        {
            return true;
        }
        // Si es mayor, sale del bucle y si sigue asi ira al fondo
        else if (palabra[i] > palTexto[i])
        {
            return false;
        }
    }
    // Aqui llega si la palabra es igual a la otra lo que las diferenia es su longitud
    // Si la palabra es menor tiene preferencia
    return palabra.size() < palTexto.size();
}

void desplazarUnoDerecha(TLista& lista, int posAct)
{
    lista.tamTexto++;
    for (int i = lista.tamTexto - 1 ;i > posAct ;i-- )
    {
        lista.texto[i] = lista.texto[i-1];
    }
}

void procesarPalabra(TLista& lista, string palabra)
{
    bool hueco = false;

    for (int i = 0;i < lista.tamTexto && !hueco;i++ )
    {
        if (menorAlfabe(lista.texto[i],palabra))
        {
            hueco = true;
            desplazarUnoDerecha(lista,i);
            lista.texto[i] = palabra;
        }
    }

    // No es menor alfabeticamente que ninguna
    if (!hueco)
    {
        lista.texto[lista.tamTexto] = palabra;
        lista.tamTexto++;
    }
}

void escribirTexto(const TLista& lista)
{
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << lista.texto[i] << " ";
    }
}

int main(){
    TLista lista;
    string palabra;

    cout << "Introduzca un texto (FIN para terminar): " << endl;
    cin >> palabra;
    string copia = palabra;
    lista.asciiPatron = tamASCII(palabra);
    while (palabra != "FIN")
    {
        if (!esta(lista,palabra,lista.tamTexto) && tamASCII(palabra) < lista.asciiPatron && palabra != copia && lista.tamTexto < MAX_PAL_DIST)
        {
            procesarPalabra(lista,palabra);
        }
        cin >> palabra;
    }
    cout << endl;
    cout << "Las palabras que son menores que " << copia << " son: " << endl;
    escribirTexto(lista);
return 0;

}

// CREO QUE VOY A FIN
// CREO QUE VOY A IR ESTA TARDE AL CINE Y LUEGO VOY A IR A CENAR MAS TARDE FIN
