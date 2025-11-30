#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool esPalindromo(string cadena)
{
    bool palin = false;

    int i = 0;                  /// CADENA NORMAL
    int j = cadena.size() - 1;  /// CADENA INVERTIDA
    int cnt = 0;                /// ESTE CNT SE ESTABLECE EN 0, SI ESTE VARIA EN EL BUCLE ESO QUIERE DECIR QUE TODAS LA CADENA ES IGUAL
                                /// DA IGUAL POR DONDE SE LEA
    while (cadena[i] == cadena[j] && i < j && cnt == 0)     /// AQUI COMPARA EN CADA CICLO SI SON IGUALES LAS CADENAS
    {
        palin = true;
        i++;            // PASA AL SIGUIENTE NUMERO
        j--;            // PASA AL SIGUIENTE NUMERO
        if (cadena[i] != cadena[j])                         /// SI EN ALGUN MOMENTO SON IGUALES ESTE SE DECLARA FALSO Y AUMENTA EL CNT
        {
            palin = false;
            cnt++;
        }
    }
    return palin;
}

int main(){
    string cadena;

    cout << "Introduzca una palabra comprobar si es un palindromo: ";
    cin >> cadena;
    if (esPalindromo(cadena))
    {
        cout << cadena << " ES palindromo" << endl;
    }
    else
    {
        cout << cadena << " NO es palindromo" << endl;
    }
return 0;

}
/// OTRA MANERA
/*
bool esPalindromo(const string& palabra) {
    string inversa;
    invertir(palabra,inversa);
    return (palabra == inversa);
}

void invertir(const string& pal, string& inv) {
    inv = "";
    for (int i = 0; i < int(pal.size()); i++) {
        inv = pal[i] + inv;
    }
}
*/
