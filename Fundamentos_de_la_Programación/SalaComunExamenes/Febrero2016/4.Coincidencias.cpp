#include <iostream>
#include <array>
#include <math.h>

using namespace std;

// Numero de caracteres de cadena2 en cadena1 en la misma posicion
// Y numero de caracteres de cadena2 en cadena1 en diferente posicion

bool estaLetra(string letrasLeidas, char letra)
{
    bool siEsta = false;

    for (int i = 0 ;i < int(letrasLeidas.size()) && !siEsta;i++ )
    {
        if (letra == letrasLeidas[i])
        {
            siEsta = true;
        }
    }
    return siEsta;
}

void intercambiar(string& c1, string& c2)
{
    string aux = c1;
    c1 = c2;
    c2 = aux;
}

void coincidencias(string& cadena1, string& cadena2, int& numMismaPos, int& numDiffPos)
{
    string letrasLeidas, letrasLeidas2;

    // Intercambiar si cadena1 es mas larga que cadena2
    if (cadena1.size() > cadena2.size())
    {
        intercambiar(cadena1,cadena2);
    }

    // Misma posicion
    cout << "Misma posicion" << endl;
    for (int i = 0;i < int(cadena1.size()) ;i++ )
    {
        if (cadena1[i] == cadena2[i] && !estaLetra(letrasLeidas,cadena1[i]))
        {
            numMismaPos++;
            letrasLeidas += cadena1[i];
            cout << cadena1[i] << endl;
        }
    }

    // Distinta posicion
    cout << "Distinta posicion" << endl;
    for (int i = 0;i < int(cadena1.size()) ;i++ )
    {
        for (int j = 0;j < int(cadena2.size()) ;j++ )
        {
            if (i != j && cadena1[i] == cadena2[j])
            {
                if (!estaLetra(letrasLeidas,cadena1[i]))
                {
                    numDiffPos++;
                    letrasLeidas += cadena1[i];
                    cout << cadena1[i] << endl;
                }
            }
        }
    }
}

int main(){
    string cadena1, cadena2;
    int n1 = 0, n2 = 0;

    cout << "Introduzca 2 cadenas de caracteres separadas por espacios: " << endl;
    cin >> cadena1 >> cadena2;
    coincidencias(cadena1, cadena2,n1,n2);
    cout << "Hay " << n1 << " caracteres de cadena2 en cadena1 en la misma posicion" << endl;
    cout << "Hay " << n2 << " caracteres de cadena2 en cadena1 en diferente posicion" << endl;
return 0;

}

/*

ARXMBA RZXMKJH
2 y 1

JAKZEF AOA
0 y 1

JAKZAF AA   ESTE CASO NO FUNCIONA
1 y 1

EA AA
1 y 0

*/

/*
void buscar_coincidencias_no_coincidencias(const string& p1, const string& p2, int& coincidencias, int&
no_coincidencias){
    // Bucle que recorra una de las cadenas SOLO con los indices VALIDOS
    int i = 0;
    string letras_coincidencias = "";

    coincidencias = 0;
    no_coincidencias = 0;
    while(i < int(p1.size()) && i < int(p2.size()))
    {
        if(p1[i] == p2[i] && !esta_letra(letras_coincidencias, p1[i]))
        {
            // Coincidencia en letra!!!
            coincidencias++;
            letras_coincidencias += p1[i];
        }
        else if(esta_letra(p1, p2[i]))
        {
             // No coincidencias
             no_coincidencias++;
        }
        i++;
    }
}
*/
