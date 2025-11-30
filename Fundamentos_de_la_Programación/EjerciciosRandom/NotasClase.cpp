#include <iostream>
#include <array>
#include <math.h>

using namespace std;

double numSuspensos(double notas)
{
    int cntSus = 0;
    while (notas != 0)
    {
        if (notas > 0 && notas < 5)
        {
            cntSus++;
        }
        cin >> notas;
    }
    return cntSus;
}

double numAprobados(double notas)
{
    int cntApr = 0;
    while (notas != 0)
    {
        if (notas >= 5 && notas <= 10)
        {
            cntApr++;
        }
        cin >> notas;
    }
    return cntApr;
}

double media(double notas)
{
    int sumaNotas = 0;
    int numNotas = 0;

    while (notas != 0)
    {
        if (notas > 0 && notas <= 10)
        {
            cout << "Notas: " << notas << endl;
            sumaNotas += notas;
            numNotas++;
        }
        cin >> notas;
    }
    cout << "Numero Notas: " << numNotas << endl;
    return sumaNotas/numNotas;
}

double mayorNota(double notas)
{
    int mayor = notas;

    while (notas != 0)
    {
        if ((notas > mayor) && (notas > 0 && notas <= 10))
        {
            mayor = notas;
        }
        cin >> notas;
    }
    return mayor;
}

double peorNota(double notas)
{
    int menor = notas;

    while (notas != 0)
    {
        if (notas < menor && (notas > 0 && notas <= 10))
        {
            menor = notas;
        }
        cin >> notas;
    }
    return menor;
}

double leerDatos(double notas)
{
    cout << "Introduce las notas (separadas por blancos, finalice con un valor negativo y pulse INTRO): ";
    cin >> notas;
    return notas;
}

int main(){
    double notas;
    char c;
    do
    {
        notas = leerDatos(notas);
        if (notas > 0)
        {
            int suspenso = numSuspensos(notas);
            int aprobado = numAprobados(notas);
            double medias = media(notas);
            double mayor = mayorNota(notas);
            double menor = peorNota(notas);

            cout << "Suspensos: " << suspenso <<", " << "Aprobados: " << aprobado << ", "
            << "Media: " << medias << ", " << "Mejor: " << mayor << ", " << "Menor: " << menor << endl;
        }
        else if (notas == 0){
            cout << "No ha introducido nintuna nota" << endl;
        }

        cout << "Desea introducir otra nota? (S/N): ";
        cin >> c;
    } while (c == 'S' || c == 's');
    if (c == 'N' || c == 'n')
    {
        cout << "FIN DEL PROGRAMA" << endl;
    }
return 0;

}

/*
double leerDatos(double notas);
void analizarNotas(double notas);
double mayorNota(double notas);
double peorNota(double notas);
double media(double notas);
double numSuspensos(double notas);
double numAprobados(double notas);
*/
/*
cout << "No hay ninguna nota" << endl;
        cout << "Desea repetir el proceso (S/N)? ";
        cin >> c;
*/

/*void analizarNotas(double notas)
{
    cout << "Suspensos: " << numSuspensos(notas) <<", " << "Aprobados: " << numAprobados(notas) << ", "
    << "Media: " << media(notas) << ", " << "Mejor: " << mayorNota(notas) << ", " << "Menor: " << peorNota(notas) << endl;
}
*/

// MAIN QUE ES UN LIO Y NO FUNCIONA
/*
    sec = leerDatos(notas);
    if (sec < 0)
    {
        cout << "No hay ninguna nota" << endl;
        cout << "Desea repetir el proceso (S/N)? ";
        cin >> c;

        if (c == 'S')
        {
            leerDatos(notas);
            sec = leerDatos(notas);
            cout << "Suspensos: " << numSuspensos(notas) <<", " << "Aprobados: " << numAprobados(notas) << ", "
            << "Media: " << media(notas) << ", " << "Mejor: " << mayorNota(notas) << ", " << "Menor: " << peorNota(notas) << endl;
        }
        else
        {
            cout << "FIN DEL PROGRAMA" << endl;
        }
    }
    else
    {
        cout << "Suspensos: " << numSuspensos(sec) <<", " << "Aprobados: " << numAprobados(sec) << ", "
        << "Media: " << media(sec) << ", " << "Mejor: " << mayorNota(sec) << ", " << "Menor: " << peorNota(sec) << endl;
        /*cout << "Desea repetir el proceso (S/N)? ";
        cin >> c;

        if (c == 'S')
        {
            leerDatos(notas);
            sec = leerDatos(notas);
            cout << "Suspensos: " << numSuspensos(notas) <<", " << "Aprobados: " << numAprobados(notas) << ", "
            << "Media: " << media(notas) << ", " << "Mejor: " << mayorNota(notas) << ", " << "Menor: " << peorNota(notas) << endl;
        }
        else
        {
            cout << "FIN DEL PROGRAMA" << endl;
        }
        */

