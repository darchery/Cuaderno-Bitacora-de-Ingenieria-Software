#include <iostream>
#include <array>
#include <math.h>


using namespace std;

int main(){
    int dia,mes,ano;
    string mes1;

    cout << "Introduzca el dia, mes y año: " << endl;
    cin >> dia >> mes >> ano;

    
    switch (mes)
    {
    case 1:
        mes1 = "Enero";
        break;
    case 2:
        mes1 = "Febrero";
        break;
    case 3:
        mes1 = "Marzo";
        break;
    case 4:
        mes1 = "Abril";
        break;
    case 5:
        mes1 = "Mayo";
        break;
    case 6:
        mes1 = "Junio";
        break;
    case 7:
        mes1 = "Julio";
        break;
    case 8:
        mes1 = "Agosto";
        break;
    case 9:
        mes1 = "Septiembre";
        break;
    case 10:
        mes1 = "Octubre";
        break;
    case 11:
        mes1 = "Noviembre";
        break;
    case 12:
        mes1 = "Diciembre";
        break;

    default:
        cout << "Ese numero no equivale a ningun mes..." << endl;
        break;
    }
    
    cout <<"Dia: " << dia << endl;
    cout <<"Mes: " << mes1 << endl;
    cout <<"Año: " << ano << endl;

return 0;
 
}