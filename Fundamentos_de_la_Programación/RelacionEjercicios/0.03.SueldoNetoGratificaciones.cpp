#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    
    float sueldo;
    int antiguedad;
    int gratificaciones;
    float salarioBruto=0.0;
    float salarioNeto=0.0;
    

    cout << "Introduce el sueldo y la antiguedad del trabajador: " << endl;
    cin >> sueldo >> antiguedad;


    if (antiguedad%5==0)
    {
        gratificaciones =60*antiguedad;
    }
    else if (antiguedad%5!=0)
    {
        gratificaciones= (antiguedad/5)*60 + (antiguedad%5)*6;
    }
    
    salarioBruto = sueldo + gratificaciones;
    salarioNeto = salarioBruto - (salarioBruto*(20.0/100)) - (salarioBruto*(5.0/100));

    cout << "Salario Neto: " << salarioNeto << endl;    
    

return 0;
 
}