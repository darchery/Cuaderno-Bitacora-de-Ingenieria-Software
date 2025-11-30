#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int GASTOS_FIJOS = 1;
const double KWH_100 = 0.50;
const double KWH_150 = 0.35;
const double KWH_MAS = 0.25;

//ARREGLAR ESTÁ MAL

int main(){
    int Kwh;
    double total;

    cout <<"Introduce los Kw/h que has consumido: " << endl;
    cin >> Kwh;

    if (Kwh <= 100 && Kwh>=0)
    {
        total=Kwh*KWH_100 + GASTOS_FIJOS;
        
    }
    else if (Kwh >= 100 && Kwh <= 150)
    {
        total= KWH_150*(Kwh-100)  + KWH_100*100 + GASTOS_FIJOS;
        
    }
    else if (Kwh >=  150)
    {
        total= KWH_MAS*(Kwh-150) + KWH_150*50 +  KWH_100*100 + GASTOS_FIJOS;
       
    }
    else
        cout << "Introduce un numero valido..." << endl;

    cout <<"Consumo: " << Kwh << " kWh. Precio total a pagar: " << total<< " euros." << endl;
return 0;
 
}