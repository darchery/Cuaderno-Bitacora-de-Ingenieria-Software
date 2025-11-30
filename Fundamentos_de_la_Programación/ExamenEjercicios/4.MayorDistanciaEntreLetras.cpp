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
