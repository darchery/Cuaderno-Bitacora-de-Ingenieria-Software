#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool cumpleConjetura(int num);
void analizaRango(int n, int m);
bool esPrimo(int num);

int main(){
    int n, m;

    do
    {
        cout << "Introduzca un minimo y un maximo: ";
        cin >> n >> m;

    } while (n > m);
    analizaRango(n,m);
return 0;

}
// DAMOS UN RANGO ENTRE MIN Y MAX
//  VAMOS A ANALIZAR LOS NUMERO PARES EN LA FUNCION BOOL (TENEMOS QUE ANAZLIZAR SOLO LOS PARES NUM % 2 == 0)

void analizaRango(int n, int m)
{
    int cntSecuencia = 0; // CUENTA LOS CICLOS DEL FOR
    int cntConjetura = 0; // CUENTA LAS VECES QUE  SE CUMPLE LA CONJETURA EN NUMEROS PARES

    for (int i = n;i <= m ;i++ )
    {
        if (i % 2 == 0 && cumpleConjetura(i))
        {
            cntConjetura++;
        }
        if(i % 2 == 0)
        {
            cntSecuencia++;
        }
    }
    if (cntConjetura == cntSecuencia)
    {
        cout << "Todos los pares en el rango elegido cumplen la conjetura" << endl;
    }
    else
    {
        cout << "No cumplen la condicion" << endl;
    }
}

bool cumpleConjetura(int num)
{
    bool cumple = false;
    //cout << "Numero analizado: " << num << endl;
    for (int prim1 = 1;prim1 < num ;prim1++ )                               // ESTE BUCLE LO QUE HACE ES IR COMPROBANDO UNO POR UNO
    {                                                                       // LA SUMA DE LAS COMBINACIONES
        for (int prim2 = 1;prim2 < num ;prim2++ )                           // PRIMERO COGE EL 1 Y ENTRA AL BUCLE Y COGE EL 1 Y LOS SUMA PARA VER SI
        {
            //cout << "Primo1: " << prim1 << endl;                          // ESTA SUMA ES IGUAL AL NUMERO PAR EN EL RANGO
            //cout << "Primo2: " << prim2 << endl;                          // SI NO LO ES, EN EL SEGUNDO BUCLE FOR SUMA UNO Y PRUEBA NUEVAMENTE A SUMAR
            if (esPrimo(prim1) && esPrimo(prim2) && (prim1 + prim2 == num)) // 1 + 2 Y SI ES IGUAL AL NUMERO PAR ACABA EL BUCLE Y PASA A SIGUIENTE PAR
            {
                cumple = true;
                return cumple;
            }
        }
    }
    return cumple;
}

bool esPrimo(int num)
{
    bool primo = false;
    int cntPrimo = 0;                       // SI ESTE ES MAYOR QUE 2 NO ES PRIMO
    for (int div = 1;div <= num ;div++ )
    {
        if (num % div == 0)
        {
            cntPrimo++;
        }
    }
    if (cntPrimo == 2)
    {
        primo = true;
    }
    return primo;
}
