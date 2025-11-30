#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    char c1,c2,c3;
    int num;
    

    cout << "Introduce los caracteres para pasarlos a entero: " << endl;
    cin >> c1 >> c2 >> c3;



    num = (c1-'0')*100  +
          (c2-'0')*10   +
          (c3-'0')*1    ;
    cout << num <<endl;

   

    /*
        double x;
        int x;

        y=23;
        x=y; x=23.0

        char c;
        int x;

        c='A';
        x=c; x=65

        Julio cesar
        
        char c;
        int x;

        c='A';
        x=c;
        x=char(c+4); x='D'
            
    */
return 0;
 

}