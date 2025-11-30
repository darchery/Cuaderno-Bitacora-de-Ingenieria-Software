#include <iostream>
#include <array>
#include <math.h>

using namespace std;

/*
IDEA:
Hacer la criba con un array de frecuencias de todos los numeros que aparezcan.
Para ello necesito un array donde guardar el vector
Otro donde lo
*/

int const MAX = 10;
typedef array<int, MAX> TArray;
typedef array<int, MAX> TFrecuencia;

struct TLista {
    TArray vec;
    TFrecuencia frecuencia;
    int tamVector;
};

void leerNumsYX(TLista& lista , int& x)
{
    do
    {
        cout << "Cuantos numeros desea introducir (maximo " << MAX << " ): ";
        cin >> lista.tamVector;
    } while (lista.tamVector <= 0 || lista.tamVector > MAX);

    cout << endl;

    cout << "Introduzca " << lista.tamVector << " numeros: ";
    for (int i = 0;i < lista.tamVector ;i++ )
    {
        cin >> lista.vec[i];
    }

    cout << endl;

    do
    {
        cout << "Introduzca el numero de repeticiones para realizar la criba: ";
        cin >> x;
    } while (x < 0);
}

void escribir(const TLista& lista) {
cout << "La lista cribada es: ";
for (int i = 0; i < lista.tamVector; i++) {
cout << lista.vec[i] << " ";
}
}

/*
bool esta(int elem, const TLista& lista) {
int cont = 0;
while ((cont < lista.numElem) && (elem != lista.elementos[cont])) {
cont++;
}
return (cont < lista.numElem);
}
int repeticiones(int elem, const TLista& lista) {
int res = 0;
for (int i = 0; i < lista.numElem; i++) {
if (elem == lista.elementos[i]) {
res++;
}
}
return res;
}
void criba(int x, const TLista& lista1, TLista& lista2) {
lista2.numElem = 0;
for (int i = 0; i < lista1.numElem; i++) {
if ((repeticiones(lista1.elementos[i],lista1) == x)
&& (!esta(lista1.elementos[i],lista2))) {
lista2.elementos[lista2.numElem] = lista1.elementos[i];
lista2.numElem++;
}
}
}
*/
