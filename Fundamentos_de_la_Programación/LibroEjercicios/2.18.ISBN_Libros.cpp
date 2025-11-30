#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int N = 9; 
    int VectorISBN[N] = {8, 4, 4, 6, 0, 0, 2, 3, 4};
    int total = 0;
    int cnt = 1;
    /*int VectorISBN[N]={8,4,2,0,5,3,2,1,1};*/
    
    /* 8 4 2 0 5 3 2 1 1  = 96*/
    
    for (int i = 0; i < N; i++)
    {
       /* cout << "Introduce los 9 primeros digitos del ISBN: " << endl,
        cin >> vector_ISBN[i];*/
        total += VectorISBN[i]*cnt;
        cout << total << endl;
        cnt++;
    }
    
    int UltimoDigito = total%11;

    cout << "Total: "<< total << endl;

    if (UltimoDigito==10)
    {
        cout << "El ultimo digito del ISBN: X" << endl;
    }
    else
        cout << "El ultimo digito del ISBN: " << UltimoDigito << endl;
 
return 0;
 
}