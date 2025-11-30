#include <iostream>
#include <array>
#include <math.h>

using namespace std;

/*
NECESITO QUE EL USUARIO INTRODUZCA 2 NUMEROS DE IDENTIFICACIÓN Y A PARTIR ESTOS 2 ME DE LA DIFERENCIA ENTRE ELLOS
UNO SERA MI NUMERO IDENTIFICATIVO(NIVEL) Y EL OTRO NUMERO IDENTIFICATIVO(NIVEL) SERÁ EL DE LA OTRA PERSONA.
ESTABLECER NIVELES.

CADA PERSONA CONTROLA N+1 PERSONA
A CADA PERSONA DEL NIVEL N+1 LA VIGILA UNA PERSONA DEL NIVEL N
NUMERO DE PERSONAS DE CAD NIVEL
*/

int distanciaEntreNiveles(int numIden1, int numIden2);

int main(){
    int n1, n2;

    cout << "Introduzca su numero identificativo y el del otro(separados de un espacio):  ";
    cin >> n1 >> n2;

    distanciaEntreNiveles(n1,n2);

return 0;

}

int distanciaEntreNiveles(int numIden1, int numIden2)
{
    int numPersonasNivelMayor = 1;
    int numPersonasNivelMenor = 1;

    for (int i = 1; i <= numIden1  ; i++ )
    {
        numPersonasNivelMayor *= (i*i -1);
    }

    cout << numPersonasNivelMayor << endl;

}
