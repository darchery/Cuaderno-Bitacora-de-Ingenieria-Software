#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void triangulo(int n);
void trianguloAlreves(int n);

int main(){
    int n;

    cout << "Introduzca un numero(>0): ";
    cin >> n;

    triangulo(n);
    trianguloAlreves(n);
return 0;

}

void triangulo(int n)
{
    for (int i = 0;i < n ;i++ )
    {
        for (int k = 0;k < n-i-1 ;k++ )
        {
            cout << " ";
        }
        for (int j = 0;j < i ;j++ )
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void trianguloAlreves(int n)
{
    for (int i = 0;i <= n ;i++ )
    {
        for (int k = 0;k < i ;k++ )
        {
            cout << " ";
        }
        for (int j = 0;j < n-i-1 ;j++ )
        {
            cout << "* ";
        }
        cout << endl;
    }
}

