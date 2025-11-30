#include <iostream>
#include <array>
#include <math.h>

/*El máximo común divisor (mcd) de dos números naturales p y q es el mayor entero d que
divide a ambos. Un algoritmo muy conocido para calcularlo es el de Euclides. Éste utiliza dos
variables, que contienen inicialmente a cada uno de los números, y trata de hacer que su
contenido sea el mismo. Para ello, irá restando la menor a la mayor hasta que ambas
contengan el mismo valor. En dicho momento, el valor obtenido en cualquiera de ellas es el
máximo común divisor de los dos números iniciales. Por ejemplo, si P = 18 y Q = 12, el
algoritmo hará que P y Q vayan tomando los siguientes valores:

Inicialmente P == 18 y Q == 12 (P > Q => P = P - Q)
Después P == 6 y Q == 12 (Q > P => Q = Q - P)
Después P == 6 y Q == 6 (P == Q => El mcd es 6)

Diseña una función con la siguiente cabecera para el algoritmo anterior siguiendo un
enfoque recursivo:

int mcd(int P, int Q)
Diseña también un algoritmo principal (main) para probar la función. Para ello, se leerán
de teclado los valores P y Q (asegurándose que son números > 0), se invocará a la función
implementada y se mostrará por pantalla el valor devuelto por la */

using namespace std;

int mcd(int P, int Q);

int main(){
    int P, Q;

    cout << "Introduzca 2 numeros: ";
    cin >> P >> Q;

    if (P <= 0 || Q <= 0)
    {
        cout << "ERROR: introduzca numero mayores que cero" << endl;
    }
    else
    {
        cout << "El mcd de " << P << " Y " << Q << " es " << mcd(P,Q) << endl;
    }
return 0;

}

int mcd(int P, int Q)
{
    int res;

    if (P == Q)
    {
        res = P;
    }
    else if (P > Q)
    {
        res = mcd(P - Q, Q);
    }
    else
    {
        res = mcd(P, Q-P);
    }

    return res;
}
