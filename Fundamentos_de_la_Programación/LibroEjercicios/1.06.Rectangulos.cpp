#include <iostream>
#include <array>         /*NO FUNCIONA*/
#include <math.h>

using namespace std;
 
int main(){
    int x1,x2,y1,y2;
    cout << "Introduce las coordenadas del rectangulo, x1,x2,y1 e y2 respectivamente: "<<endl;
    cin >> x1 >> x2 >> y1 >> y2;
  /*int punto1=(x1,y1);
    int punto2=(x1,y2);
    int punto3=(x2,y1);
    int punto4=(x2,y2);*/
    
    if ( (sqrt(pow(x1-x1,2)+pow(y1-y2,2))) > 0 and (sqrt(pow(x1-x2,2)+pow(y1-y1,2))) > 0 and (sqrt(pow(x1-x2,2)+pow(y1-y2,2))) > 0 
     and (sqrt(pow(x1-x2,2)+pow(y2-y1,2))) > 0 and (sqrt(pow(x1-x2,2)+pow(y2-y2,2))) > 0  and (sqrt(pow(x2-x2,2)+pow(y1-y2,2))) > 0 ) 
    {
        
        cout << "Es un rectangulo"<<endl;
    }
    else    
        cout << "No es un rectangulo)"<<endl;
    
return 0;
 
}