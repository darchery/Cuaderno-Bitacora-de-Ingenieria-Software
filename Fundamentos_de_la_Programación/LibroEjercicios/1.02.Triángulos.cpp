#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cout << "Inserte el valor de los lados: "<< endl;
    cin >> a >> b >> c;

    if (a+b > c && a+c >b && b+c >a)
    {
        cout << "Es un triangulo "<<endl;
    
    if (a==b and a==c and b==c)
    {
       cout <<"El triangulo es Equilatero"<< endl;
    }
    else if (a!=b and a!=c and b!=c)
    {
    cout <<"El triangulo es Escaleno"<< endl;    
    }
    else
        cout <<"El triangulo es Isosceles"<< endl;   
    
    /* Escaleno ==> ((a==b and c=!a and c!=b) or (b==c and a=!b and a!=c) or (a==c and b=!a and b!=c) )*/

    }
    else
    {
        cout << "No es un triangulo"<< endl;
    }    
    return 0;
}