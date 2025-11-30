#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool proximos(double const& x, double const& y);

// False 0
//True 1
int main(){
    double x,y;

    cout << "Introduzca 2 numeros para ver si son proximos: ";
    cin >> x >> y;
    cout << boolalpha <<proximos(x,y)<< endl;


return 0;

}

bool proximos(double const& x, double const& y)
{
    double const EPS =1.0/1000000.0  ; // 1E-6
    return fabs(x-y) < EPS;
}
