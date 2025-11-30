#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void leer(int& N)
{
    do
    {
        cout << "Introduzca un numero: ";
        cin >> N;
    } while (N <= 0 || N >= 10);
}

void imprimirEspacios(int N)
{
    for (int i = 0;i < N ;i++ )
    {
        cout << " ";
    }
}

void imprimirAscendente(int num)
{
    for (int i = num;i <= num*2 - 1 ;i++ )      /// EJ: 5, EN LA FILA 5 ESTE IMPRIMIRA DESDE 5 HASTA 5*2-1 = 9, OSEA 5 6 7 8 9
    {                                           /// Y LUEGO EN EL BUCLE DE ABAJO DESDE 2*5-2 = 8 HASTA 5, OSEA 8 7 6 5
        cout << i % 10;                         /// QUEDARÍA TAL QUE ASI                567898765
    }
}
void imprimirDescendente(int num)
{
    for (int i = 2*num - 2; i >= num; i--)
        {
        cout << i % 10;
    }
}

int main(){
    int N;
    leer(N);

    for (int i = 1;i <= N ;i++ )
    {
        imprimirEspacios(N-i);
        imprimirAscendente(i);
        imprimirDescendente(i);
        cout << endl;
    }

return 0;

}

/*
          1
         232
        34543
       4567654
      567898765
     67890109876
    7890123210987
   890123454321098
  90123456765432109
 0123456789876543210
123456789010987654321
*/
