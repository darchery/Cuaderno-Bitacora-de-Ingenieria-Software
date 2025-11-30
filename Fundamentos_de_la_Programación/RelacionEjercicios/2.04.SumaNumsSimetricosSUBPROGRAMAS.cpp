#include <iostream>
#include <array>
#include <math.h>

using namespace std;
// SUMAR NUMDIGIT

int main(){
    int N;
    int numDigt = 1;
    int iniDigt = 0;
    int res = 0;
    int sum1;
    int sum2;
    bool sum2Suma = false;
    bool numeroDigitosImpares = false;

    cout << "Introduzca un numero y se sumaran los simetricos: ";
    cin >> N;
    int fakeN = N;

    if (N < 0)
    {
        cout << "Introduzca un numero mayor que cero" << endl;
    }
        else
        {
            while (fakeN >= 10) //CUENTA NUMERO DE DIGITOS
            {
                fakeN /= 10;
                numDigt++;
            }

            int fakeN1 = N; // REINICIA LOS NUMEROS
            int fakeN2 = N;

            while (numDigt > iniDigt && numeroDigitosImpares == false)  // CONTADOR DEL NUMERO DE DIGITOS  Y CUANDO LOS NUMERO SON IMPARES EL DIGITO DE EN MEDIO NO LO IMPRIMA
            {
                sum1 = fakeN1%10; // ESCOGE LOS PRIMEROS NUMEROS DEL NUMERO
                fakeN1 /= 10;


                while (fakeN2 >= 10)    // ELIGE LOS NUMEROS FINALES DEL NUMERO
                {
                    fakeN2 /= 10;
                    sum2 = fakeN2%10;
                }

                cout << "Suma 2: " << sum2 << endl;
                cout << "Suma 1: " << sum1 << endl;

                res = sum1 + sum2;
                cout << "Resultado: " << res << endl;


                cout << "Numero digitos: " << numDigt << endl;
                cout << "Digit inicial: " << iniDigt << endl;

                numDigt--;  // DISMINUYE Y AUMENTA EL NUMERO DE DIGITOS
                iniDigt++;

               // cout << N << endl << "-" <<endl<< sum2*pow(10,numDigt) << endl;
                fakeN2 = N - sum2*pow(10,numDigt); // RESTA AL NUMERO ORIGINAL EL PRIMER DIGITO

                if ( numDigt == iniDigt + 1) // CUANDO TIENE NUMERO DIGITOS IMPARES CORTA EL BUCLE
                {
                    numeroDigitosImpares = true;
                }

                //cout << "N: " << N << endl;

                N = fakeN2; // ESTABLECE EN N EL NUEVO NUMERO RESTANDO EL DIGITO ANTERIOR
                sum1 = 0; // RESTAURA LOS NUMEROS QUE VAMOS A SUMAR
                sum2 = 0;

                //cout << "Siguiente NUMERO: " << fakeN2 << endl;
            }
        }


return 0;

}

