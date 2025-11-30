#include <iostream>
#include <array>

using namespace std;

const int MAX_PAL_DIST = 20;
typedef array<string, MAX_PAL_DIST> TTexto;
typedef array<bool, MAX_PAL_DIST> TUsado;

struct TLista{
    TTexto texto;
    TUsado usado = {{}};
    int tamTexto = 0;
};

void leerTexto(TLista& lista)
{
    int index = 0;
    int cicloRepes;
    string palabra;
    bool repetida;

    cout << "Introduzca un texto (FIN para terminar): ";
    cin >> palabra;

    while (palabra != "FIN" && lista.tamTexto < MAX_PAL_DIST)
    {
        lista.texto[index] = palabra;
        cicloRepes = lista.tamTexto - 1;
        repetida = false;

        while (cicloRepes >= 0 && !repetida)
        {
            if (lista.texto[cicloRepes] == lista.texto[index])
            {
                repetida = true;
            }
            cicloRepes--;
        }

        if (!repetida)
        {
            index++;
            lista.tamTexto++;
        }

        cin >> palabra;
    }
}

int topeMayor(TLista& lista)
{
    int tope = lista.texto[0].size();

    for (int i = 1;i < lista.tamTexto ;i++ )
    {
        if (tope < int(lista.texto[i].size()) )
        {
            tope =int(lista.texto[i].size());
        }
    }
    return tope;
}

void menorAMayor(TLista& lista)
{
    int menorSize = topeMayor(lista);
    string menor = lista.texto[0];
    int indeMenor = 0;

    for (int i = 0;i < lista.tamTexto ;i++ )
    {
        if (menorSize >= int(lista.texto[i].size()) && !lista.usado[i])
        {
            menorSize = lista.texto[i].size();
            menor = lista.texto[i];
            indeMenor = i;
        }
    }
    if (!lista.usado[indeMenor])
    {
        cout << menor << " ";
        /*cout << menor << " " << "tam = " << menorSize << " " <<
        "tachado: " << boolalpha << lista.usado[indeMenor] << endl;*/
        lista.usado[indeMenor] = true;
    }
}

int main() {
    TLista lista1;

    leerTexto(lista1);
    cout << "Las palabras ordenadas de menor a mayor son: " << endl;
    for (int i = 0;i < lista1.tamTexto ;i++ )
    {
        menorAMayor(lista1);
    }
    //escribirTexto(lista1);
    return 0;
}

/*void escribirTexto(TLista& lista)
{
    cout << "Las palabras ordenadas de menor a mayor son: " << endl;
    for (int i = 0;i < lista.tamTexto;i++ )
    {
        cout << lista.texto[i] << " ";
    }
}*/
