#include <iostream>
#include <array>

using namespace std;
 
int main(){
    char letras[]={'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    int dni,result;
    cout << "Enter your DNI: "<< endl;
    cin >>  dni;
    result = dni%23;
    cout << " Your DNI letter is: " << letras[result];

return 0;
 
}