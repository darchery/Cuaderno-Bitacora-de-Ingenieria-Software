#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int mcd(int N1,int N2);

int main(){
    int n1, n2;

    cout << "Introduzca 2 numeros separados por espacios para calcular su MCD: ";
    cin >> n1 >> n2;


    cout << "El mcd de " << n1 << " y " << n2 << " es " << mcd(n1,n2)<< endl;

return 0;

}

int mcd(int N1,int N2)
{
    int div = 2;
    bool mcdEncontrado = false;

    if ( N1 < 0  || N2 < 0)
    {
        cout << "Introduzca numero mayores que positivos y mayores que 0..." << endl;
    }
    else
    {
        while ((div <= N1 || div <= N2) && mcdEncontrado == false)
        {
            if (N1%div==0 && N2%div==0)
            {
                mcdEncontrado = true;
            }
            div++;
        }
        return div-1;
    }
}
