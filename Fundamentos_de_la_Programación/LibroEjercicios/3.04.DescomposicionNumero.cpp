#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int parteMasSigfinicativa(int& num1);
int parteMenosSigfinicativa(int& num2);
void digitoEnesimo(int& num3);

int main(){
    int numero1, numero2, numero3;

    cout << "Introduzca el numero: ";
    cin >> numero1;
    numero2 = numero1;
    numero3 = numero1;
    cout <<"\n";
    cout << "La parte mas significativa es " <<parteMasSigfinicativa(numero1) << endl;
    cout <<"\n";
    cout << "La parte menos significativa es " <<parteMenosSigfinicativa(numero2) << endl;
    cout <<"\n";
    digitoEnesimo(numero3);

return 0;

}

int parteMasSigfinicativa(int& num1)
{
    while (num1 >= 10)
    {
        num1 /= 10;
    }
    return num1;
}
int parteMenosSigfinicativa(int& num2)
{

    return num2%10;
}
void digitoEnesimo(int& num3)
{
    int cnt = 1;
    int fakeNum3 =  num3;

    while (num3 > 0)
    {
        fakeNum3 = num3%10;
        cout << "Digito " << cnt << ": " << fakeNum3 << endl;
        num3 /= 10;
        cnt++;
    }
}
