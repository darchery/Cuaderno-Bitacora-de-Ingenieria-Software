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
    
    switch (unidad)
    {
    case 1:
        cout << "El precio es de " <<unidad*UNA_UNIDAD << endl;
        break;

    case 2:
        cout << "El precio es de " <<unidad*DOS_UNIDAD << endl;
        break;

    case 3:
        cout << "El precio es de " <<unidad*TRES_UNIDAD << endl;
        break;

    default:
        cout << "El precio es de " <<unidad*CUATROMAS_UNIDAD<< endl;
        break;
    }
    
return 0;
 
}