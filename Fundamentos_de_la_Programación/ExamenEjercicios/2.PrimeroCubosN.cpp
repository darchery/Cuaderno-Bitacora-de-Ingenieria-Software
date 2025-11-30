#include <iostream>
#include <array>
#include <math.h>

// LOS CUBOS DE CON NICOMACO DE GERESA SE CACULA SUMANDO LOS NUMEROS IMPARES

using namespace std;

void cubos(int num);

int main(){
    int n;

    do
    {
        cout << "Introduzca un numero para imprimir sus cubos desde 1 hasta el mismo: ";
        cin >> n;

    } while (n < 0);

    cubos(n);
return 0;

}
// HACER QUE TENGAMOS UN CNT DIV QUE NUNCA SE REINICIE SIEMPRE PRUBE NUEVOS NUMEROS, PERO CUBO SIMPRE QUE COUTEE CUBO SE PONE A 0
void cubos(int num)
{

    int cubo = 0;
    int div = 1;
    cout << "Los " << num << " primeros cubos son: " << endl;

    for (int i = 1;i <= num ;i++ )
    {
        int tope = pow(i,3);
        while (cubo < tope)
        {
            if (div % 2 != 0)
            {
                cubo += div;
            }
            div++;
        }
        cout << i << " al cubo es :" << cubo << endl;
        cubo = 0;
    }

    /*
    for (int i = 1;i <= num ;i++ )
    {
        cout << i << " al cubo es :" << pow(i,3) << endl;;
    }
    */
}
