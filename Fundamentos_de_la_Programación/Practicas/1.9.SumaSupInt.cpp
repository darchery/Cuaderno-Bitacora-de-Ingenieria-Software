#include <iostream>

using namespace std;
/*
Este programa no realiza bien la suma 1 + 3000000000, porque el rango del tipo int es de -2.147.483.648 a 2.147.483.647.
*/

int main()
{
    int n1, n2;
    
    cout << "Introduce 2 numeros para sumarlos: " << endl;
    cin >> n1 >> n2;
    cout << "Su suma es " << n1+n2 << endl;

 return 0;
}