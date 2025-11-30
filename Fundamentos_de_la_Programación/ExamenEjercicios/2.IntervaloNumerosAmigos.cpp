#include <iostream>
#include <array>
#include <math.h>

void sonAmigos(int n, int m);
int sumaDivisores(int num);

using namespace std;

int main(){
    int n, m;

    cout << "Introduzca dos limites uno inferior y otro superior: ";
    cin >> n >> m;

    if (n > m)
    {
        cout << "ERROR: el limite inferior no puede ser mayor que el limite superior..." << endl;
    }
    else
    {
        sonAmigos(n,m);
    }
return 0;

}
// ESTA NO ES LA FORMA



// SON AMIGOS SI LAS SUMA DE LOS DIVISORES DE N = M Y LA SUMA DE LOS DIVISORES DE M = N
void sonAmigos(int n, int m)
{
    int sumDivN = 0; // TIENE QUE SER IGUAL A M
    int sumDivM = 0; // TIENE QUE SER IGUAL A N

    for (int n1 = n;n1 < m ;n1++ )
    {
        for (int n2 = n;n2 < m ;n2++ )
        {
            // EL ALGORITMO DEBERIA FUNCIONAR PERO CREO QUE ESTÁ PROBANDO MUCHISISMAS COMBINACIONES PROBABLEMENTE UN NUMERO COMBINATORIO ENTRE 2000,
            // ES PROBAR DESDE 1 2, 1,3 HASTA 1 2000 Y LUEOG PASAR AL 2 2000 Y LUEGO  OSEA HACER 2000 VECES 2000 VECES
            if (sumaDivisores(n1) == m && sumaDivisores(n2) == n)
            {
                cout << "Amigos: " << n1 << ", " << n2 << endl;
            }
        }
    }

}

int sumaDivisores(int num)
{
    int suma = 0;
    for (int div = 1;div < num ;div++ )
    {
        if (num % div == 0)
        {
            suma += div;
        }
    }
    return suma;
}
