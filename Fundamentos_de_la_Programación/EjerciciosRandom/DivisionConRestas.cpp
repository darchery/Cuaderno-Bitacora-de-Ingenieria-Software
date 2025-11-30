#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void divisionRestas(int m, int n);

int main(){
    int m, n;

    do
    {
        cout << "Introduzca 2 numeros(>0): ";
        cin >> m >> n;
    } while (m < 0 || n <= 0);

    divisionRestas(m,n);
return 0;

}

void divisionRestas(int m, int n)
{
    int cnt = 0;
    while (m > n)
    {
        cout << m << " - " << n << " = " << m - n << endl;
        m = m - n;
        cnt++;
    }
    cout << "Hemos hecho " << cnt << " restas:  cociente es " << m/n <<", y el resto seria " << m << endl;
}
