#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const double IVA= 12.0/100.0;
const double DES = 5.0/100.0;

int main(){
    int unidades;
    double precio;
    double total;

    cout << "Introduce las unidades del producto: " << endl;
    cin >> unidades;
    cout << "Introduce el precio de cada unidad: "  << endl;
    cin >> precio;

    total= unidades*precio +  IVA*(unidades*precio);

    if (total > 300)
    {
        total-= DES*total;
        cout << "Se ha aplicado el descuento del 5%." << endl;
        cout << "El precio final es de: " << total << endl;
    }
    else
        cout << "El precio final es de: " << total << endl;
    

 
return 0;
 
}