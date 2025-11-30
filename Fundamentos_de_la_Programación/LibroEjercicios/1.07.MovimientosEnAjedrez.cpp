#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int f1,c1,f2,c2;
    cout << "Introduce f1: "<< endl;
    cin >> f1;
    cout << "Introduce c1: "<< endl;
    cin >> c1;
    cout << "Introduce f2: "<< endl;
    cin >> f2;
    cout << "Introduce c2: "<< endl;
    cin >> c2;

    if (f1==f2 or c2==c1)
    {
        cout <<"Torre Si"<<endl;
    }
    else    
        cout <<"Torre No"<< endl;

    if ( (abs(f1-f2<=1) and abs((f1-f2!=0))) and (abs(c1-c2<=1) and abs((c1-c2!=0))) )
    {
        cout <<"Rey Si"<<endl;
    }
    else    
        cout <<"Rey No"<< endl;

    if (f1==f2 or c2==c1 or (abs(f1-f2) == abs(c1-c2)) )
    {
        cout <<"Reina Si"<<endl;
    }
    else    
        cout <<"Reina No"<< endl;
        
    if (abs(f1-f2) == abs(c1-c2) )
    {
        cout <<"Alfil Si"<<endl;
    }
    else    
        cout <<"Alfil No"<< endl;
    
    if (abs(f1-f2)*abs(c1-c2)==2 )
    {
        cout <<"Caballo Si"<<endl;
    }
    else    
        cout <<"Caballo No"<< endl;
return 0;
 
}