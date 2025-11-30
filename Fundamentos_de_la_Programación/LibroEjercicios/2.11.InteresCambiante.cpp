#include <iostream>
#include <array>
#include <math.h>
#include <ctime>


using namespace std;
 
int main(){
    float dinero, interes, restante;
    int year;
    
    srand((unsigned)time(0));
    interes = (float)(1 + rand() % 200)/200;
    
    cout << "Introduce el dinero que quieres ahorrar en el fondo con interes variable cada año" << endl;
    cin >> dinero;
    cout << "Introduce los años que lo quieres tener aquí depositado: " << endl;
    cin >> year;

    while (year > 0)
    {
        srand((unsigned)time(0));
        interes = (float)(1 + rand() % 200)/200;
        cout << interes;
        restante += dinero+dinero*interes;
        year--;
        srand((unsigned)time(0));
        interes = (float)(1 + rand() % 200)/200;
    }
    cout << "Tu dinero final es : " << restante << " euros" << endl; 
 
return 0;
 
}