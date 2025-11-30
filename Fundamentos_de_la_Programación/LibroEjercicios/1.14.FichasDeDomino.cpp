#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int menor, mayor;
    cout << "Introduce el menor y mayor numero de la ficha de dominó: " << endl;
    cin >> menor >> mayor;
    cout << (menor + mayor) * (menor + mayor + 1) / (2 + menor);
            /*Suma de las 2 tapas * Siguiente numero despues de la suma  / (Calcula la 
            suma de todos los números desde 0 hasta la suma de los valores en ambos lado) + Se suma al 
            resultado para ajustar la posición a la ficha específica que se está calculando.*/
return 0;
 
}