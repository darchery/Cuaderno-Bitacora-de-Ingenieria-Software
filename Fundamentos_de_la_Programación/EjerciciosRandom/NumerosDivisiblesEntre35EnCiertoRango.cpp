/*
Write a program to find those numbers which are divisible by 35, between 1500 and 2700 (both included) (It should
print: 1505, 1540, 1575, 1610, 1645, 1680, 1715, 1750, 1785, 1820, 1855, 1890, 1925, 1960, 1995, 2030, 2065, 2100, 2135,
2170, 2205, 2240, 2275, 2310, 2345, 2380, 2415, 2450, 2485, 2520, 2555, 2590, 2625, 2660, 2695).
*/

#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int DIVISOR = 35;

int main(){
    int limInf, limSup;

    cout << "Introduzca el limite inferior y superior para ver los divisores de 35 en un cierto rango: ";
    cin >> limInf >> limSup;

    for (int i = limInf; i <= limSup ; i++ )
    {
        if (limInf % DIVISOR == 0)
        {
            cout << limInf <<", ";
        }
        limInf++;
    }

return 0;

}
