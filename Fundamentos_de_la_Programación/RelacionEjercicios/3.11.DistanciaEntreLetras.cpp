#include <iostream>
#include <array>
#include <math.h>
#include <string>

/*
La distancia entre dos letras en un texto es el número de letras que aparecen en el texto entre las
dos letras indicadas. Diseñe un algoritmo que lea un texto de longitud indefinida formado por
letras mayúsculas (que termina con un punto) y muestre por pantalla la máxima distancia entre
cada par de letras repetidas. Aquellas letras que no se repitan no aparecerán en la salida.

Ejemplo de ejecución:
Introduzca secuencia de mayúsculas (punto para finalizar): ABEADDGLAKE.
Distancia entre A: 4
Distancia entre D: 0
Distancia entre E: 7
*/

using namespace std;

const int LETRAS = 26;

struct TLetra {
    int ultPos = 0;
    int mayorDis = 0;
    bool repe = false;
};

typedef array<TLetra, LETRAS> TLista;

void leerYCalcMayorPos(TLista& lista)
{
    char c;
    int index = 0;
    int dis;
    cout << "Introduzca secuencia de mayusculas (punto para finalizar): ";
    cin.get(c);

    while (c != '.')
    {
        // Primera aparicion de la letra
        if (!lista[c - 'A'].repe && (c >= 'A' && c <= 'Z') && lista[c - 'A'].ultPos == 0)
        {
            lista[c - 'A'].ultPos = index;
        }
        // Demas apariciones
        else
        {
            lista[c - 'A'].repe= true;
            dis = index - lista[c - 'A'].ultPos - 1;
            lista[c - 'A'].ultPos = index;
            if (dis > lista[c - 'A'].mayorDis)
            {
                lista[c - 'A'].mayorDis = dis;
            }
        }
        index++;
        cin >> c;
    }
}

void escribir(TLista& lista)
{
    for (int i = 0;i < LETRAS ;i++ )
    {
        if (lista[i].repe)
        {
            cout << "Distancia entre " << char(i + 'A') << ": " << lista[i].mayorDis << endl;
        }
    }
}

// ABEADDGLAKE.

int main(){
    TLista lista1;

    leerYCalcMayorPos(lista1);
   escribir(lista1);
return 0;

}

/*#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int LETRAS = 26;

typedef array<int, LETRAS> TLetras;

struct TDis{
    TLetras distancia;
    string cadena;
};

void leerCadena(TDis& lista)
{
    cout << "Introduzca secuencia de mayusculas (punto para finalizar): ";
    getline(cin, lista.cadena, '.');
}

bool seRepite(TDis& lista, char letra)
{
    int tamString = lista.cadena.size();
    bool rep = true;
    int cntRep = 0;

    for (int i = 0;i < tamString ;i++ )
    {
        if (lista.cadena[i] == letra)
        {
            cntRep++;
        }
    }
    if (cntRep == 1)
    {
        rep = false;
    }
    return rep;
}

//  ABEADDGLAKE.
/// USAREMOS UN PRIMER FOR PARA ELEGIR UN CARACTER DEL ARRAY Y ASI MEDIR SU DISTANCIA ENTRE EL MISMO YA RECORRIENDO EL ARRAY DESDE LA POSICION DESPUES
/// DE EL MISMO CON EL SEGUNDO FOR
void calcularDistancias(TDis& lista)
{
    int tamString = lista.cadena.size();
    for (int i = 0;i < tamString ;i++ )     // QUIERO ELEGIR EL PRIMER ELEMENTO DE ARRAY VER SI SE REPITE Y SI SE REPITE COMPARARLO CON SU ARRAY Y SACAR LAS DISTANCIAS
    {
        if (seRepite(lista, lista.cadena[i]))
        {
            for (int j = 0;j < tamString  ;j++ )
            {
                if (lista.cadena[i] != lista.cadena[j])
                {
                    lista.distancia[i]++;
                }
                else if (lista.cadena[i] == lista.cadena[j])
                {
                    lista.distancia[i] = 0;
                }
            }
        }
    }
}

void imprimirDis(TDis& lista)
{
    for (int i = 0;i < LETRAS ;i++ )
    {
        if (lista.distancia[i] != 0)
        {
            cout << "Distancia entre " << char(i + 'A') << ": " << lista.distancia[i] << endl;
        }
    }
}

int main(){
    TDis lista;
    lista.distancia = {{}};

    leerCadena(lista);
    calcularDistancias(lista);
    imprimirDis(lista);
return 0;

}*/
/*
void leerSec(string& secuencia)
{
    cout << "Introduzca secuencia de mayusculas (punto para finalizar): ";
    getline(cin, secuencia, '.');
}

bool apareceMasDeUnaVez(string& secuencia, char letra)
{
    bool aparece = false;
    int cnt = 0;

    for (size_t i = 0;i < secuencia.size() ;i++ )
    {
        if (letra == secuencia[i])
        {
            cnt++;
        }
    }
    if (cnt > 1)
    {
        aparece = true;
    }
    return aparece;
}

int distanciaLetras(string& secuencia, char letra)
{
    int distancia = 0;
    bool primerLetra = false;

    for (size_t i = 0;i < secuencia.size() ;i++ )
    {
        if (letra != secuencia[i] && primerLetra == true )
        {
            distancia++;
        }
        else if (letra == secuencia[i] && primerLetra == false)
        {
            primerLetra = true;
        }
        else if (letra == secuencia[i] && primerLetra == true)
        {
            distancia = 0;
        }
    }
    return distancia;
}
// ABEADDGLAKE.
int main(){
    string secuencia;

    leerSec(secuencia);
    for (size_t i = 0;i < secuencia.size() ;i++ )
    {
        if (apareceMasDeUnaVez(secuencia, secuencia[i]))
        {
            cout << "Distancia entre " << secuencia[i] << ": " << distanciaLetras(secuencia, secuencia[i]) << endl;
        }
    }
return 0;

}
*/

