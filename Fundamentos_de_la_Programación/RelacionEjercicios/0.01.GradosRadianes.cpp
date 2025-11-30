#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const double pi=3.1416;
const double gradRad=pi/180;

int main(){
    double ang;
    double rad;
    
    cout << "Introduce el valor en angulos: " << endl;
    cin >> ang;
    rad= ang*gradRad;
    cout << "Ese angulo en radianes es: "<< rad << " rads" <<endl;


return 0;

}
