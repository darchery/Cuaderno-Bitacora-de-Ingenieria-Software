#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const string VACIO = "VACIO";
const int RATIO = 3;
const int MAX = 10;

struct TInfo {
    string nombre;
    unsigned res; // 0 1 o 2
    unsigned cant;
};

typedef array<TInfo, MAX> TDatos;

struct TLista
{
    TDatos datos;
    unsigned apuesta;
    int numPers = 0;
};

void leerDatos(TLista& lista)
{
    bool fin = false;
    int index = 0;

    cout << "Introduzca nombres, resultados y cantidades apostadas (FIN para terminar): " << endl;
    while (lista.numPers < MAX && !fin)
    {
        cout << "Nombre: ";
        cin >> lista.datos[index].nombre;
        if (lista.datos[index].nombre == "FIN")
        {
            fin = true;
        }
        else
        {
            cout << "Resultado (0 1 2): ";
            cin >> lista.datos[index].res;
            cout << "Cantidad (> 0): ";
            cin >> lista.datos[index].cant;
            lista.numPers++;
            index++;
        }
    }
    cout << "Introduzca el resultado final de la apuesta (0 1 2): ";
    cin >> lista.apuesta;
    cout << endl;
}

void sumarApostado(TLista& lista, int posAct)
{
    for (int i = posAct + 1;i < lista.numPers ;i++ )
    {
        if (lista.datos[i].nombre == lista.datos[posAct].nombre && lista.datos[i].res == lista.datos[posAct].res)
        {
            lista.datos[i].nombre = VACIO;
            lista.datos[posAct].cant += lista.datos[i].cant;
            lista.datos[i].cant = 0;
        }
    }
}

void juntarInputs(TLista& lista)
{
    for (int i = 0;i < lista.numPers;i++ )
    {
        if (lista.datos[i].nombre != VACIO)
        {
            sumarApostado(lista,i);
            cout << lista.datos[i].nombre << " " << lista.datos[i].res << " " << lista.datos[i].cant << endl;
        }
    }
}

void resumenApuesta(TLista& lista)
{
    int totalApostado = 0;
    int totalGanador = 0;

    for (int i = 0;i < lista.numPers ;i++ )
    {
        if (lista.datos[i].nombre != VACIO)
        {
            if (lista.apuesta == lista.datos[i].res)
            {
                totalGanador += lista.datos[i].cant;
            }
            totalApostado += lista.datos[i].cant;
        }
    }
    cout << "Total apostado: " << totalApostado << endl;
    cout << "Total ganador: " << totalGanador << endl;
    cout << "Ratio: " << RATIO << endl;
}

void resultadoApuesta(TLista& lista)
{
    for (int i = 0;i < lista.numPers;i++ )
    {
        if (lista.datos[i].nombre != VACIO)
        {
            if (lista.apuesta == lista.datos[i].res)
            {
                cout << lista.datos[i].nombre << " " << lista.datos[i].res << " " << lista.datos[i].cant << " -> " << RATIO * lista.datos[i].cant << endl;
            }
            else
            {
                cout << lista.datos[i].nombre << " " << lista.datos[i].res << " " << lista.datos[i].cant << " -> " << 0 * lista.datos[i].cant << endl;
            }
        }
    }
}

int main(){
    TLista lista;

    leerDatos(lista);
    juntarInputs(lista);
    cout << endl << endl;
    resumenApuesta(lista);
    cout << endl << endl;
    resultadoApuesta(lista);
return 0;

}
/*
luis 0 2 lola 1 3 juan 2 4 ana 2 2 luis 0 1 lola 1 6 FIN 2

Nombre: luis
Resultado (0 1 2): 0
Cantidad (> 0): 2
Nombre: lola
Resultado (0 1 2): 1
Cantidad (> 0): 3
Nombre: juan
Resultado (0 1 2): 2
Cantidad (> 0): 4
Nombre: ana
Resultado (0 1 2): 2
Cantidad (> 0): 2
Nombre: luis
Resultado (0 1 2): 0
Cantidad (> 0): 1
Nombre: lola
Resultado (0 1 2): 1
Cantidad (> 0): 6
Nombre: FIN
*/
