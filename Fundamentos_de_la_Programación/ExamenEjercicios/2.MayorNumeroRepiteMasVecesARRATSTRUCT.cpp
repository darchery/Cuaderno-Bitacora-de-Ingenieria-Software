#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX_NUMS = 10;
typedef array<int, MAX_NUMS> TVector;
typedef array<int, MAX_NUMS> TFrecuencia;

struct TLista {
    TVector vec;
    TFrecuencia frec = {{}};
    int tamVec = 0;
};

void leerSecuenciaYCalcFrecuencia(TLista& lista)
{
    int num;            // Aqui se pondrá cada numero en el cin
    int ciclosRepes;    // Sirve para revisar los anteriores numeros para asi saber si esta repetido
    bool repetido;      // Es un punto de control para saber si se ha repetido o no
    int index = 0;      // Indice del vector

    cout << "Introduzca una secuencia de valores acaba en 0: ";
    cin >> num;

    if (num == 0)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        while (num != 0 && lista.tamVec < MAX_NUMS)
        {
            repetido = false;                           //Iniciamos cada ciclo para analizar un numero numero en false y restandole  uno al tamañao actual
            ciclosRepes = lista.tamVec - 1;             // esto ultimo es para que no analice incluyendo el numero actual , si no justo la posicion anterior


            if (index == 0) // Primera aparicion del primer numero
            {
                lista.vec[index] = num;
                lista.frec[index]++;
                lista.tamVec++;
                index++;
            }
            else
            {
                //  Analiza si el numero está repetido
                lista.vec[index] = num;
                while (ciclosRepes >= 0 && !repetido)   // Si los numeros detras de el son diferentes no es repetido
                {
                    if (lista.vec[ciclosRepes] == lista.vec[index]) // Si lo es se le sumará uno al arrat frec en la posicion encontrada
                    {
                        repetido = true;
                        lista.frec[ciclosRepes]++;  // Se suma uno al frec del numero original
                    }
                    ciclosRepes--;
                }

                // Si no lo está usa ese espacio para el num y prepara el siguiente hueco
                if (!repetido)
                {
                    //lista.vec[index] = num;
                    lista.frec[index]++;
                    lista.tamVec++;
                    index++;
                }
            }
            cin >> num;
        }
    }



    // Muestra la frecuencia de cada numero
    /*for (int i = 0;i <lista.tamVec ;i++ )
    {
        cout << lista.vec[i] << ": " << lista.frec[i] << endl;
    }*/
}

int numeroMayorConMenorFrecuencia(TLista& lista)
{
    int res = lista.frec[0];
    int num = lista.vec[0];

    for (int i = 1;i < lista.tamVec;i++ )
    {
        if (res > lista.frec[i] && num < lista.vec[i])
        {
            num = lista.vec[i];
        }
    }
    return num;
}

// 2 5 10 22 2 5 3 3 4 10 23 25 1 3 2 6 7 0
int main(){
    TLista lista1;

    leerSecuenciaYCalcFrecuencia(lista1);
    cout << "El numero mayor con menor frecuencia es: " << numeroMayorConMenorFrecuencia(lista1) << endl;
return 0;

}
