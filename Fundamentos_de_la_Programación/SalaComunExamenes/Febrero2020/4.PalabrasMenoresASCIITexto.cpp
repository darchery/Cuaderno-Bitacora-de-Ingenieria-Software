#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_PAL_DIST = 20;
const string VACIO = "V4C10";
typedef array<string, MAX_PAL_DIST> TTexto;
typedef array<bool, MAX_PAL_DIST> TTachado;

struct TLista {
    TTexto texto;
    TTexto resultado;
    int tamRes = 0;
    int tamTexto = 0;
    string patron;
    int sumaPatron;
};

int sumaASCII(string palabra)
{
    int suma = 0;

    for (int i = 0;i < int(palabra.size()) ;i++ )
    {
        suma += palabra[i];
    }
    return suma;
}

bool esta(TLista& lista, string palabra, int index)
{
    bool siEsta = false;

    for (int i = index - 1;i >= 0 && !siEsta;i-- )
    {
        if (lista.texto[i] == palabra)
        {
            siEsta = true;
        }
    }
    return siEsta;
}

void leerTexto(TLista& lista)
{
    string palabra;
    int index = 0;

    cout << "Introduzca un texto (FIN para terminar): " << endl;
    cin  >> palabra;
    lista.patron = palabra;
    lista.sumaPatron = sumaASCII(palabra);

    while (palabra != "FIN")
    {
        if (!esta(lista, palabra, index))
        {
            lista.texto[index] = palabra;
            index++;
            lista.tamTexto++;
        }
        cin >> palabra;
    }
}

void analizarTexto(TLista& lista)
{
    int index = 0;
    int tamPalabra;

    for (int i = 1;i < lista.tamTexto ;i++ )
    {
        tamPalabra = sumaASCII(lista.texto[i]);
        if (lista.sumaPatron > tamPalabra)
        {
            lista.resultado[index] = lista.texto[i];
            index++;
            lista.tamRes++;
        }
    }
}

bool todosUsados(TLista& lista, TTachado& tachado)
{
    bool usado = true;

    for (int i = 0;i < lista.tamRes && usado;i++ )
    {
        if (!tachado[i])
        {
            usado = false;
        }
    }
    return usado;
}

// Falta ORDENARLAS ALFABETICAMENTE
// Mi idea ahora es buscar la palabra con la letra mas pequeña si hay alguna en la que sea igual entonces se ccogeran esas dos palabras
// Y se buscaran sus letras si alguna de estas no coincide, cogeremos la palabra cuya letra sea mas pequeña
// Habiendo acabado el ciclo de busqueda, tacharemos esa palabra con un array de bool que coincide con la siguiente palabra
// Para buscar una palara, la palabra que cogeremos no deberá estar tachadas

void escribirResultado(TLista& lista)
{
    //TTachado tachado = {{}};
    string palabra;

    cout << "Las palabras que son menores que " << lista.patron << " son: " << endl;
    /*while (!todosUsados(lista, tachado))
    {*/
        for (int i = 0;i < lista.tamRes ;i++ )
        {

        }
    //}
}

int main(){
    TLista lista;

    leerTexto(lista);
    analizarTexto(lista);
    escribirResultado(lista);
return 0;

}
