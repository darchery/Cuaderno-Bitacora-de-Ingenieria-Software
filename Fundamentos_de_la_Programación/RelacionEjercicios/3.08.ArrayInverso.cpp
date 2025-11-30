#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 7;

typedef array<int, MAX> TVector;

void leer(TVector& v)
{
    cout << "Introduzca " << MAX << " numeros enteros: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cin >> v[i];
    }
}

void intercambiar(int& x, int& y)
{
    int aux;

    aux = x;
    x = y;
    y = aux;
}

void invertirArray(TVector& v)
{
    for (int i = 0;i <= MAX/2  ;i++ )
    {
        intercambiar(v[i], v[MAX-1-i] );
    }
}

void imprimir(const TVector& v)
{
    cout << "Esos numeros en orden inverso son: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cout << v[i] << " ";
    }
}

int main(){
    TVector v1;

    leer(v1);
    invertirArray(v1);
    imprimir(v1);
return 0;

}

/*#include <iostream>
#include <array>
using namespace std;
const int MAX = 7;
typedef array<int,MAX> TArray;
void intercambiar(int& x, int& y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void invertir(TArray& a) {
    for (int i = 0; i <= MAX/2-1; i++) {
    intercambiar(a[i],a[MAX-1-i]);
    }
}
void leer(TArray& a) {
    cout << "Introduzca " << MAX << " numeros enteros: ";
    for (int i = 0; i < MAX; i++) {
    cin >> a[i];
    }
}
void escribir(const TArray& a) {
    cout << "Esos numeros en orden inverso son: ";
    // con un for-each
    for (int x : a) {
    cout << x << " ";
    }
}
int main() {
    TArray a;

    leer(a);
    invertir(a);
    escribir(a);
return 0;
}*/
