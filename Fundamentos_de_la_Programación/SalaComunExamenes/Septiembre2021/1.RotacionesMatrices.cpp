
#include <iostream>
#include <array>
using namespace std;

const int MAX = 4;
typedef array<int, MAX> TFila;
typedef array<TFila, MAX> TMatriz;

void leer(TMatriz& m) {

	for (int fi = 0; fi < MAX; fi++) {
		for (int co = 0; co < MAX; co++) {
			cin >> m[fi][co];
		}
	}
}

void rotar1Vez(TMatriz& m)
{
    TMatriz mCopia = {{}};

    for (int fila = 0;fila < MAX ;fila++ )
    {
        for (int col = 0;col < MAX ;col++ )
        {
            mCopia[col][MAX-1-fila] = m[fila][col]; // Esto es la verdadera clave
        }
    }
    m = mCopia;
}

void rotar(TMatriz& m, int n)
{
    for (int i = 0;i < n ;i++ )
    {
        rotar1Vez(m);
    }
}

void escribir(const TMatriz& m) {

	for (int fi = 0; fi < MAX; fi++) {
		for (int co = 0; co < MAX; co++) {
			cout <<  m[fi][co] << " ";
		}
		cout << endl;
	}
}

int main() {
	TMatriz m;
	int n;

	cout << "Introduzca los elementos de la matriz ("
                << MAX << " x " << MAX << ") fila a fila:" << endl;
	leer(m);

    do
    {
        cout << "\nIntroduzca el numero de rotaciones a realizar: ";
        cin >> n;
    } while (n <= 0);

	rotar(m,n);

	cout << "\nLa matriz resultado tras las rotaciones es:\n";
	escribir(m);

	return 0;
}

/*
1 6 7 9
2 5 15 16
8 7 1 4
3 12 11 10
*/
