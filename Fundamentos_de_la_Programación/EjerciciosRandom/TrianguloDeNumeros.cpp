#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void imprimirTriangulo(int num);

int main(){
    int n;

    do
    {
        cout << "Introduzca un numero para hacer el triangulo(introduzca 0 para finalizar): ";
        cin >> n;
    } while ( n != 0 && n >= 10);

    imprimirTriangulo(n);
return 0;

}

void imprimirTriangulo(int num)
{
    int ini = 1;
    int centro = 35;

    for (int i = ini;i <= num ;i++ )
    {
        for (int j = 1;j <= centro - i ;j++ )
        {
            cout << " ";
        }
        for (int j = ini + 1;j <= i ;j++ )
        {
            cout << j;
        }
        for (int j = i - 1;j >= ini ;j-- )
        {
            cout << j;
        }
        cout << endl;
    }







}


/*void imprimirTriangulo(int num)
{
    int cnt = 1;
    for (int i = 0;i < num ;i++ )
    {
        for (int k = 0;k < num-i-1 ;k++ )
        {
            cout << " ";
        }
        for (int j = 0;j < i*2+1 ;j++ )
        {
            if (cnt >= num)
            {
                cnt = 1;
            }
            cout << cnt;
            cnt++;
        }
        cout << endl;
        cnt = 1;
    }

    int cnt = 1;
    for (int filas = 0;filas < num ;filas++ )
    {
        for (int espacios = 0;espacios < num-filas-1 ;espacios++ )
        {
            cout << " ";
        }

        for (int columnas = 0;columnas < filas*2+1 ;columnas++)
        {
            cout << cnt;
            if (cnt >= 9)
            {
                cnt = 1;
            }
            cnt++;
        }
        cout << endl;
    }
}
*/
