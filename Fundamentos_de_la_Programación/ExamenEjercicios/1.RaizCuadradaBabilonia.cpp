#include <iostream>
#include <array>
#include <math.h>


using namespace std;

double raizBabilonia(double num);

int main(){
    double num;

    do
    {
        cout << "Introduzca un numero para calcular su raiz: ";
        cin >> num;

    } while (num < 0);

    cout << "La raiz cuadrada de " << num << " con el metodo babilonio es: " << raizBabilonia(num) << endl;
return 0;

}

double raizBabilonia(double num)
{
    double res = sqrt(num);
    double aprox = num/2;
    double raiz = num/aprox;

    while (res != raiz)
    {
        raiz = num/aprox;
        aprox = (aprox+raiz)/2;
    }
    return raiz;
}
