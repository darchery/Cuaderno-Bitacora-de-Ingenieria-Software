#include <iostream>

using namespace std;

const double TEORIA = 7.0/10.0;
const double PRAC = 3.0/10.0;

int main()
{
    double notaTeoria, notaPrac, notaFinal;

    cout << "Introduce las notas de teoria y practica: " << endl;
    cin >> notaTeoria >> notaPrac;

    notaFinal=  notaTeoria*TEORIA + notaPrac*PRAC;

    cout << "Nota final: " << notaFinal << endl;
 return 0;
}