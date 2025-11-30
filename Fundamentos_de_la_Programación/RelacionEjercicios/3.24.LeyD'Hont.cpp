#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_CARGOS = 15;
const int MAX_PARTIDOS = 10;

struct TDatos {
    string nombre;
    int numVotos;
    int divPropio = 1;
    int escanyo = 0;
};

typedef array<TDatos, MAX_PARTIDOS> TPartidos;
typedef array<int, MAX_PARTIDOS> TAuxiliar;

struct TLista {
    TPartidos partido;
    TAuxiliar aux;
    int numCargos;
    int numPartidos;
};

void leerDatos(TLista& lista)
{
    cout << "Introduzca el Numero de Cargos (>= 1 y <= " << MAX_CARGOS << "): ";
    cin >> lista.numCargos;
    cout << "Introduzca el Numero de Partidos (>= 1 y <= " << MAX_PARTIDOS << "): ";
    cin >> lista.numPartidos;

    cout << "Introduzca el Nombre (un caracter) y Número de Votos por Partido: " << endl;
    for (int i = 0;i < lista.numPartidos;i++ )
    {
        cout << "Partido " << i + 1 << ": ";
        cin >> lista.partido[i].nombre >> lista.partido[i].numVotos;
        lista.aux[i] = lista.partido[i].numVotos;
    }
}

void escribirResultados(TLista& lista)
{
    cout << "Los cargos elecetos son: " << endl;
    for (int i = 0;i < lista.numPartidos ;i++ )
    {
        if (lista.partido[i].escanyo != 0)
        {
            cout << lista.partido[i].nombre << " " << lista.partido[i].escanyo << endl;
        }
    }
}

void mayorVoto(TLista& lista)
{
    int mayor = lista.partido[0].numVotos;
    int indexMayor = 0;

    // Buscamos el mayor
    for (int i = 1;i < lista.numPartidos ;i++ )
    {
        if (mayor < lista.partido[i].numVotos)
        {
            /*cout << "Antiguo mayor: " << mayor << endl;
            cout << "Mayor actual: " << lista.partido[i].numVotos << endl;*/
            mayor = lista.partido[i].numVotos;
            indexMayor = i;
        }
    }

    // Sumamos un escanyo y sumamos uno al divisor del mayor
    lista.partido[indexMayor].escanyo++;
    if (lista.partido[indexMayor].divPropio < lista.numCargos)
    {
        cout << "Votos actuales: " << lista.partido[indexMayor].numVotos << endl;
        lista.partido[indexMayor].divPropio++;
        lista.partido[indexMayor].numVotos =  lista.aux[indexMayor] / lista.partido[indexMayor].divPropio;
        cout << "Votos actuales entre " <<  lista.partido[indexMayor].divPropio << ": " << lista.partido[indexMayor].numVotos << endl;
    }
    // Problema: que cuando divide los votos se acumula, es es decir, despues de usar 340000 se divide 340000/2 pero luego no se divide
    // 340000/3 sino que divide 340000/2  entre 3 es decir 170000/ 3
    // Necesito no acumular eso, quizas con un array auxiliar
}

int main(){
    TLista lista;

    leerDatos(lista);
    for (int i = 0;i < lista.numCargos;i++ )
    {
        mayorVoto(lista);
    }
    escribirResultados(lista);
return 0;

}

/*
7 5 A 340000 B 280000 C 160000 D 60000 E 15000

Introduzca el Numero de Cargos (>= 1 y <= 15): 7
Introduzca el Numero de Partidos (>= 1 y <= 10): 5
Introduzca el Nombre (un caracter) y Número de Votos por Partido:
Partido 1: A 340.000
Partido 2: B 280.000
Partido 3: C 160.000
Partido 4: D 60.000
Partido 5: E 15.0000
*/
