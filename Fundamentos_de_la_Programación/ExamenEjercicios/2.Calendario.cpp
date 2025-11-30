#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void calendario(char dia);

int main(){
    char c;

    cout << "Dia que cae primero: ";
    cin >> c;

    calendario(c);

return 0;

}
// VAMOS A PREGUNTAR EL DIA Y DEPENDE DEL DIA VAMOS A COUTEAR DE 0 A 4 '.. '
// DESPUES CON UN FOR EMPEZAREMOS A RECORER LOS NUMEROS DESDE EL EL 1 HASTA EL 31, PONIENDO DESDE EL 1 AL 9 UN PUNTO ANTES, ES DECIR: .1 .2 .3
// HASTA 31 Y PONER SOLO 7 POR FILA
// CUANDO HAYAMOS COUTEADO 7 COSAS LE SUMAMOS UN CNT Y SI LLEGA A 7 HACEMOS COUT <<  ENDL;

void calendario(char dia)
{
    int numHuecos = 0;
    bool espacios;
    int cnt7 = 0;

    switch (dia)
    {
    case 'l':
        numHuecos = 0;
        break;
    case 'm':
        numHuecos = 1;
        break;
    case 'x':
        numHuecos = 2;
        break;
    case 'j':
        numHuecos = 3;
        break;
    case 'v':
        numHuecos = 4;
        break;
    case 's':
        numHuecos = 5;
        break;
    case 'd':
        numHuecos = 6;
        break;
    default:
        cout << "ERROR: dia no identificado" << endl;
        break;
    }

    for (int i = 1;i <= 31 ;i++ )
    {
        if(espacios)
        {
            for (int j = 0;numHuecos > j;j++ )
            {
                cout << ".. ";
                cnt7++;
            }
        }
        espacios = false;

        if (i < 10)
        {
            cout << ".";
        }
        cout << i << " ";
        cnt7++;

        if (cnt7 == 7)
        {
            cnt7 = 0;
            cout << endl;
        }
    }


}

/*
void calendario(char dia)
{
    if (dia == 'l')
    {
        cout << ".1 .2 .3 .4 .5 .6 .7" << endl;
        cout << ".8 .9 10 11 12 13 14" << endl;
        cout << "15 16 17 18 19 20 21" << endl;
        cout << "22 23 24 25 26 27 28" << endl;
        cout << "29 30 31" << endl;
    }
    else if (dia == 'm')
    {
        cout << ".. .1 .2 .3 .4 .5 .6" << endl;
        cout << ".7 .8 .9 10 11 12 13" << endl;
        cout << "14 15 16 17 18 19 20" << endl;
        cout << "21 22 23 24 25 26 27" << endl;
        cout << "28 29 30 31" << endl;
    }
        else if (dia == 'x')
    {
        cout << ".. .. .1 .2 .3 .4 .5" << endl;
        cout << ".6 .7 .8 .9 10 11 12" << endl;
        cout << "13 14 15 16 17 18 19" << endl;
        cout << "20 21 22 23 24 25 26" << endl;
        cout << "27 28 29 30 31" << endl;
    }
        else if (dia == 'j')
    {
        cout << ".. .. .. .1 .2 .3 .4" << endl;
        cout << ".5 .6 .7 .8 .9 10 11" << endl;
        cout << "12 13 14 15 16 17 18" << endl;
        cout << "19 20 21 22 23 24 25" << endl;
        cout << "26 27 28 29 30 31" << endl;
    }
        else if (dia == 'v')
    {
        cout << ".. .. .. .. .1 .2 .3" << endl;
        cout << ".4 .5 .6 .7 .8 .9 10" << endl;
        cout << "11 12 13 14 15 16 17" << endl;
        cout << "18 19 20 21 22 23 24" << endl;
        cout << "25 26 27 28 29 30 31" << endl;
    }

}
*/
