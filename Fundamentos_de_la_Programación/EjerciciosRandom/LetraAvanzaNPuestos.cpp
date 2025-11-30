#include <iostream>
#include <array>
#include <math.h>

using namespace std;

char avanzaNletras(char c, int n);

int main(){
    char c;
    int n;

    do
    {
        cout << "Introduzca una letra y el numero de puestos que va a avanzar: ";
        cin >> c >> n;
    } while (n < 0 && (c >= 'A' && c <= 'Z'));

    cout << "La letra " << c << " avanzada " << n << " puestos es " << avanzaNletras(c,n) << endl;
return 0;

}

char avanzaNletras(char c, int n)
{
    char res;
    int aux;

    if (int(c) + n > int('Z') )
    {
        res = char(int(c) + n - int('Z' - '@')); // COGE Y SUMA EL CHAR CON N EN INT Y
    }                          //  Z - @ = 26       LE RESTA LAS POSICIONES ENTRE Z Y A(25) Y LE RESTO 1 PARA QUE DEN LAS CUENTAS PORQUE SALE UNO DE MAS
    else{
        res = char(int(c) + n);
    }
    return res;
}
