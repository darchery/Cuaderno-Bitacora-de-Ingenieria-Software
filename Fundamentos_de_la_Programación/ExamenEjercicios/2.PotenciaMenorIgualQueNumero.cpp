#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int tope;
    int numero = 1;
    int potencia ;
    int resultado;
    bool encontrado = false;

    cout << "Introduzca el tope y la potencia separados de un espacio: "; //RECOGE LOS DATOS
    cin >> tope >> potencia;


    if ( tope <= 0 || potencia <= 0 )
    {
        cout << "Introduzca numeros mayores que cero..." << endl;
    }
    else
    {
        resultado = pow(numero,potencia);                   // CREA EL PRIMER RESULTADO QUE SERIA EN EL INPUT 125 3, 1^3 = 3
        while (resultado <= tope && encontrado == false)    // MIENTRAS EL RES SEA MENOR O IGUAL AL TOPE, EN EL INPUT 125 O encontrado SIGA SIENDO FALSE
        {                                                   // EN EL BUCLE SE CHECKEA SI EL RES ES IGUAL A TOPE SI LO ENCUENTRA AL ACABAR EL CICLO CORTA EL BUCLE
            if (resultado == tope)
            {
                encontrado = true;
            }
            numero++;                                       // CUANDO SALE DEL IF SUMA UNO AL NUMERO, Y QUEDA EJ: DE 1^3 PASA A 2^3
            resultado = pow(numero,potencia);               // Y CREA EL SIGUIENTE RESULTADO QUE SERAS 2^3 = 8
        }

        cout << "El resultado es: " << numero - 1 << endl;    // CUANDO EL BUCLE ACABA LE RESTA UNO YA QUE POR LA NATURALEZA DEL BUCLE NO PARA JUSTO AL SER TRUE EL BOOL
                                                          // Y TAMPOCO PARA JUSTO CUANDO ES YA MAYOR QUE EL TOPE
    }


return 0;

}
