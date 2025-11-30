#include <fstream>
#include <string>
#include <math.h>

using namespace std;
 
int main(){

    ifstream fuente ("rayuela.txt");
    ofstream pares ("pares.txt");
    ofstream impares ("impares.txt");
    while (!fuente.eof())
    {
        string linea;
        getline(fuente,linea); pares << linea << endl;
        if (!fuente.eof())
        {
            getline(fuente,linea); impares  << linea << endl;
        }
        
    }
    

 
}