#include <iostream>

using namespace std;

const double tasa = 25.0;
const double PRECIO_HORA = 60.0;

int main()
{
double horas,dias,total,neto;

cout << "Introduzca las horas trabajadas: ";
cin >> horas;
cout << "Introduzca los dias trabajados: ";
cin >> dias;
total = horas*dias*PRECIO_HORA;
neto = total - tasa;
cout << "El valor total a pagar es: ";
cout << total << endl;
cout << "El valor neto a pagar es: ";
cout << neto << endl;

return 0;
}