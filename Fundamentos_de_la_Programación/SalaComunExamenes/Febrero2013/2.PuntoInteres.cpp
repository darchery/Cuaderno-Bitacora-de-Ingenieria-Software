#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N = 3;

struct TPuntoInteres {
    unsigned tipo;          //   0  ,     1     ,    2    ,    3
    string nombre;          // hotel, gasolinera, hospital, colegio
    bool hayPuntoInteres;   // false, true
};

typedef array<TPuntoInteres, N> TFila;
typedef array<TFila, N> TMapa;

/*
    Para localizar el punto de interés más cercano se buscará primero en la misma celda del
    mapa que la posición proporcionada (celda a distancia 0). Si en esa celda no hay ningún
    punto de interés del tipo solicitado se buscará en las celdas adyacentes (celdas a
    distancia 1) y así se irá desplazando a distancia 2, 3, etc… hasta encontrar el punto de
    interés o recorrer todo el mapa sin encontrarlo. Si hay más de un punto de interés a la
    misma distancia se devuelve el primero que se encuentre.
*/


bool celdaValida(int fila, int col)
{
    return fila >= 0 && fila < N && col >= 0 && col < N;
}

void distanciasDesdeFilaCol(const TMapa &mapa, unsigned tipo,
int fila, int columna, TPuntoInteres &puntInt, int &filaPi, int &columnaPi, bool &ok, int distancia)
{
    for (int i = fila - distancia;i <= fila + distancia && !ok;i++ )
    {
        for (int j = columna - distancia;j <= columna + distancia && !ok;j++ )
        {
            if (celdaValida(i,j) && mapa[i][j].tipo == tipo && mapa[i][j].hayPuntoInteres)
            {
                ok = true;
                filaPi = i;
                columnaPi = j;
                puntInt.tipo = mapa[i][j].tipo;
                puntInt.nombre = mapa[i][j].nombre;
                puntInt.hayPuntoInteres = ok;
            }
        }
    }
}

void puntoInteresMasCercano(const TMapa &mapa, unsigned tipo,
int fila, int columna, TPuntoInteres &puntInt, int &filaPi, int &columnaPi, bool &ok)
{
    int distancia = 0;

    if (mapa[fila][columna].tipo == tipo && mapa[fila][columna].hayPuntoInteres)
    {
        ok = true;
        filaPi = fila;
        columnaPi = columna;
        puntInt.tipo = mapa[fila][columna].tipo;
        puntInt.nombre = mapa[fila][columna].nombre;
        puntInt.hayPuntoInteres = ok;
    }
    else
    {
        do
        {
            distancia++;
            distanciasDesdeFilaCol(mapa,tipo,fila,columna,puntInt,filaPi,columnaPi,ok,distancia);
        } while (!ok && distancia < N);
    }

}

int main(){
    TMapa mapa = {{
            {{
                    {1, "Gasolinera Repsol", true}, {1, "Gasolinera Shell", false}, {1, "Gasolinera Electrica", true}
                    }
            },
            {{
                    {2, "Hospital Elyoya", true}, {1, "Gasolinera  Cepsa", true}, {3, "Colegio IBAI LLANOS", true}
                }
            },
            {{
                    {1, "Gasolinera EROSKI", true}, {0, "Hotel Movistar KOI", false}, {2, "Hospital Xpeke", true}
                }
            }
        }
    };

    int f, c;
    bool ok = false;
    TPuntoInteres p;
    puntoInteresMasCercano(mapa, 0, 1, 2, p, f, c, ok);
    // Mapa usado, Tipo de establecimiento, el punto de interes a encontrar,
    // posicion en la que estamos, Si ha sido encontrado o no

    if(ok)
    {
        cout << "Se ha encontrado en la posicion (" << f << "," << c << "): " << p.nombre << endl;
    }
    else
    {
        cout << "No se ha encontrado ningun punto de interes del tipo solicitado.";
    }

return 0;

}
