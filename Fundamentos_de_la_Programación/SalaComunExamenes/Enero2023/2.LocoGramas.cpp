#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_PAL_DIST = 15;
typedef array<string, MAX_PAL_DIST> TTexto;

struct TLista {
    TTexto texto;
    int tamTexto = 0;
    string patron;
    string patronReducido;
    int tamPrimeraPalabra;
};

bool estaLaLetra(string patron, int index, char letra)
{
    bool siEsta = false;

    for (int i = index - 1;i >= 0 && !siEsta ;i-- )
    {
        if (patron[i] == letra)
        {
            siEsta = true;
        }
    }
    return siEsta;
}

void reducirPatron(string& patron)
{
    string newPat;

    for (int i = 0;i < int(patron.size());i++ )
    {
        if (!estaLaLetra(patron,i,patron[i]))
        {
            newPat += patron[i];
        }
    }
    patron = newPat;
}

bool esta(TLista& lista, string palabra, int index)
{
    bool siEsta = false;

    for (int i = index - 1;i >= 0 && !siEsta ;i-- )
    {
        if (palabra == lista.texto[i])
        {
            siEsta = true;
        }
    }
    return siEsta;
}

bool longitudesIguales(string p1, string p2)
{
    return p1.size() == p2.size();
}

bool tienenMismasLetras(string patron, string palabra)
{
    bool mismas = true;
    bool aparece;

    // Elegimos letra palabra
    for (int i = 0;i < int(palabra.size()) && mismas;i++ )
    {
        aparece = false;
        //Elegimos una letra del patron a comparar
        for (int j = 0;j < int(patron.size()) && !aparece;j++ )
        {
            // Comparamos la letra con la otra
            if (patron[j] == palabra[i])
            {  cout << palabra[i] << " y " << patron[j] << endl;
                aparece = true;
            }
        }
        // Si aparece sigue falso es quiere decir que no ha encontrado la letra, por lo tanto ya no son locogramas
        if (!aparece)
        {
            mismas = false;
        }
        cout << endl;
    }
    return mismas;
}

// Problema encontrado: en el caso que analizo, hay diferentes palabras y el programa se va ejecutando
// Va palabra por palabra hasta que llega a  CCSAS Y SSSAS y las junta y las analiza juntas, en vez
// de analizarlas por separadas como a las anteriores

void leerTexto(TLista& lista)
{
    string palabra;

    cout << "Introduzca un texto (FIN para terminar): " << endl;
    cin >> palabra;
    lista.tamPrimeraPalabra = palabra.size();
    lista.patron = palabra;
    lista.patronReducido = palabra;
    reducirPatron(lista.patronReducido);
    while (palabra != "FIN")
    {
        if (palabra != lista.patron && !esta(lista,palabra,lista.tamTexto) && longitudesIguales(lista.patron, palabra)
            && tienenMismasLetras(lista.patronReducido, palabra))
        {
            lista.texto[lista.tamTexto] = palabra;
            lista.tamTexto++;
        }
        cin >> palabra;
    }
}

void escribirLocogramas(TLista& lista)
{
    cout << "Las palabras que son locogramas de " << lista.patron << " son: " << endl;
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << lista.texto[i] << endl;
    }
}

int main(){
    TLista lista;

    leerTexto(lista);
    escribirLocogramas(lista);
return 0;

}
// SACAS LAS COSAS DE TUS CASAS Y LUEGO ME DICES CASAS Y CCSAS SSSAS SIN SENTIDO LAS CASAS DE COSAS DE ASACA FIN
