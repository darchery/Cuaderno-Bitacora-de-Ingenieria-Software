#include <iostream>
#include <string>
#include <array>

using namespace std;

const int MAX_PAL_DIST = 15;

struct TReg {
    string palabra;
    int priPos;
    int ultPos;
};

typedef array<TReg,MAX_PAL_DIST> TArray;

struct TDatos {
    TArray elementos;
    int numElem;
};

int buscarInd(const string& pal, const TDatos& datos) {
    int ind = 0;

    while (ind < datos.numElem && pal != datos.elementos[ind].palabra)
    {
        ind++;
    }
    return ind;
}

void almacenar(TDatos& datos, const string& pal, int pos) {
    int ind = buscarInd(pal,datos);

    if (ind >= datos.numElem)   // primera aparicion de pal
    {
        datos.elementos[datos.numElem].palabra = pal;
        datos.elementos[datos.numElem].priPos = pos;
        datos.elementos[datos.numElem].ultPos = pos;
        datos.numElem++;
    }
    else    // se repite pal
    {
        datos.elementos[ind].ultPos = pos;
    }
}

void escribir(const TDatos& datos)
{
    cout << "Palabras y posiciones primera y ultima:\n";
    for (int i = 0; i < datos.numElem; i++)
    {
        cout << datos.elementos[i].palabra << " " << datos.elementos[i].priPos << " " << datos.elementos[i].ultPos << endl;
    }
}

int main() {
    string pal;
    int pos;
    TDatos datos;
    datos.numElem = 0;

    cout << "Introduzca un texto (FIN para terminar):\n";
    cin >> pal;
    pos = 1;

    while (pal != "FIN")
    {
        almacenar(datos,pal,pos);
        cin >> pal;
        pos++;
    }
    escribir(datos);
return 0;
}
