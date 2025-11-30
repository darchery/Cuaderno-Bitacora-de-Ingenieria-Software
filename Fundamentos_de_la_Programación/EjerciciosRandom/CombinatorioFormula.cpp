#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void leerDatos(int& m, int& n);
double factorial(int x);
double combinacional(int m, int n);
void imprimirResultado(int m, int n, double res);

int main(){
    int n, m;
    double comb;
    leerDatos(m, n);
    comb = combinacional(m, n);
    imprimirResultado(m, n, comb);

return 0;

}

void leerDatos(int& m, int& n)
{
    do
    {
        cout << "Introduzca m y n para realizar el numero combinatorio(separado por espacios): ";
        cin >> m >> n;

    } while (m < 0 || n < 0 || m < n);

}

double factorial(int x)
{
    double fact = 1;

    for (int i = 2;i <= x ;i++)
    {
        fact *= i;
    }

    return fact;
}

double combinacional(int m, int n)
{
    // PRIMERA MANERA m!/n!*(m-n)
    return factorial(m) / (factorial(n) * factorial(m-n));

    // SEGUNDA MANERA (COMO SE HACE A MANO)
    /*
        int numerador = 1; //PARA PODER "TACHAR" LOS NUMEROS

        for (int i = 0;i < n;i++ )
        {
            numerador *= (m-i);
        }

        return numerador/factorial(n);
    */
    // TERCERA FORMULA ENTE MUCHAS COMILLAS
    // EJ: 12,3 = 12!/(3! * 9!) ELIMINO EL SEGUNDO QUE ES 9! (EL MAYOR BIEN HECHO!)
    // EJ: 12,9 = 12! /(9! * 3!) (EL PROGRAMA ELIMINA EL 3! PERO ES MAS EFICIENTE ELIMINAR EL 9!)
    // IMPLEMENTAR ESE IF, JUNTAR ESTA IDEA CON LA EJECUCION DEL SEGUNDO
    /*


    */
}

void imprimirResultado(int n, int m, double res)
{
    cout << "El numero combinatorio de " << m << " y " << n << " es " << res << endl;
}
