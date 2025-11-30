#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool mismaCantidadOSXS(string cadena)
{
    int os = 0, xs = 0;

    for (int i = 0;i < int(cadena.size()) ;i++ )
    {
        if (cadena[i] == 'o')
        {
            os++;
        }
        else if (cadena[i] == 'x')
        {
            xs++;
        }
    }

    if (os == xs)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(){
    string cadena1 = "ooxx", cadena2 = "xooxx";
    string cadena3 = "ooxxm", cadena4 = "zpzpzpp", cadena5 = "zzoo";

    cout << cadena1 << " => " << boolalpha << mismaCantidadOSXS(cadena1) << endl;
    cout << cadena2 << " => " << boolalpha << mismaCantidadOSXS(cadena2) << endl;
    cout << cadena3 << " => " << boolalpha << mismaCantidadOSXS(cadena3) << endl;
    cout << cadena4 << " => " << boolalpha << mismaCantidadOSXS(cadena4) << endl;
    cout << cadena5 << " => " << boolalpha << mismaCantidadOSXS(cadena5) << endl;
return 0;

}
