#include <iostream>
#include <array>
#include <math.h>

/*
Diseña la versión iterativa del siguiente procedimiento recursivo:

void Rec(int n)
{
    if (!f(n))
    {
        {cualquier grupo de sentencias que no modifiquen el valor de n}
        Rec(g(n))
    }
}

donde las cabeceras de f y g se definen como: bool f(int n)
                                              int g(int n)
*/

using namespace std;

void Rec(int n);
bool f(int n);
int g(int n);
void NoRec(int n);

int main(){
    int n;

return 0;

}

void NoRec(int n)
{
    while (!f(n))
    {
        {cualquier grupo de sentencias que no modifiquen el valor de n}
        n = g(n);
    }
}

void Rec(int n)
{
    if (!f(n))
    {
        {cualquier grupo de sentencias que no modifiquen el valor de n}
        Rec(g(n));
    }
}
