#include <iostream>
#include <array>

using namespace std;

const int TAM = 10;

typedef array <int , TAM > TArray ;

void strictSmallest(TArray secuencia, bool& encontrado, int& valor);
bool seRepite(TArray secuencia, int valor);

int main ()
{
    TArray a1 = {{4 , 7 , 5 , 3 , 5 , 7 , 9 , 32 , 45 , 8}};
    TArray a2 = {{4 , 7 , 5 , 3 , 5 , 7 , 3 , 32 , 45 , 8}};
    TArray a3 = {{4 , 7 , 5 , 3 , 5 , 7 , 3 , 32 , 2 , 8}};

    bool found;
    int value;

    strictSmallest (a1 , found , value );
    if ( found == true )
    {
        cout << "The strict smallest value of first array is: " << value << endl ;
    }
        else cout << "The first array has not strict smallest " << endl ;

    strictSmallest (a2 , found , value );
    if ( found == true)
    {
        cout << "The strict smallest value of second array is: " << value << endl ;
    }
        else cout << "The second array has not strict smallest " << endl ;

    strictSmallest (a3 , found , value ) ;
    if ( found == true)
    {
        cout << "The strict smallest value of third array is: " << value << endl ;
    }
        else cout << "The third array has not strict smallest " << endl ;

return 0;
}

void strictSmallest(TArray secuencia, bool& encontrado, int& valor)
{
    valor = secuencia[0];

    for (int i = 1; i < TAM ; i++ ) // COMPRUEBA SI EL VALOR INICIAL ES EL MENOR DE TODA LA LISTA Y SI NO LO ES LO ACTUALIZA
    {
        if (secuencia[i] < valor)
        {
            valor = secuencia[i];
        }
    }

    if((seRepite(secuencia,valor))== true) // LLAMA A SE REPITE
    {
        encontrado = false;
    }
    else{
        encontrado = true;
    }
}

bool seRepite(TArray secuencia, int valor)
{
    bool estrictMin = false;
    int cntSec = 0;
    int cntRepetido = 0;

    while (cntSec < TAM && !estrictMin) // AQUI REELEEMOS EL ARRAY TENIENDO YA EL MENOR ELEGIDO
    {                                   // SI AL RELEER EL ARRAY EL VALOR ES REPETIDO SE LE SUMA UNO A LA VARIABLES cntRepetido
        if (secuencia[cntSec] == valor) // POR LO TANTO SI cntRepetido SE MANTIENE (EN CERO) ES MENOR ESTRICTO Y SUELTA EL FALSE
        {                               // POR LO TANTO NO SE REPITE Y SERÍA UN ESTRICTO MINIMO
            cntRepetido++;
        }

        if (cntRepetido > 1)
        {
            estrictMin = true;
        }
        cntSec++;
    }
    return estrictMin;
}









/*
valor = secuencia[0];
    bool encontrado = true;

    for (int i = 0; i < TAM ; i++ )
    {
        cout <<  "Numero " << i << ": " << secuencia[i] << endl;

        if (secuencia[i] < valor )
        {
            valor = secuencia[i];
            cout << "Menor: "<<valor << endl;
        }
        else if (secuencia[i] == valor )
        {
            encontrado = false;
        }
    }

    return encontrado;
*/
