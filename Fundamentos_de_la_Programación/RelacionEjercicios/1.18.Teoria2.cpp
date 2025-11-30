#include <iostream>
#include <array>
#include <math.h>

using namespace std;
 
int main(){
    int  A = 2;
    int  B = 1;
do {
    while (A > B) {
        A = A – B;
    }
    while (B > A) {
        B = B – A;
    }
} while (A != B);

return 0;
 /*SIEMPRE VA A ACABAR SI A>B Y SIEMPRE QUE B NO SEA 0 ENTONCES A>0 Y B>0*/
}