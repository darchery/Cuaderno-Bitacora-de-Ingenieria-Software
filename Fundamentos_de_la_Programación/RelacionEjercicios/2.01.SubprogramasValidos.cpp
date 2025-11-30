#include <iostream>
#include <array>
#include <math.h>

using namespace std;

bool uno(int x, int y);
void dos(int& x, int y);
int tres(int x);

int main(){
    int a,b,c;
    bool fin;
    /*
    a) if (uno(a,b))        CORRETO, se ejecuta el cuerpo del if si uno(a,b) es true
    b) dos(a,b+3)           CORRECTO, se puede incializar sumandole a una variable porque no lleva &
    c) fin = uno(c,5)       CORRECTO, se le puede asignar un bool a fin porque es bool y los valores son validos
    d) fin = dos(c,5)       INCORRECTO, porque 1. dos es un subP void y no returna nada y no se le puede asignar ningun valor
    e) dos(a,tres(a))       CORRECTO, podemos aplicar la f. void  en a que es entero y la y seria lo que devuele tres
    f) dos(tres(b),c)       INCORRECTO, el primer valor se pasa por &, es decir solo puede ser una variable, ni constantes ni expresiones
    g) if tres(a)           INCORRECTO, necesitas meter en parentesis, NO NO ESTAS COMPARANDO NADA
    h) b = tres(dos(a,5))   INCORRECTA, b es int (bien), tres con un valor int (bien) pero el void  no retorna nada
    i) dos(4,c)             INCORRECTA, CUANDO ES POR & SE PASAN SOLO VARIABLES
    */
    //cin >> a;
   // cout << dos(a,tres(a));
return 0;

}

void dos(int& x, int y)
{
    x = y ;
}
int tres(int x)
{
    return 3*x;
}

