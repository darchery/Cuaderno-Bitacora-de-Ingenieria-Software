/*
To read the chars use:

    char c;
    c = cin.get(); // it reads spaces too
    while (c != ’.’ )
    {
    // your code goes here
    c = cin.get();
    }

better than cin >> c; since the latter form skips over spaces, tabs and newlines: that is, it doesn’t read them.
Make a program that reads chars until a dot (’.’) is entered. Then the program will show the number of vowels,
upper letters and non letter read.
*/

#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    char c;
    int cntVocales = 0;
    int cntMayusculas = 0;
    int cntEspacios = 0;
    int cntCaracteres = 0;
    int CaracteresNoLeidos =0;

    cout << "Introduce la cadena de caracteres terminada en punto: ";
    cin.get(c);

    while (c != '.')
    {
        if (c  >= 'A' && c <= 'Z')
        {
            if (c =='a' || c =='A' || c =='e' ||c =='E' ||c =='i' ||c =='I' || c =='o' ||c =='O' || c =='u' || c =='U')
            {
               cntVocales++;
            }
            cntMayusculas++;
        }
        else if (c ==' ')
        {
            cntEspacios++;
        }
        else if (c =='a' || c =='A' || c =='e' ||c =='E' ||c =='i' ||c =='I' || c =='o' ||c =='O' || c =='u' || c =='U' )
        {
            cntVocales++;
        }
        else{
            CaracteresNoLeidos++;
        }
        cntCaracteres++;
        cin.get(c);
    }
    cout << "CARACTERES: " << cntCaracteres << endl;
    cout << "Vocales: " << cntVocales << endl;
    cout << "Mayusculas: " << cntMayusculas << endl;
    cout << "Caracteres no leidos: " << CaracteresNoLeidos << endl;
    cout << "Espacios: " << cntEspacios << endl;

return 0;

}
