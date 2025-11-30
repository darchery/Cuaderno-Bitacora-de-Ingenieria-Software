#include <iostream>
#include <array>
#include <math.h>

/*El alumnado de informática desea celebrar una comida un día del presente mes en el que
puedan acudir todos. Se pide realizar un algoritmo que recoja de cada estudiante los días que le
vendría bien ir a la comida, e imprima los días concordantes para todo el alumnado o una
indicación de que no hay. Los datos se introducirán por teclado. Primero se introducirá el
número de estudiantes que intervienen. Después, por cada estudiante se introducirá una única
línea con los números de los días libres separados por espacios (un 0 para terminar).*/

using namespace std;

int const N = 32;
typedef array<int,N> TDias;

void sumarFrec(TDias& frec)
{
    int dia;
    cin >> dia;

    while (dia != 0)
    {
        if (dia >= 1 && dia <= N - 1)
        {
            frec[dia]++;
        }
        cin >> dia;
    }
}

void leerEst(TDias& frec, int& numAlum)
{
    cout << "Numero de estudiantes a introducir: ";
    cin >> numAlum;

    for (int i = 0;i < numAlum ;i++ )
    {
        cout << "Introduzca los dias preferidos por estudiante " << i+1 << " (introduzca un 0 para terminar): ";
        sumarFrec(frec);
    }
}

void imprimirComunes(const TDias frec, int numAlum)
{
    bool diasCom = false;
    cout << "Dias preferidos: ";
    for (int i = 0;i < N && !diasCom;i++ )
    {
        if (frec[i] == numAlum)
        {
            cout << i << " ";
            diasCom = true;
        }
    }
    if (!diasCom)
    {
        cout << "NO hay dias comunes" << endl;
    }
}

/// VAMOS A TENER UN ARRAY DE 32, DE 0 A 31 DIAS DEL MES, Y VAMOS LEER EL NUMERO DE ALUMNOS QUE VAN A PARTICIPAR
/// DESPUES ANALIZAREMOS LOS ARRAYS Y SI POR EJEMPLO ES 2 23 27, LE SUMAREMOS UNO EN EL ARRAY EN LAS POSICIONES 2 23 Y 27
/// AL ACABAR DE REALIZAR ESTE PROCESO, SI ALGUNO DE ESTAS FRECUENCIA ES IGUAL AL NUMERO DE ALUMNOS ESO QUIERE DECIR  QUE ES UN DIA FAVORITO
int main(){
    TDias frec = {{}};
    int numAlum;

    leerEst(frec, numAlum);
    imprimirComunes(frec, numAlum);
return 0;

}

/*
void encontarDiasComunes(int TDias[][100], int N)
{
    //int diasComunes[100] = {0};
    bool diasEncontrados = false;
    //int index = 0;
    //int day;

    for (int i = 0;i < N ;i++ )
    {
        for (int j = 0;TDias[i][j] != 0 ;j++ )
        {
            day = TDias[i][j];
            diasComunes[index] = day;
            index++;
        }
    }

    cout << "Dias encontrados: ";
    for (size_t i = 0; i < 100 ;i++ )
    {
        if ()
        {
            cout << diasComunes[i] << " ";
            diasEncontrados = true;
        }
    }

    if (!diasEncontrados)
    {
        cout << "No hay dias preferidos" << endl;
    }
}

int main(){
    int N;
    leerEstudiantes(N);
    int TDias[100][100] = {{0}};

    for (int i = 0;i < N ;i++ )
    {
        leerNotas(TDias[i], i);
        cout << endl;
    }
    encontarDiasComunes(TDias,N);
return 0;

}
*/
/// PRIMERA IDEA QUE SE ME VIENE ES COMPARAR TODAS LAS CADENAS ENTRE SI, PERO NO SERÍA LO MEJOR
// SERIA COMPARANDO , EJ: 3, LA 1 CON LA 2 Y 3, Y LA 2 CON LA 3, Y SI ALGUNA TIENE ALGUN NUMERO IGUAL EN LAS 3 BIEN
// QUIZÁ LO MEJOR ES COMPAR LA 1  CON LA 2 Y LA 3 A LA VEZ, PERO NO

/// LO TENGO: INICIAREMOS LA BUSQUEDA CON EL FOR EN LA CADENA 1 CON LA CADENA 2, SI ENCUENTRA UN ELEMENTO IGUAL,VA A DEJAR DE ANALIZAR LA CADENA 2
/// Y SALTARÁ A LA CADENA 3 BUSCANDO ESE NUMERO FINAL QUE NECESITAMOS PARA SER UN DIA PREFERIDO, Y SI LO ENCUENRTA EL BOOL SE DECLARA FALSE
/// CASO CONTRARIO ES QUE COMPARO LA CADENA 1 CON LA 2 Y SI NO HAY NINGUNO EN COMUN ESO QUIERE DECIR QUE NO HABRÁ DIA PREFERIDO, ENTONCES SE PARARA EL BUCLE
/// OTRO CASO SERIA QUE ESTAMOS EN LA 1 SALTA A LA 2 LUEGO A LA 3 y SI EN LA 3 NO ENCUENTRA NINGUNO TAMBIEN CERRARA EL BUCLE
/// LO CERRARA SI LOS DATOS DE LA PRIMERA CADENA SE ACABARON O DE LA SEGUNDO
