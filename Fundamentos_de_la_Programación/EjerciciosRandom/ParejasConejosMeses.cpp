#include <iostream>
#include <array>
#include <math.h>

// Disponemos de una pareja de conejos y deseamos saber cuántas parejas hay al cabo de n meses si:
// 1. Los conejos nunca mueren //
// 2. Una pareja de conejos pueden reproducirse al comienzo de su tercer mes de vida
// 3. Cada pareja madura genera una nueva al comienzo de cada mes

// EVOLUCIÓN
//     MES: 1         2        3         4        5        6          7
// PAREJAS: 1         1        1         1        1
//                             1         1        1
//                                       1        1
//                                                1
//                                                1
using namespace std;

int numeroDeParejasRecursivo(int mes)
{
    int parejas;

    if (mes <= 2)
    {
        parejas = 1;
    }
    else
    {
        parejas = numeroDeParejasRecursivo(mes-1) + numeroDeParejasRecursivo(mes-2);
    }
}


// ARREGLAR: SOLO CUENTA LOS HIJOS DE LA PRIMERA PAREJA, SI LA ENTRADA ES 4, EN EL MES UNO SE CRIAN 1 PAREJA
// SEGUNDO MES, 1 PAREJA, AL TERCER MES YA SE CREAN 1 + 1, UNA DE LA PRIMERA Y DE LA CREADA EN EL MES 1
// CUARTO MES SE SUMA 1 + 1 + 1, DE LA PRIMERA PAREJA OTRA CREADE DE LOS DEL MES 1 Y OTRA DE DEL MES 2 = 7
int numeroDeParejas(int mes)
{
    int parejas = 1;
    int cntNuevaPareja = 0;
    int cicloparejas = 0;

    for (int i = 0;i < mes ;i++ )
    {
        cout << "Parejas: " << parejas << endl;
        if (cntNuevaPareja == 2)
        {
            cicloparejas++;
            cntNuevaPareja = 0;
        }
        parejas += cicloparejas;
        cntNuevaPareja++;
    }
    return parejas;
}


int main(){
    int mes;

    do
    {
        cout << "Numero de meses: ";
        cin >> mes;
        cout << "El numero de parejas tras " << mes << " meses es " <<  numeroDeParejas(mes) << endl;

    } while (mes > 0);

return 0;

}

