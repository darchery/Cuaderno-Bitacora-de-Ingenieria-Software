#include <iostream>
#include <array>
#include <math.h>
#include <string>

using namespace std;

const int TAM = 9;

struct TLista {
    string grupo;  // 1 digito
    string editor; // 4 digitos
    string libro; // 4 digitos
};

void leerCodigos(TLista& lista)
{
    do
    {
        cout << "Introduzca el codigo de grupo: ";
        cin >> lista.grupo;
    } while (lista.grupo.size() != 1);
    do
    {
        cout << "Introduzca el codigo del editor: ";
        cin >> lista.editor;
    } while (lista.editor.size() != 4);
    do
    {
        cout << "Introduzca el codigo de grupo: ";
        cin >> lista.libro;
    } while (lista.libro.size() != 4);
}

void calcualarISBN(TLista& lista, string& codigo)
{
    int cod = stoi(codigo);
    int suma = 0;
    int digito;

    for (int i = TAM;i >= 1 ;i-- )
    {
        digito = cod % 10;
        suma += digito*i;
        cod /= 10;
    }
    if (suma % 11 == 10)
    {
        cout << "ISBN " << lista.grupo << " " << lista.editor << " " << lista.libro << " " << 'X' << endl;
    }
    else
    {
        cout << "ISBN " << lista.grupo << " " << lista.editor << " " << lista.libro << " " << suma % 11 << endl;
    }
}

int main(){
    TLista lista;

    leerCodigos(lista);
    string sumaCodigos = lista.grupo + lista.editor + lista.libro;
    calcualarISBN(lista,sumaCodigos);
return 0;

}

