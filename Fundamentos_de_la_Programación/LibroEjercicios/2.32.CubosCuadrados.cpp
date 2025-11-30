#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){

    double num;
    int cuadrado;
    int cubo;
    bool cuaPerfecto = false;
    bool cubPerfecto = false;
    int parteEnteraRaizCua;
    int parteEnteraRaizCub;
    bool encontradoParteEnteraCub = false;

    cout << "Introduce un numero para calcular su cuadrado y su cubo:";
    cin >> num;

    if (num < 0)
    {
        cout << "Introduzca un numero positivo..." << endl;
    }
    else
    {
        cubo = pow(num,3);
        cuadrado = pow(num,2);

        int n = sqrt(num);
        double m = pow(num,1.0/3.0);

        if (num == n*n )
        {
           cuaPerfecto = true;
        }
        if (num == m*m*m)
        {
            cubPerfecto = true;
        }

        parteEnteraRaizCua = sqrt(num);
        parteEnteraRaizCub = pow(num,1.0/3.0);

    }

    cout << "El cuadrado de " << num << " es " <<  cuadrado << endl;
    cout << "El cubo de " << num << " es " <<  cubo << endl;
    cout << "La parte entera de la raiz cuadrada de " << num << " es " <<  parteEnteraRaizCua << endl;
    cout << "La parte entera de la raiz cubica de " << num << " es " <<  parteEnteraRaizCub << endl;

    if (cuaPerfecto)
    {
        cout << num << " es un cuadrado perfecto" << endl;
    }
    if (cubPerfecto)
    {
        cout << num << " es un cubo perfecto" << endl;
    }

return 0;

}
