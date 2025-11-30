#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int N = 7;

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N-i-1; k++)
        {
            cout <<' ';
        }
        
        for (int j = 0; j < i*2+1; j++)
        {
            cout << '*';
        }
            cout << endl;
    }

    cout << "\n\n";

    for (int l = 0; l < N; l++)
    {
        for (int n = 0; n <N; n++)
        {
            cout << ' ';
        }
        
        for (int m = 0; m < N; m++)
        {
            cout <<'*';
        }
            cout << endl;
    }
    
 
return 0;
 
}