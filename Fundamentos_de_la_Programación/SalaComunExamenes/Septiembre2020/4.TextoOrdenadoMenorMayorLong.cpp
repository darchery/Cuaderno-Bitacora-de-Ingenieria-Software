#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_PAL_DIST = 20;
typedef array<string,MAX_PAL_DIST> TTexto;

struct TLista {
    TTexto texto;
    int tamTexto = 0;
};

bool esta(const TLista& lista, string palabra, int posActual)
{
    bool siEsta = false;

    for (int i = posActual - 1;i >= 0 && !siEsta;i-- )
    {
        if (palabra == lista.texto[i])
        {
            siEsta = true;
        }
    }
    return siEsta;
}

void moverUnoDerecha(TLista& lista, int posEncontrada)
{
    // Aumentamos el tamaño
    lista.tamTexto++;

    // Movemos todos los elementos una posicion a la derecha
    for (int i =  lista.tamTexto - 1;i > posEncontrada;i-- )
    {
        lista.texto[i] = lista.texto[i-1];
    }
}

void procesarPalabra(TLista& lista, string palabra)
{
    bool huecoFound = false;

    for (int i = 0;i < lista.tamTexto && !huecoFound;i++ )
    {
        // Comprueba si esta palabra es de menor tamaño que las demas
        if (palabra.size() < lista.texto[i].size())
        {
            huecoFound = true;
            moverUnoDerecha(lista,i);
            lista.texto[i] = palabra;
        }
    }

    // Si esa palabra no es menor que ninguna de las que ya hay se mete en el vector
    if (!huecoFound)
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
    while (palabra != "FIN")
    {
        if (!esta(lista,palabra,lista.tamTexto) && lista.tamTexto < MAX_PAL_DIST)
        {
            procesarPalabra(lista,palabra);
        }
        cin >> palabra;
    }
    cout << "Las palabras ordenadas de menor a mayor por longitud son: " << endl;
    escribirTexto(lista);
return 0;

}

// CREO QUE VOY A IR ESTA TARDE AL CINE Y LUEGO VOY A IR A CENAR MAS TARDE FIN
