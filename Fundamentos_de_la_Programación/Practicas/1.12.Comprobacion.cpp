#include <iostream>
using namespace std;
/*
El primer código intercambia los valores de a y b gracias a l variable auxiliar
 y la segunda sentencia hace lo mismo mediante sumas y restas
*/
int main()
{
 int a=6, b=14;
 int auxiliar;
 cout << "a vale " << a << " y b vale " << b << endl;

 // ¿Qué hacen estas tres sentencias?

 /*auxiliar = a;
 a = b;
 b = auxiliar;*/

 a = a + b;
 b = a - b;
 a = a - b;

 cout << "a vale " << a << " y b vale " << b << endl;

 return 0;
}
