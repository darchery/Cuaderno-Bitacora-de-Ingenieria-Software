#include <iostream>
#include <array>

using namespace std;

const int MAX= 50;
typedef array<double, MAX> TEstatura;

/// CREAR STRUCT

/*struct TLista {
    TEstatura estatura;
    int tamVector;
};*/


void leerEstaturas(TEstatura& v, int& tamVector)
{
    do
    {
        cout << "Cuantas estructuras va a introducir (maximo " << MAX << "): ";
        cin >> tamVector;
    } while (tamVector <= 0 || tamVector > MAX);

    cout << "Introduzca las " << tamVector << " estaturas: ";
    for (int i = 0;i < tamVector ;i++ )
    {
        cin >> v[i];
        while (v[i] <= 0)
        {
            cin >> v[i];
        }
    }
}

double mediaEstaturas(TEstatura& v, int& tamVector)
{
    double media = 0;

    if (tamVector > 0) // robusto
    {
        for (int i = 0;i < tamVector ;i++ )
        {
            media += v[i];
        }
    }
    return media/tamVector;
}

double altos(TEstatura& v, int& tamVector, double media)
{
    int nAltos = 0;

    for (int i = 0;i < tamVector ;i++ )
    {
        if (v[i] > media)
        {
            nAltos++;
        }
    }
    return nAltos;
}

double bajos(TEstatura& v, int& tamVector, double media)
{
    int nBajos = 0;

    for (int i = 0;i < tamVector ;i++ )
    {
        if (v[i] < media)
        {
            nBajos++;
        }
    }
    return nBajos;
}

int main()
{
    TEstatura v1;
    int tamVector;
    double media;

    leerEstaturas(v1, tamVector);
    media =  mediaEstaturas(v1, tamVector);
    cout << "La media es: " << media << endl;
    cout << "Numero de alumnos mas altos que la media: " << altos(v1, tamVector, media); << endl;
    cout << "Numero de alumnos mas bajos que la media: " << bajos(v1, tamVector, media); << endl;
    return 0;
}
/*
void escribir(double media, int altos, int bajos) {
cout << "La media es: " << media << endl;
cout << "Numero de alumnos mas altos que la media: "
<< altos << endl;
cout << "Numero de alumnos mas bajos que la media: "
<< bajos << endl;
}
escribir(med,masAltos(clase,med),masBajos(clase,med));
*/
