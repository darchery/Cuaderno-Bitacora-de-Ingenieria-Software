#include <iostream>
using namespace std;

void imprimirEspacios(int N)
{
    for (int i = 0;i < N ;i++ )
    {
        cout << " ";
    }
}

void imprimirAscendente(int N)
{
    for (int i = 1;i < N ;i++ )
    {
        cout << i;
    }
}
void imprimirDescendente(int N)
{
    for (int i = N;i > 0 ;i-- )
    {
        cout << i;
    }
}

int main() {
    int N;
    do
    {
        cout << "Introduzca un numero: ";
        cin >> N;
    } while (N <= 0 || N >= 10);

    int cnt = 1;
    for (int i = N;i >= 0 ;i-- )
    {
        imprimirEspacios(i);
        imprimirAscendente(cnt);
        imprimirDescendente(cnt-2);
        cout << endl;
        cnt++;
    }
    return 0;
}
