#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int mes;
    int dias;
    
    cout << "Introduce un mes para ver cuantos dias tiene(del 1 al 12): " << endl;
    cin >> mes;

   if (mes==2)
    {
        dias = 28;
    }
    else if (mes==1 || mes==3 || mes==5 || mes==7 || mes == 8 || mes == 10 || mes==12 )
    {
        dias= 31;
    }
    else if (mes==4 || mes==6 || mes==9 || mes==11  )
    {
        dias = 30;
    }
    

    switch (mes)
    {

    case 1:
        cout << "Enero tiene " << dias << " dias." << endl;
        break;
    case 2:

        cout << "Febrero tiene " << dias << " dias." << endl;
        break;
    case 3:

        cout << "Marzo tiene " << dias << " dias." << endl;
        break;
    case 4:

        cout << "Abril tiene " << dias << " dias." << endl;
        break;
    case 5:

        cout << "Mayo tiene " << dias << " dias." << endl;
        break;
    case 6:

        cout << "Junio tiene " << dias << " dias." << endl;
        break;
    case 7:

        cout << "Julio tiene " << dias << " dias." << endl;
        break;
    case 8:

        cout << "Agosto tiene " << dias << " dias." << endl;
        break;
    case 9:

        cout << "Septiembre tiene " << dias << " dias." << endl;
        break;
    case 10:

        cout << "Octubre tiene " << dias << " dias." << endl;
        break;
    case 11:

        cout << "Noviembre tiene " << dias << " dias." << endl;
        break;
    case 12:

        cout << "Diciembre tiene " << dias << " dias." << endl;
        break;
    default:
        cout <<"Porfavor introduce un numero ente 1 y 12..." << endl;
        break;
    }
    /*
    OR
    switch (mes){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: dias = 31;
    break;
    case 4:
    case 6:
    case 9:
    case 11: dias = 30;
    break;
    case 2: dias = 28;
    break;
    def
    */
 
return 0;
 
}