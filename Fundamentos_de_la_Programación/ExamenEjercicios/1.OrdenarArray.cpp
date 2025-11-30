#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 10;
typedef array<int, MAX> TVector;
typedef array<bool, MAX> TTachado;

struct TLista {
    TVector v;
    TTachado tachado = {{}};
};

void leerVec(TLista& lista)
{
    cout << "Introduzca un vector de " << MAX << " numeros: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cin >> lista.v[i];
    }
}

int tope(TLista& lista)
{
    int top = lista.v[0];

    for (int i = 0;i < MAX ;i++ )
    {
        if (top < lista.v[i])
        {
            top = lista.v[i];
        }
    }
    top++;
    return top;
}

void elegirNumero(TLista& lista, int& num)
{
    int indexMin;
    num = tope(lista);    // CALCULAREMOS UN TOPE

    // Elegimos el minimo
    for (int i = 0;i < MAX ;i++ )
    {
        if (num > lista.v[i] && !lista.tachado[i])
        {
            num = lista.v[i];
            indexMin = i;
        }
    }

    // Lo tachamos de la lista
    lista.tachado[indexMin] = true;
}

void escribirVecOrdenado(TLista& lista)
{
    cout << "La lista ordenada es: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cout << lista.v[i] << " ";
    }
}

int main(){
    TLista lista1, lista2;
    int num;

    leerVec(lista1);
    for (int i = 0;i < MAX ;i++ )
    {
        elegirNumero(lista1, num);
        lista2.v[i] = num;
    }
    escribirVecOrdenado(lista2);
return 0;

}
