#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int siguienteNum (int const& n, int const& tope);

int main(){
    int const n = 5;
    int num = 0;

    for (int i =0; i <= n ;i++)
    {
        for (int j = 0; j <= n ;j++ )
        {
            cout << num << ' ';
            if ( j != num)
            {
                num = siguienteNum(num, n);
            }
        }
            cout << endl;
    }

return 0;

}

int siguienteNum (int const& n, int const& tope)
{
    if ( n == tope)
    {
        return 0;
    }
    else
    {
        return n + 1;
    }
}
