#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int num;
    int cnt_12=0;
    int pos =1;
    int posPrimer12=0;
    int posUlt12=0;
    
    cout << "Introduce la secuencia para ver las posiciones del 12 (termiando en 0):" << endl;
    cin >> num;

    while (num!=0)
    {
     if (num==12 && cnt_12==0)
     {
        cnt_12++;
        posPrimer12=pos;
     }
     if (num==12 && cnt_12!=0)
     {
        cnt_12++;
        posUlt12 = pos;
     }
     
     pos++;
     cin >>  num;

    }

    cout << "Posicion del primer 12: " <<posPrimer12<< endl;
    cout << "Posicion del ultimo 12: " <<posUlt12<< endl;

return 0;
 
}