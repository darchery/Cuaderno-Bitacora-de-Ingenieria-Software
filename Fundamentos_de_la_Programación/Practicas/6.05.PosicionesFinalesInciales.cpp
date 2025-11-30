#include <iostream>
#include <array>

using namespace std;

const int TAM = 10;
typedef array<int, TAM> TVector;


void leer(TVector& v)
{
    cout << "Introduzca la sucesion de " << TAM << " naturales: ";
    for (int i = 0;i < TAM ;i++ )
    {
        cin >> v[i];
        while (v[i] < 0) // robusto
        {
            cin >> v[i];
        }
    }
}
/// ESTE ESQUEMA ES LA CLAVE, PEQUEÑOS PASOS SIMPLES QUE LLEVAN A LA RESOLUCION DE UN PROBLEMA MAS COMPLEJO
/* 1. Usaremos un while para recorrer los maximos
    1.1. Sacaremos el maximo.
    1.2. Luego recorreremos este array en busca de repeticiones.
    1.3. Despues de contar las repeticiones recorreremos de nuevo el array, y ahora si contando y coutendo las posiciones que aparecen + 1
    1.4. Despues de analizar este máximo lo pondremos por ejemplo a -1
    1.5. Sumaremos las repeticiones a un counter que controlara todo el programa
*/

int calcMaximo(const TVector& v)    /// CALCULAMOS EL MAXIMO DEL ARRAY(POSTERIORMENTE LO BORRAREMOS PARA QUE NO SEA EL MISMO)
{
    int maximo = v[0];

    for (int i = 1;i < TAM ;i++ )
    {
        if (maximo < v[i])
        {
            maximo = v[i];
        }
    }
    return maximo;
}

int calcApariciones(const TVector& v, int maximo)   /// CONTAMOS SUS APARICIONES
{
    int apariciones = 0;
    for (int i = 0;i < TAM ;i++ )
    {
        if (maximo == v[i])
        {
            apariciones++;
        }
    }
    return apariciones;
}

void escribirResulatodosCalcPosicion(TVector& v, int maximo, int apariciones)
{
    cout << maximo << " aparece " << apariciones  << " ";   /// AQUÍ LAS COUTEAMOS
    if (apariciones > 1)
    {
        cout << " veces, en posiciones ";
    }
    else
    {
        cout << " vez, en la posicion ";
    }

    for (int i = 0;i < TAM ;i++ )   /// Y AQUÍ OCURRE LA PARTE DE LAS POSICIONES Y DE BORRAR EL ELEMENTO
    {
        if (v[i] == maximo)
        {
            cout << i + 1 << " ";
            v[i] = -1;
        }
    }
}

int main()
{
    TVector v1;
    int numMaximos = 0; // ESTE COUNTER HARÁ QUE SE ANALICEN EXACTAMEN COMO MAXIMO 10 NUMEROS DIFRENTES, MEDIANTE SUMANDO
    int maximo, apariciones;

    leer(v1);
    while (numMaximos < TAM)
    {
        maximo = calcMaximo(v1);
        apariciones = calcApariciones(v1, maximo);
        escribirResulatodosCalcPosicion(v1, maximo, apariciones);
        numMaximos += apariciones;      /// ESTA PARTE HACE QUE EL PROGRAMA FUNCIONE, SIN ESTO NO CUENTA LAS APARICIONES Y POR LO TANTO LAS VUELTAS QUE TIENE QUE DAR
        cout << endl;
    }
    return 0;
}

