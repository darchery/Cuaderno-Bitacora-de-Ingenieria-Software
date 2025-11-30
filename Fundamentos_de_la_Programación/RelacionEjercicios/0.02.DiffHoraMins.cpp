#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int hora1,min1;
    int hora2,min2;
    int difHora,difMinuto;

    cout << "Introduce las horas para hacer la resta: " << endl;
    cin >> hora1 >> min1;
    cin >> hora2 >> min2;

    difHora=hora1-hora2;
    difMinuto=min1-min2;

    if (difMinuto < 0)
    {
        hora1 = hora1 - 1;
        min1 = min1 + 60;
        
        difHora=hora1-hora2;
        difMinuto=min1-min2;
    }
    
    cout << difHora << " horas y " << difMinuto << " minutos" << endl;

return 0;

}