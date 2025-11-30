#include <iostream>
#include <array>
#include <math.h>

using namespace std;

/*

Cada código consta de cuatro dígitos.
• El primer dígito representa a una provincia.
• Los dos siguientes dígitos indican el número de la operación.
• El último dígito es un dígito de control.

Ej: 4105
Provincia: 4
Nº de la operacion: 10
Digito de control, Diferente de 0: 5

*/
 
int main(){
    int  codNum;
    int provincia;
    int numOperacion;
    int digitControl;
    
    cout << "Introduce el codigo numerico de 4 digitos: " << endl;
    cin >> codNum;

    if (codNum < 9999 && codNum > 999)
    {
        cout << "Introduce un numero con 4 digitos..." << endl;
    }
    else{
        provincia = codNum/1000;
        digitControl = codNum % 10;
        numOperacion= ((codNum/100)%10)*10 + (codNum/10)%10 ;
    }
    cout << "Provincia: " << provincia << endl;
    cout << "Numero de la operacion: " << numOperacion << endl;
    cout << "Digito de control: " << digitControl << endl;

      if (digitControl==(numOperacion*provincia)%10)
    {
        cout << "Confirmacion: correcto" << endl;
    }
    else
        cout << "Confirmacion: error" << endl;
return 0;
 
}