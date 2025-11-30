#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 10;
typedef array<int, MAX> TArray;

void leerArray(TArray& a)
{
    cout << "Introduce " << MAX << " números: ";
    for (int i = 0;i < MAX ;i++ )
    {
        cin >> a[i];
    }
}

double media(TArray& a)
{
    double suma = 0.0;

    for (int i = 0;i < MAX ;i++ )
    {
        suma += a[i];
    }
    return suma/MAX;
}

int primerMayorMedia(TArray& a, double mArit)
{
    int mayor = a[0];
    int pos = 0;
    bool found = false;

    for (int i = 1;i < MAX && !found;i++ )
    {

        if (mayor < a[i] && a[i] >= mArit)
        {
            cout << "Mayor ACT: " << mayor << endl;
            cout << "Candidato: " << a[i] << endl;
            mayor = a[i];
            pos = i;
            found = true;
        }
    }
    return pos;
}

int main(){
    TArray a1;

    leerArray(a1);
    cout << media(a1) << endl;
    cout << "El primer elemento mayor o igual que la media se encuentra en " << primerMayorMedia(a1, media(a1)) << endl;
return 0;

}
