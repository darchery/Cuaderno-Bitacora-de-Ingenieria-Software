#include <iostream>

using namespace std;

const int TAM = 7; // Tamaño máximo de las listas

struct TLista {
    int elementos[TAM];
    int cantidadElementos = 0;

    void agregarElemento(int elemento) {
        if (cantidadElementos < TAM) {
            elementos[cantidadElementos] = elemento;
            cantidadElementos++;
        }
    }

    void rotarDerecha(int numRot) {
        numRot %= cantidadElementos; // Ajustar el número de rotaciones si es mayor que la cantidad de elementos
        while (numRot > 0) {
            int temp = elementos[cantidadElementos - 1];
            for (int i = cantidadElementos - 1; i > 0; --i) {
                elementos[i] = elementos[i - 1];
            }
            elementos[0] = temp;
            numRot--;
        }
    }

    void rotarIzquierda(int numRot) {
        numRot %= cantidadElementos; // Ajustar el número de rotaciones si es mayor que la cantidad de elementos
        while (numRot > 0) {
            int temp = elementos[0];
            for (int i = 0; i < cantidadElementos - 1; ++i) {
                elementos[i] = elementos[i + 1];
            }
            elementos[cantidadElementos - 1] = temp;
            numRot--;
        }
    }

    void mostrarLista() {
        for (int i = 0; i < cantidadElementos; ++i) {
            cout << elementos[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int numRot;
    cout << "Introduce el número de rotaciones: ";
    cin >> numRot;

    TLista lista1, lista2;

    cout << "Introduce los elementos de la lista 1 separados por espacios (max " << TAM << " elementos, negativo para terminar): ";
    int num;
    while (cin >> num && num >= 0) {
        lista1.agregarElemento(num);
    }
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Introduce los elementos de la lista 2 separados por espacios (max " << TAM << " elementos, negativo para terminar): ";
    while (cin >> num && num >= 0) {
        lista2.agregarElemento(num);
    }
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Contenido de las listas antes de las rotaciones:\n";
    cout << "Lista 1: ";
    lista1.mostrarLista();
    cout << "Lista 2: ";
    lista2.mostrarLista();

    lista1.rotarDerecha(numRot);
    lista2.rotarIzquierda(numRot);

    cout << "Contenido de las listas después de las rotaciones:\n";
    cout << "Lista 1 (rotada hacia la derecha): ";
    lista1.mostrarLista();
    cout << "Lista 2 (rotada hacia la izquierda): ";
    lista2.mostrarLista();

    return 0;
}
