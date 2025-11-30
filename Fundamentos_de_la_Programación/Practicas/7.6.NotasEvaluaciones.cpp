#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int N_EVALUACIONES = 3;
const int MAX_ALUMNOS = 20;

struct TDatos {
    string nombre;
    double n1, n2, n3;
};

typedef array<TDatos, MAX_ALUMNOS> TAlumnos;

struct TLista {
    TAlumnos alumnos;
    double media1, media2, media3;
    int N_alumnos;
};

void leerDatos(TLista& lista)
{
    do
    {
        cout << "Introduce el numero de alumnos: ";
        cin >> lista.N_alumnos;
    } while (lista.N_alumnos <= 0 || lista.N_alumnos > 20);

    for (int i = 0;i < lista.N_alumnos ;i++ )
    {
        cout << "Introduce el nombre y " << N_EVALUACIONES <<  " notas: ";
        cin >> lista.alumnos[i].nombre >> lista.alumnos[i].n1 >> lista.alumnos[i].n2 >> lista.alumnos[i].n3;
    }
}

void mediaAsignatura(TLista& lista)
{
    double suma1 = 0, suma2 = 0, suma3 = 0;

    for (int i = 0;i < lista.N_alumnos ;i++)
    {
        suma1 += lista.alumnos[i].n1;
    }
    lista.media1 = suma1/lista.N_alumnos;

    for (int i = 0;i < lista.N_alumnos ;i++)
    {
        suma2 += lista.alumnos[i].n2;
    }
    lista.media2 = suma2/lista.N_alumnos;

    for (int i = 0;i < lista.N_alumnos ;i++)
    {
        suma3 += lista.alumnos[i].n3;
    }
    lista.media3 = suma1/lista.N_alumnos;
}

void analizarNotas(TLista& lista)
{
    int numGuiones = (N_EVALUACIONES + 1) * 13;
    mediaAsignatura(lista);

    // Cabecera
    cout << "Alumnos       ";
    for (int i = 0;i < N_EVALUACIONES ;i++ )
    {
        cout << "Nota - " << i + 1 << "       ";
    }
    cout << endl;
    // Guiones
    for (int i = 0;i < numGuiones ;i++ )
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0;i < lista.N_alumnos ;i++ )
    {
        cout << lista.alumnos[i].nombre << "       ";
        if (lista.media1 < lista.alumnos[i].n1)
        {
            cout << "Aprobado      ";
        }
        else
        {
            cout << "Suspenso      ";
        }
        if (lista.media2 < lista.alumnos[i].n2)
        {
            cout << "Aprobado      ";
        }
        else
        {
            cout << "Suspenso      ";
        }
        if (lista.media3 < lista.alumnos[i].n3) // Este ultimo el de Dani no da 6.3 5.2 6.5 , sale el ultimo Aprobado cuando deberia ser falso
        {
            cout << "Aprobado      ";
        }
        else
        {
            cout << "Suspenso      ";
        }
        cout << endl;
    }
}

/*
Lucas 5.3 3.2 8.5
Marta 2.3 5.2 7.5
Dani 6.3 5.2 6.5
*/

int main(){
    TLista lista1;

    leerDatos(lista1);
    analizarNotas(lista1);
return 0;

}

/*
double mediaAsignatura(const TLista& lista)
{
    double suma = 0;

    for (int i = 0;i < lista.N_alumnos ;i++)
    {
        suma += lista.alumnos[0].n1
    }
    return suma/lista.N_alumnos;
}

void analizarNotas(const TLista& lista)
{
    int numGuiones = (lista.N_alumnos + 1) * 13;
    lista.media1 = mediaAsignatura(lista);
    lista.media2 = mediaAsignatura(lista);
    lista.media3 = mediaAsignatura(lista);

    // Cabecera
    cout << "Alumnos       ";
    for (int i = 0;i < lista.N_alumnos ;i++ )
    {
        cout << "Nota - " << i + 1 << "       ";
    }
    cout << endl;
    // Guiones
    for (int i = 0;i < numGuiones ;i++ )
    {
        cout << "-";
    }
    cout << endl;
}
*/
