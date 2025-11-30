#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAM = 25;
typedef array<string, TAM> TTexto;

struct TLista {
    TTexto texto;
    int tamTexto = 0;
    string patron;
};

bool esta(TLista& l, string palabra, int posPal)
{
    bool siEsta = false;

    for (int i = posPal - 1;i >= 0 && !siEsta;i-- )
    {
        if (l.texto[i] == palabra)
        {
            siEsta  = true;
        }
    }
    return siEsta;
}

bool patronOrdenRelativo(TLista& l, string palabra)
{
    bool contiene = false;
    int cnt = 0;

    for (int i = 0;i < int(palabra.size()) && !contiene ;i++ )
    {
        cout << "LetraPal: " << palabra[i] << " y  LetraPat: " << l.patron[cnt] << endl;
        if (l.patron[cnt] == palabra[i])
        {
            cnt++;
            if (cnt == int(l.patron.size()) )
            {
                contiene = true;
            }
        }
    }
    cout << endl;
    return contiene;
}

void escribirTexto(TLista& l)
{
    cout << "Resultado: " << endl;
    for (int i = 0;i < l.tamTexto ;i++ )
    {
        cout << l.texto[i] << " ";
    }
}

int main(){
    TLista l;
    string palabra;

    cout << "Introduzca el patron: ";
    cin >> l.patron;
    cout << "Introduzca el texto (FIN para terminar): " << endl;
    cin >> palabra;

    while (palabra != "FIN")
    {
        if (!esta(l,palabra, l.tamTexto) && patronOrdenRelativo(l,palabra))
        {
            l.texto[l.tamTexto] = palabra;
            l.tamTexto++;
        }
        cin >> palabra;
    }
    escribirTexto(l);
return 0;

}

// CREO QUE IREMOS A LA DIRECCION QUE NOS DIERON Y TAMBIEN IREMOS A LA DIRECCION NUEVA QUE YO CONOCIA FIN
