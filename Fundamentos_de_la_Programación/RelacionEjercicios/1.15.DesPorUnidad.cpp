#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int UNA_UNIDAD=100;
const int DOS_UNIDAD=95;
const int TRES_UNIDAD=90;
const int CUATROMAS_UNIDAD=85;

int main(){
    int unidad;
    cout << "Introduce las unidades que quieres comprar: " << endl;
    cin >> unidad;
    if (unidad==1)
    {
        cout << "El precio es de " << unidad*UNA_UNIDAD;
    }
    else if (unidad==2)
    {
        cout << "El precio es de " << unidad*DOS_UNIDAD;
    }
    else if (unidad == 3)
    {
        cout << "El precio es de " << unidad*TRES_UNIDAD;
    }
    else if (unidad >= 4)
    {
        cout << "El precio es de " << unidad*CUATROMAS_UNIDAD;
    }
    else
        cout << "Introduce una unidad valida..."  << endl;
    
return 0;
 
}