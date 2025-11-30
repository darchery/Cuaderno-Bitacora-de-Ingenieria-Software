#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void invertirCadena(string cadena)
{
    string cadInv;
    int j = cadena.size() - 1;

    cout << "La cadena invertida es: ";
    for (int i = 0;i < cadena.size() ;i++ )
    {
        cadInv[i] = cadena[j];
        cout << cadInv[i];
        j--;
    }
}

int main(){
    string cadena;

    cout << "Introduce una cadena para invertirla: ";
    cin >> cadena;
    invertirCadena(cadena);
return 0;

}
