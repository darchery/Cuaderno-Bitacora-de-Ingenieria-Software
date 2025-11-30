#include <iostream>
#include <array>
#include <math.h>

/// HAY QUE CORREGIR ERRORES, SOBRE TODO RELACIONADOS CON EL EXECESO DE NUMEROS, OSEA CUANDO HAY MAS DE 10 NUMEROS,
/// SI ESTÁ LLENO LA COSA CAMBIA, NO SE PUEDE INSERTAR NUMEROS SI ESTA LLENO EL ARRAY
/// SIEMPRE QUE QUERAMOS HACER UNA INSERCION EN EL ARRAY DEBEMOS PREGUNTAR SI EL ARRAY ESTA LLENO

using namespace std;

const int MAX = 10;
typedef array<int, MAX> TNumeros;

struct TLista {
    TNumeros numeros; // enteros almacenados (consecutivos desde índice 0)
    int tam; // numero de enteros almacenados
    /// HABIA QUE USAR lista.tam AL RECIBIR LOS DATOS Y ASI TENERLO CONTROLADO PARA NO ALMACENAR MAS DE 10 DIGITOS
    /// SUSTITUIR tamVector por lista.tam
};

void leerNumeros(TLista& lista, int& pos)
{
    bool ceroEncontrado = false;
    cout << "Introduzca una secuencia de numeros enteros (0 para terminar y como maximo 10 numeros): ";
    for (int i = 0;i < MAX && !ceroEncontrado ;i++ )
    {
        cin >> lista.numeros[i];
        if (lista.numeros[i] == 0)
        {
            ceroEncontrado = true;
        }
        pos = i;
    }
}

bool ordenado(TLista& lista, int pos)
{
    bool orden = true;
    int numComp = lista.numeros[0];

    for (int i = 0; i < pos && orden ;i++ )
    {
        if (lista.numeros[i] < numComp )
        {
            orden = false;
        }
        numComp = lista.numeros[i];
    }
    return orden;
}


void borrar(TLista& lista, int& tamVector)
{
    int n;
    int index;

    cout << "Introduzca un numero entero a borrar del vector: ";
    cin >> n;

    cout << "El vector despues de borrar es: ";
    for (int i = 0;i < tamVector ;i++ )
    {
        index = i;
        if (lista.numeros[i] == n)
        {
            while (index < tamVector)
            {
                lista.numeros[index] = lista.numeros[index+1];
                index++;
            }
            tamVector--;
        }
        cout << lista.numeros[i] << " ";
    }
    cout << endl;
}
// 1 2 3 5 6 0 PASA A 1 2 3 0 5 6  Y LUEGO A 1 2 3 4 5 6
void insertarOrdenado(TLista& lista, int& tamVector) {
    int n;

    cout << "Introduzca un numero entero a insertar en el vector: ";
    cin >> n;

    // Incrementar el tamaño del vector
    tamVector++;

    // Encontrar la posición de inserción, Y DESPLAZAR SUS NUMEROS SUPERIORES A LA DERECHA
    int index = tamVector - 1;
    while (index >= 0 && lista.numeros[index - 1] >= n) {                                    /// AQUÍ LO QUE HACEMOS ES EMPEZAR DESPLAZANDO LOS NUMEROS A LA DERECHA SI ESTOS SON MAYORES QUE N
        //cout << "Casilla que vamos a cambiar: " << lista.numeros[index] << endl;            /// DE MANERA QUE EL ULTIMO NUMERO ES REEMPLAZADO POR EL ANTERIOR, PERO NO SE PIERDE NINGUNO PORQUE EL
        //cout << "Numero con el que vamos a cambiar: " << lista.numeros[index - 1] << endl;  /// EL PRIMER NUMERO QUE CAMBIAMOS ES EL 0, EL BUCLE PARA SI INDEX ES NEGATIVO O CUANDO EL NUMERO A CAMBIAR ES MENOR QUE N
        lista.numeros[index] = lista.numeros[index - 1];
        index--;
    }

    // Realizar la insercion
    lista.numeros[index] = n;  /// COMO PARA EN EL NUMERO JUSTO QUE ES MAYOR Y ESTE YA SE HA DESPLAZADO, SE CAMBIA POR N

    // Mostrar el vector resultante
    cout << "El vector despues de insertar es: ";
    for (int i = 0; i < tamVector; i++) {
        cout << lista.numeros[i] << " ";
    }
    cout << endl;
}

void insertarNoOrdenado(TLista& lista, int& tamVector)
{
    int n;

    cout << "Introduzca un numero entero a insertar en el vector: ";
    cin >> n;

    cout << "El vector despues de insertar es: " ;
    tamVector++;
    lista.numeros[tamVector - 1] = n;

    for (int i = 0;i < tamVector ;i++ )
    {
        cout << lista.numeros[i] << " ";
    }
}

int main(){
    TLista lista1;
    int tamVector;

    leerNumeros(lista1, tamVector);
    if (ordenado(lista1, tamVector))
    {
        cout << "VECTOR  ORDENADO" << endl;
        borrar(lista1, tamVector);
        insertarOrdenado(lista1, tamVector);
    }
    else
    {
        cout << "VECTOR NO ORDENADO" << endl;
        borrar(lista1, tamVector);     /// DA IGUAL SI ESTÁ ORDENADO O NO, YA QUE LO VAS A ELIMINAR
        insertarNoOrdenado(lista1, tamVector);
    }
return 0;

}

/*
void insertarOrdenado(TLista& lista, int& tamVector)
{
    /// 1. INCREMENTAR EL TAMAÑO DEL VECTOR; HECHO
    /// 2. MOVER LOS VALORES SUPERIORES A N A LAS CASILLAS SIGUIENTES HASTA RELLENAR EL HUECO CREADO
    /// 3. PONER EL HUECO INTERMEDIO A CERO HECHO
    /// 4. IMPRIMIR EL VECTOR Y CONVERTIR ESE VALORR A N HECHO
    int n;
    int index = 0;
    bool valorDesplazado = false;

    cout << "Introduzca un numero entero a insertar en el vector: ";
    cin >> n;

    cout << "El vector despues de insertar es:" ;
    tamVector++;
    cout << endl;

    /// LO UNICO QUE FALTA ES DETERMINAR LAS POSICIONES DESPUES DEL SEGUNDO NUMERO CAMBIADO
    for (int i = 0;i < tamVector ;i++ )
    {
        index = i;
        if (lista.numeros[i] > n)
        {
            lista.numeros[tamVector - 1] = lista.numeros[tamVector - 2];    // CON EL NUEVO HUECO, PASA EL ULTIMO VALOR AL HUECO PARA LLENA EL ARRAY
            while (index < tamVector - 1)
            {
                cout << "Desplazar ya: "  << lista.numeros[index] << endl;
                cout << "Desplazar ya + 1: " << lista.numeros[index + 1] << endl;

                lista.numeros[index + 1] = lista.numeros[index];
                index++;
            }
            if (!valorDesplazado)   // HACE QUE EL HUECO QUE QUEDA EN MEDIO AL DESPLAZAR LOS VALORES LATERALES SE IGUALE A CERO, PARA LUEGO CAMBIARLO  A N
            {
                lista.numeros[i] = 0;
                valorDesplazado = true;
            }
        }
    }

    for (int i = 0; i < tamVector ;i++ )
    {
        if (lista.numeros[i] == 0)
        {
            lista.numeros[i] = n;
        }
        cout << lista.numeros[i] << " ";
    }
}
*/
