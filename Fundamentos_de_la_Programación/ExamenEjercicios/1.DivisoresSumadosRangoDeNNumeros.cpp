#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int limInf, limSup;
    int div = 1;
    int sum = 0;

    cout << "Introduzca el rango  del numero inferior y superior para sumar todos sus divisores: "; // ESTABLECE EL RANGO DE VALORES
    cin >> limInf >> limSup;

    if (limInf <= 0 || limSup <= 0)
    {
        cout << "Introduzca numeros mayores que cero..." << endl;
    }
    else
    {
        while (limInf <= limSup)                            // EL BUCLE SE EJECUTA SIEMPRE Y CUANDO INF SEA MENOR O IGUAL PARA RECORRER
        {                                                   // EN CASO DE INPUT 1 10 , LOS 10 VALORES DESE 1 A 10
            while (limInf >= div)                           // EN ESTE CASO ESTE BUCLE SE ENCARGA DE IR DIVIENDO LOS NUMERO DEL RANGO
            {                                               // ENTRE LOS DIVISORES , CUANDO SU RESTO ES IGUAL A 0 LO SUMA
                if (limInf%div == 0)                        // Y PASA ALA SIGUIENTE DIVISOR , Y CUANDO EL DIVISOR SEA MAYOR AL NUMERO CORTA EL BUCLE Y SE REINICIA
                {
                    sum += div;
                }
                div++;
            }
            cout << limInf << ": " << sum << endl;          // AQUI SE COUTEAN LOS VALORES DEL RANGO Y LAS SUMAS DE SUS DIVISORES INDIVIDUALMENTE
            div = 1;                                        // AQUI COMO YA ACABAMOS DE SACAR SUS DIVISORES, ESTABLECEMOS A SUS VALORES INCICALES
            sum = 0;                                        // LAS VARIABLES, DIV = 1 Y SUM = 0 Y PASAMOS POR FIN AL SIGUIENTE NUMERO DEL RANGO
            limInf++;
        }
    }

return 0;

}

// SUPUESTA VERSION DEL MAIN MEJORADA
/*
 int limInf, limSup;
    int div = 1;
    int sum = 0;

    cout << "Introduzca el rango  del numero inferior y superior para sumar todos sus divisores: "; // ESTABLECE EL RANGO DE VALORES
    cin >> limInf >> limSup;

    if (limInf <= 0 || limSup <= 0)
    {
        cout << "Introduzca numeros mayores que cero..." << endl;
    }
    else
    {
        for (int i = limInf; i <= limSup ;i++ )
        {
            while (limInf >= div)
            {
                if (limInf%div == 0)
                {
                    sum += div;
                }
                div++;
            }
            cout << limInf << ": " << sum << endl;
            div = 1;
            sum = 0;
            limInf++;
        }
    }

return 0;
*/
