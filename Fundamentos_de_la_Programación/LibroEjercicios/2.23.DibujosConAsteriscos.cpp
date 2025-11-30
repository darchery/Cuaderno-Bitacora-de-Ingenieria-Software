#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){

    cout <<"VOLCAN: "<< "\n" << endl;

    int m=2;
    int espacios=32;
    int altura=6;



  /* for (int i = 0; i < altura; i++)
    {
        for (int k = 0; k < espacios; k++)
        {
            cout <<' ';
        }
        espacios -=4;

        for (int j = 1; j < m; j++)
        {
            cout << '*';
        }
        m *=2;
        cout << '*' << endl;
    }
    */



   for (int i = 0; i < altura; i++) {
    
        for (int k = 0; k < espacios; k++) {
            cout << ' ';
        }

        for (int j = 0; j < m; j++) {
            cout << '*';
        }

        espacios -= 2;
        m += 4;
        cout << endl;
    }


  cout <<"MOSAICO: "<< "\n" << endl;

    char list[]={' ','*'};
    int sim=0;

    int N=8 ;

    cout<<"\n";
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << list[sim];
            if (sim==0)
            {
                sim=1;
            }
            else if (sim==1)
            {
                sim=0;
            }    
        }
        
        cout << list[sim] << endl;
        if (sim==0)
         {
            sim=1;
        }
        else if (sim==1)
        {
            sim=0;
        }     
    }
    

 
return 0;
 
}