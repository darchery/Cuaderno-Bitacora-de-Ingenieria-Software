#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    double a,b,ra,rb,rc,r1,r2;
    cout << "Introduce los radios de los circulos: " << endl;
    cin >> ra >> rb >> rc;

    double const sa=1/ra;
    double const sb=1/rb;
    double const sc=1/rc;

    a= sa*sa+sb*sb+sc*sc;
    b= sa+sb+sc;
    r1=((-2*b+sqrt(8*(b*b-a)))/2);
    r2=abs(((-2*b-sqrt(8*(b*b-a)))/2));
    
    cout << "El primer radio es: "<< r1 << endl;
    cout << "El segundo radio es: "<< r2 << endl;
    
    return 0;
 
}