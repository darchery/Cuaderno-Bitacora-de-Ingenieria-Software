#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void espacios(int N)
{
    for (int i = 0;i <= N ;i++ )         /// IMPRIME ESPACIOS HASTA N, DE 0 A N (N VECES)
    {
        cout << " ";
    }
}

void asteriscos(int N)
{
    for (int i = 0;i <= N ;i++ )        /// IMPRIME ASTERICOS DESDE O HASTA N INCLUIDO, OSEA N+1 CICLOS
    {
        cout << " *";
    }
}

int main(){
    int N;
    cin >> N;

    for (int i = 0;i <= N ;i++ )        /// ESTO CONTROLA LAS FILAS QUE SE CREAN, SON N+1 FILAS CREADAS
    {
        espacios(N-i);                  /// IMPRIME N-I ESPACIOS, QUE I VA CRECIENDO PROGRESIVAMENTE Y ASÍ SE VAN REGULANDO LOS ESPACIOS
        asteriscos(i-1);                /// AQUI LOS ASTERICOS EMPIEZAN EN UNO ASI QUE COMO I VA CRECIENDO CADA VEZ SE PONEN MAS ASTERICOS
        cout << endl;
    }
    cout << endl;
    for (int i = 0;i <= N ;i++ )
    {
        espacios(i-1);
        asteriscos(N-i);
        cout << endl;
    }
return 0;

}
