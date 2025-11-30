#include <iostream>
#include <array>
#include <math.h>
#include <ctime> 

using namespace std;
 
int main(){

    int numObjeto;
    int numElim;
    int aleatorio = 0;
    srand((unsigned)time(0));
    bool ceroObjetosMAQUINA = false;
    bool ceroObjetosPERSONA = false;

    cout << "Introduce el numero de bolas" << endl;
    cin >> numObjeto;

    while (numObjeto > 0)
    {
        srand((unsigned)time(0));
        aleatorio = 1 + rand() % 3;
        numObjeto-=aleatorio;

        if (numObjeto <= 0 )
        {
            ceroObjetosMAQUINA = true;
            break;
        }
        
        //HACKS ACTIVADOS cout <<"Bolas restantes: " << numObjeto << endl;

        cout <<"Quita 1, 2 o 3 bolas: " << endl;
        cin >>  numElim;
        numObjeto-=numElim;
        srand((unsigned)time(0));
        
        if (numObjeto <= 0)
        {
            ceroObjetosPERSONA = true;
            break;
        }
    }

    if (ceroObjetosPERSONA)
    {
        cout << "Perdiste humano..." << endl;
        cout << "Felicidades MAQUINA!!!" << endl;
    }
    
    if (ceroObjetosMAQUINA)
    {
        cout << "Perdiste maquina..." << endl;
        cout << "Felicidades PERSONA!!!"<< endl;
    }

return 0;
 
}