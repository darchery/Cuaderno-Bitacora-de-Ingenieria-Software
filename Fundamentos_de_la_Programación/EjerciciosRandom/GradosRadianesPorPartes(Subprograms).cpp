#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const double PI = 3.1416;

void leerDatos(double& n);
void imprimirResultado(double& n, double res);
double conversorGradosRadianes(double n);

int main(){
    double n, res;

    leerDatos(n);
    res = conversorGradosRadianes(n);
    imprimirResultado(n,res);

return 0;

}

void leerDatos(double& n)
{
    cout << "Introduzca un angulo expresado en grados para convertilo a radianes: ";
    cin >> n;
}

void imprimirResultado(double& n, double res)
{
    cout << n << " grados en radianes son " << res << " radianes" << endl;

}

double conversorGradosRadianes(double n)
{
    return (PI*n)/180.0;
}
