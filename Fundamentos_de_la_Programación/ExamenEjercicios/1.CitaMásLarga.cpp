#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void leerCadena(char& cadena)
{
    cout << "Introduzca una secuencia de caracteres acabada en punto: ";
    cin.get(cadena);
}

void analizarRes(char& cadena)
{
    int cntCita = 0;  // Si es par quiere decir que hay citas cerradas, si es impar no las hay
    int longitud = 0;
    int longAnterior = longitud;
    bool empieza = false;

    while (cadena != '.')
    {
        if (cadena == '"' && (cntCita == 0 || cntCita % 2 == 0) )
        {
            //cout << "Empieza cadena " << cntCita  << endl;
            cntCita++;
            empieza = true;
        }

        else if (cadena == '"' && empieza)
        {
            //cout << "Acaba cadena " << cntCita << endl;
            if (longitud > longAnterior)
            {
                longAnterior = longitud;
            }
            empieza = false;
            longitud = 0;
            cntCita++;
        }

        else if (empieza && cntCita % 2 != 0)
        {
            longitud++;
            //cout << "Longitud actual cita " <<  cntCita << ": " << longitud << endl;
        }

        cin >> cadena;
    }

    // Posibles resultados
    if (cntCita == 0)
    {
        cout << "El texto no tiene citas." << endl;
    }
    else if (cntCita % 2 != 0)
    {
        cout << "ERROR. Hay una cita inacabada." << endl;
    }
    else
    {
        cout << "La cita mas larga tiene " << longAnterior << " caracteres." << endl;
    }
}

int main(){
    char cadena;

    leerCadena(cadena);
    analizarRes(cadena);
return 0;

}
