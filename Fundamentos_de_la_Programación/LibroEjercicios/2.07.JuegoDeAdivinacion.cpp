#include <iostream>
#include <array>
#include <math.h>
#include <ctime>

using namespace std;

int main(){
    int ad,rn;
    srand((unsigned)time(0));
    rn = 1 + rand() % 1000;

    cout << "Prueba un numero joven: " << endl;
    cin >> ad;

    while (ad!=rn)
    {
        if (ad > rn)
        {
            cout << "Mas pequeño" << endl;
        }
        else if (ad < rn)
        {
            cout << "Mas grande" << endl;
        }
        else if(ad==rn)
        {
            cout << "Eureka, ese es el numero" << endl;
        }
        cin >> ad;

    }
return 0;

}
