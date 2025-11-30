#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    char sincod;
    string cod;
    int clave =4;
    
    cout << "introduce la secuencia: " << endl;
    cin >> sincod;

    while (sincod!=0)
    {
        cod = char(sincod + clave);
        cout << "Letra codificada :" << endl;
        cout << cod << endl;
        cout << endl;
        cin >> sincod;
        
    }
    
    
return 0;
 
}