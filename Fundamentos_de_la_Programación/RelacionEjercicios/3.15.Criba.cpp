#include <iostream>
#include <array>
#include <math.h>

/// NO ESTO NO
/*
LA IDEA ES RECORRER EL ARRAY , Y CUANDO ENCONTREMOS UN NUMERO QUE NO HAYA SIDO TACHADO(BOOL = FALSE) TRATARLO Y CONTAR SUS APARCIONES
SI AL FINAL DEL BUCLE E SIGUAL A X, LO GUARDAMOS EN lista2 Y PONEMOS TACHADO A TRUU
*/

using namespace std;

int const MAX = 10;
typedef array<int, MAX> TArray;

struct TLista {
    TArray vec;
    int tamVector;
};

void leerNumsYX(TLista& lista , int& x)
{
    do
    {
        cout << "Cuantos numeros desea introducir (maximo " << MAX << " ): ";
        cin >> lista.tamVector;
    } while (lista.tamVector <= 0 || lista.tamVector > MAX);

    cout << endl;

    cout << "Introduzca " << lista.tamVector << " numeros: ";
    for (int i = 0;i < lista.tamVector ;i++ )
    {
        cin >> lista.vec[i];
    }

    cout << endl;

    do
    {
        cout << "Introduzca el numero de repeticiones para realizar la criba: ";
        cin >> x;
    } while (x < 0);
}

/*
Aquí usaremos lo mejor que se me ocurre, para tachar el numero (Y NO POSICIONES), normalmente
asignamos un valor por ejemplo -1 para marcalo, pero esta vez no podemos ya que el usario puede
usar valores negativos, asi que usaremos como tope el minimo - 1
*/

TLista criba(TLista& lista, int& x)
{
    TLista listaCribada;
    int index = 0;
    int repeticiones = 0;
    int topeMin = lista.vec[0];

    // CALCULO TOPE
    for (int i = 1;i < lista.tamVector ;i++ )
    {
        if (topeMin > lista.vec[i])
        {
            topeMin = lista.vec[i];
        }
    }
    topeMin--;

    // CRIBAR LISTA
    int numeroActual;   /// ESTE ERA EL ERROR, CUANDO VAS A USAR MUCHAS VECES UN VALOR DE UN VECTOR ESPECIFICO
                        /// LO MEJOR ES GUARDARLO EN UNA VARIABLE
    for (int i = 0;i < lista.tamVector ;i++ )
    {
        numeroActual = lista.vec[i];
        //cout << "Numero a la criba: " << numeroActual << endl;

        if (numeroActual != topeMin)
        {
            for (int j = 0;j < lista.tamVector ;j++ )
            {
                if (numeroActual == lista.vec[j])
                {
                    repeticiones++;
                    lista.vec[j] = topeMin;
                    //cout << "Repeticiones de " << numeroActual << ": " << repeticiones << endl;
                    //cout << endl;
                }
            }
        }
        if (repeticiones == x)
        {
            //cout << "Cribado " << index + 1 << ": " << numeroActual << endl;
            listaCribada.vec[index] = numeroActual;
            index++;
        }
        lista.vec[i] = topeMin;
        repeticiones = 0;
        listaCribada.tamVector = index;
    }
    return listaCribada;
}

void escribirListaCribada(TLista& lista)
{
    cout << endl;
    cout << "La lista cribada es: ";
    for (int i = 0;i < lista.tamVector;i++ )
    {
        cout << lista.vec[i] << " ";
    }
}

int main(){
    TLista lista1;
    TLista lista2;
    int x;

    leerNumsYX(lista1,x);
    lista2 = criba(lista1, x);
   escribirListaCribada(lista2);
return 0;

}
