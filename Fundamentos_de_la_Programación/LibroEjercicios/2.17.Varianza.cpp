#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int N=5;
    float vector[N];
    float total=0.0;
    float media=0.0;
    float var=0.0;

    
    for (int i = 0; i < N ; i++)
    {
        /*cout << "Ingrese el numero de datos que quiere: "<< endl;
        while (N!=0)
        {
            cin >> N;
        }*/

        cout <<"Ingrese los valores para hacer la varianza: " << endl;
        cin >> vector[i];
        total += vector[i];
    }
   
    cout << "Valores que toma x: " << endl;

    for (int j = 0; j < N; j++)
    {
        cout << "Valor "<< j <<": " << vector[j]  << endl;
        
    }
    cout << "\n\n";
    for (int k = 0; k < N; k++)
    {
        
        media= total/N;
        var += pow(vector[k] - media, 2); 
        /*var += (pow((vector[k])-(media),2)); */
        /*var+=   vector[k]*vector[k]  - 2*vector[k]*media  + media * media  ;*/
    }

    cout  << "Total: "<< total << endl;
    cout  << "Media: "<< media << endl;
    cout << "Varianza : " << var/(N-1) << endl;
    cout << "Desviacion tipica: " << sqrt(var/N)<< endl;
 
return 0;
 
}