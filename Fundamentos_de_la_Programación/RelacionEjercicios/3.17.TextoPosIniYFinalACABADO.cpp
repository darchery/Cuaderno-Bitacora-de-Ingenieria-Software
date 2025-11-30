#include <iostream>
#include <array>
#include <math.h>

/// HAY QUE ARREGLAR QUE CUANDO SE ACABEN LAS PALABRAS ES DECIR EJ: TAMAÑO DE LAS PALABRAS DIFRENTES ES 7, PUES CUANDO LLEGA A LA SÉPTIMA PARE, Y
/// Y NO SIGA IMPRIMIENDO HASTA 15 (EN ESTE CASO LA PALABRA 7)

/*
A PRIORI:
   A. Usaremos un for porque ya como máximo se ejecutará 15 veces
    1. Elegir palabra que no se ha ya repetido, usaremos un bool del array de string, esta tendrá que estar en true para ser elegida
    2. Despues con la palabra elegida, recorreremos de nuevo el array y marcaremos esas 2 posiciones, la inicial y final
    3. Luego un subprograma se encargará de coutear la palabra (en true en ese momento), y sus 2 apariciones.
    4. Luego esta palabra sera puesta en false en su array
*/
using namespace std;

int const MAX_PAL_DIST = 15;
int const N = 100; /// PROVISIONALMENTE
/*
Problema: he querido meter el texto en un array de string para asi analalizarlo pero de esta manera tengo que poner una capacidad limite y no indefinidada,
y para eso debería reconfigurar el programa entero, cambiando toda la estructura
*/

typedef array<string, N> TTexto;
typedef array<bool, N> TTachado;

struct TLista {
    TTexto texto;
    TTachado tachado;
    int tamTexto;
};

void inicializar(TLista& lista)
{
    for (int i = 0;i < N ;i++ )
    {
        lista.tachado[i] = true;
    }
}

void leerTexto(TLista& lista)
{
    string cadena;
    lista.tamTexto = 0;

    cout << "Introduzca un texto (FIN para terminar): ";
    cin >> cadena;
    while (cadena != "FIN")
    {
        lista.texto[lista.tamTexto] = cadena;
        lista.tamTexto++;
        cin >> cadena;
    }
    cout << endl;
}

void elegirPalabra(TLista& lista, string& palabra)
{
    bool found = false;
    for (int i = 0;i < lista.tamTexto && !found ;i++ )
    {
        if (lista.tachado[i])
        {
            palabra = lista.texto[i];
            found = true;
        }
    }
}

void calcPosiciones(TLista& lista,string palabra ,int& primAparicion, int&  ultAparicion)
{
    bool aparicion = false;

    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        if (palabra == lista.texto[i] && !aparicion)    // PRIMERA APARCION
        {
            primAparicion = i + 1;
            ultAparicion = primAparicion;
            aparicion = true;
        }
        else if (palabra == lista.texto[i] && aparicion) // N-ESIMA APARCION QUE SE ACTUALIZA
        {
            ultAparicion = i + 1;
        }
    }
}

void imprimirPosiciones(string palabra ,int& primAparicion, int&  ultAparicion)
{
    cout << palabra << " " << primAparicion << " " << ultAparicion << endl;
}

// HOLA BUENOS DIAS HOLA YES SKIBIDI YES HOLA DIAS SKIBIDI YES FIN

int main(){
    TLista lista1;
    string palabra;
    int primAparicion, ultAparicion;

    int palabrasImpresiones = 0;

    inicializar(lista1);
    leerTexto(lista1);
    cout << "Palabras y posiciones primera y ultima: " << endl;
    for (int i = 0;i <= MAX_PAL_DIST && palabrasImpresiones < MAX_PAL_DIST;i++ )
    {
            elegirPalabra(lista1, palabra);
            calcPosiciones(lista1, palabra, primAparicion, ultAparicion);

            if (lista1.tachado[primAparicion - 1])                  /// ESTO SIRVE PARA REVISAR  LA SI ESA PALABRA SE HA USADO ANTES,
            {                                                       /// SI EL BOOL ES VERDADERO ESO QUIERE DECIR QUE NO SE HA USADO, POR LO TANTO USAREMOS ESTA PALABRA YA QUE NO SE HA REPETIDO
                imprimirPosiciones(palabra, primAparicion, ultAparicion);       /// USAMOS EL INDICE -1 YA QUE POR LA NATURALEZA DEL PROGRAMA CUENTA LAS POSICIONES DE UNO DE MAS
                palabrasImpresiones++;                                                  /// POR EJEMPLO SI LA PALABRA UNO ESTÁ EN LAS POS 1 ESO ES 1-1 Y SU INDICE REAL ES 0, POR TANTO AL ANALIZARLO NO USARIAMOS 1 SINO -1
            }

            for (int j = 0;j < lista1.tamTexto ;j++ )
            {
                if (palabra == lista1.texto[j])
                {
                    lista1.tachado[j] = false;
                }
            }
    }
return 0;

}

// Version mejorada, no hace falta el cons int N
/*
void leerTexto(TLista& lista)
{
    string cadena;
    bool repetido;
    int ciclosRepes;
    int index = 0;

    cout << "Introduzca el texto (FIN para terminar): ";
    cin >> cadena;

    while (cadena != "FIN" && lista.tamTexto < MAX_PAL_DIS)
    {
        repetido = false;
        ciclosRepes = lista.tamTexto - 1;

        // Asigancion de cadena en la posicion index del array
        lista.texto[index] = cadena;

        // Se repite el string?
        while (ciclosRepes >= 0 && !repetido)
        {
            if (lista.texto[ciclosRepes] == lista.texto[index] )
            {
                repetido = true;
            }
            ciclosRepes--;
        }

        // Si no se repite
        if (!repetido)
        {
            index++;
            lista.tamTexto++;
        }
    }

    // Siguiente elemento
    cin >> cadena;
}
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        cout << lista.texto[i] << endl;
    }
}
*/



/*void imprimirPosiciones(string palabra ,int& primAparicion, int&  ultAparicion)
{
    cout << palabra << " " << primAparicion << " " << ultAparicion << endl;
    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        if (palabra == lista.texto[i])
        {
            lista.tachado[i] = false;
        }
    }
}*/
