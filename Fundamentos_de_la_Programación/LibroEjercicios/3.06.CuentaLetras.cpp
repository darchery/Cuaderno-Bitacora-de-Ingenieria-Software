#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int TAMANO_MAX = 100;

void cuentaLetrasPalabra(char frase[]);

int main(){
    char texto[TAMANO_MAX];

    cout << "Introduce el texto e imprimiré las longitud de cada palabra: ";
    cin.getline(texto,TAMANO_MAX,'.');

    cuentaLetrasPalabra(texto);

return 0;

}
/*
 Soy y sere a todos definible mi nombre tengo que daros cociente diametral siempre inmedible soy de los redondos aros.

 3,1415926535897932384
 32526103764691081043
*/

void cuentaLetrasPalabra(char frase[])
{

    int cntLetras=0;
    int cntPunto=0;

    for (int i = 0; i < TAMANO_MAX ; i++ )
    {
        if (frase[i]==' ' && cntPunto==0)
        {
            cout << cntLetras;
            cntLetras=0;
        }
            else if (frase[i]==' .')
            {
                cntPunto++;
            }
                else{
                    cntLetras++;
                }
    }
}
