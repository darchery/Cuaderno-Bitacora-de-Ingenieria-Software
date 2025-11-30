#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int const LETRAS = 26;

struct TDatos {
    int ultPos;
    int mayorDis;
    bool repetido;
};

typedef array<TDatos, LETRAS> TArray;

void escribirMayor(TArray& letras)
{
    for (int i = 0;i < LETRAS ;i++ )
    {
        if (letras[i].repetido)
        {
            cout << "Distancia mayor de " << char(i + 'A') << " es: " << letras[i].mayorDis << endl;
        }
    }
}

void calcMayorDisControlRepes(TArray& letras)
{
    char c;
    int pos = 1, dis;

    cout << "Introduzca secuencia de mayúsculas (punto para finalizar): ";
    cin.get(c);

    while (c != '.')
    {
        if (c >= 'A' && c <= 'Z')
        {
            if (letras[c-'A'].ultPos == 0)   // PRIMERA APARCION
            {
                letras[c-'A'].ultPos = pos; // COMO YA HA APARECIDO LO MARCAMOS DE MANERA QUE SE GUARDA LA PRIMERA A APARCION PARA USAR O NO MAS ADELANTE
            }
            else    // DEMAS APARCIONES, AQUÍ SE GESTIONA, LAS APARICIONES, MAYORES DISTANCIA, Y LA REPETICION DE LAS LETRAS
            {
                letras[c-'A'].repetido = true;  // ASI LO MARCAMOS EN LA 2, N-ENESIMA APARCION PARA SABER QUE ES REPETIDO Y ASI ANALIZARLO
                dis = pos - letras[c - 'A'].ultPos - 1;  // CALCULAMOS LA DIS DE ESTA MANERA, EJ: LUCASL, 5 - 0 - 1 = 4, ES EL ESPACIO ENTRE LA PRIMERA L Y LA ULTIMA
                letras[c-'A'].ultPos = pos;     // DE ESTA MANERA GUARDAMOS ESTA APARICION MARCANDO SU ULTIMA POSICION CON LA POSICION ACTUAL
                if (dis > letras[c-'A'].mayorDis)   // POR ULTIMO SI ESTA DISTANCIA CALCULADA ES MAYOR QUE LA ANTERIOR SE REEMPLAZA POR LA MAYOR
                {
                    letras[c-'A'].mayorDis = dis;
                }
            }
        }
        pos++;
        cin.get(c);
    }
}

int main(){
    TArray letras = {{}};   // TODAS LAS VARIABLES A 0

    calcMayorDisControlRepes(letras);
    escribirMayor(letras);
return 0;

}
