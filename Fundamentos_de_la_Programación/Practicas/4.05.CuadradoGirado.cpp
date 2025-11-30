#include <iostream>
using namespace std;

void imprimirArriba(int N)
{
    for (int i = 0;i < N ;i++ )
    {
        for (int k = 0;k < N - i ;k++ )
        {
            cout << "  ";
        }
        for (int j = 0;j < i ;j++ )
        {
            cout << "  * ";
        }
        cout << endl;
    }
}

void imprimirAbajo(int N)
{
    for (int i = 0;i <= N ;i++ )
    {
        for (int k = 0;k < i ;k++ )
        {
            cout << "  ";
        }
        for (int j = 0;j < N - i ;j++ )
        {
            cout << "  * ";
        }
        cout << endl;
    }
}

int main() {
    int N;

    do
    {
        cout << "Introduzca un numero: ";
        cin >> N;
    } while (N <= 0);

    imprimirArriba(N);
    imprimirAbajo(N);
    return 0;
}
