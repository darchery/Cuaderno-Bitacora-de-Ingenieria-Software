#include <iostream>

using namespace std;



int main()
{
    char c1, c2, c3, c4;
    cout << "Introduce la palabra: " << endl;
    cin >> c1 >> c2 >> c3 >> c4;

    c1 =  char (int(c1) - 32);
    c2 =  char (int(c2) - 32);
    c3 =  char (int(c3) - 32);
    c4 =  char (int(c4) - 32);
/* Ò
cin >> c1 >> c2 >> c3 >> c4;
 c1 = char(int('A')+(int(c1)-int('a'))); // o bien c1 = 'A'+(c1-'a');
 c2 = char(int('A')+(int(c2)-int('a')));
 c3 = char(int('A')+(int(c3)-int('a')));
 c4 = char(int('A')+(int(c4)-int('a')));
*/
    cout <<"\n";

    cout << c1 << c2 << c3 << c4 << endl;
 return 0;
}