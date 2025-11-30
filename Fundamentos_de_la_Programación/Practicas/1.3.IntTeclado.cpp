#include <iostream>

using namespace std;

/*
Vemos que cuando introducimos un entero este concuerda con le tipo de variable y lo pasa en el cout directamente, 
pero sin embargo cuando introducico un char como la letra 'a', su salida es cero, seguramente el programa está intentando pasarlo
entero, pero obviamente una letra no es un entero y le asignará un valor nulo.
*/

int main()
{
    int n;
    cout << "Introduce un entero: " << endl;
    cin >> n;
    cout << n << endl;


return 0;
}