#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void abSecuencia(char sec);

int main(){
    char c;

    cout << "Introduzca una frase acabada en punto: ";
    cin.get(c);
    abSecuencia(c);
return 0;

}

void abSecuencia(char sec)
{
    bool encontrado = false;

    while (sec != '.' && encontrado == false)
    {

        if (sec == 'a')
        {
            cin.get(sec);
            if (sec == 'b')
            {
                encontrado = true;
            }
        }
        cin.get(sec);
    }
    if (encontrado == false)
    {
        cout << "AB NO encontrado" << endl;
    }
    else
    {
       cout << "AB encontrado" << endl;
    }
}
