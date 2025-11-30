#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool esCapicua(int num);
int invertirNumero(int num);
void analizarSecuencia(int num);

int main(){
    int num;

    do
    {
        cout << "Introduzca una secuencia de numeros acabada en -1: ";
        cin >> num;

    } while (num <= 0);
    cout << "Los numero capicuas de la secuencia son: ";
    analizarSecuencia(num);

return 0;

}
bool esCapicua(int num)
{
    if (num == invertirNumero(num))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void analizarSecuencia(int num)
{
    while (num != -1)
    {
        if (esCapicua(num))
        {
            cout << num << " ";
        }
        cin >> num;
    }
}
int invertirNumero(int num)
{
    int numInvertido = 0;
    while (num > 0)
    {
        numInvertido = numInvertido*10; // HACE QUE EL PRIMER NUMERO SEA EL ULTIMO DIGITO + 0, EJ: 123, COGE EL 3 Y SUMA 0, PERO LUEGO SERA 3*10 = 30 + 2 Y DESPUES 32*10 = 320 +1 = 321
        numInvertido += num%10;         // AQUÍ SUMA LA ULTIMA CIFRA AL RESULTADO
        num /= 10;                      // Y AQUI REDUCE CORTA EL ULTIMO DIGITO, DE 123 A 12
    }

    /*int numDigitos = 0;
    int fakeN = num;
    int multiplicador = 1;

    while (fakeN != 0)
    {
        fakeN /= 10;
        numDigitos++;
    }
    fakeN = num;

    int digito;
    int cnt = numDigitos - 1;
    for (int i = 0; i < numDigitos ;i++ )
    {
        digito = fakeN % 10;
        numInvertido += digito*pow(10,cnt);
        fakeN /= 10;

    }
    */
    return numInvertido;
}


