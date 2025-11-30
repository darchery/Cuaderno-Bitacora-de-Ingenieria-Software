#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 10;
typedef array<int, MAX> TFila;
typedef array<TFila, MAX> TMatriz;

struct TLista {
    TMatriz mat;
    int nFil, nCol;
};

void leerMatriz(TLista& l)
{
    cout << "Introduzca la dimension de la matriz: ";
    do
    {
        cin >> l.nFil >> l.nCol;
    } while (l.nFil < 0 || l.nFil > MAX  || l.nCol < 0 || l.nCol > MAX);
    cout << "Introduzca la matriz (" << l.nFil << " x " << l.nCol << "): " << endl;
    for (int i = 0;i < l.nFil;i++ )
    {
        for (int j = 0;j < l.nCol;j++ )
        {
            cin >> l.mat[i][j];
        }
    }
}

void multiplicarMatrices(const TLista& l_1, const TLista& l_2, TLista& l_Res)
{
    int sumatorio;

    for (int i = 0;i < l_1.nFil ;i++ )
    {
        for (int j = 0;j < l_2.nCol ;j++ )
        {
            sumatorio = 0;
            for (int k = 0;k < l_1.nCol ;k++ )
            {
                sumatorio += l_1.mat[i][k] * l_2.mat[k][j];
            }
            l_Res.mat[i][j] = sumatorio;
        }
    }

    // Asignamos dimensiones matriz res
    l_Res.nFil = l_1.nFil;
    l_Res.nCol = l_2.nCol;
}

void escribirMatriz(TLista& l_Res)
{
    cout << "La multiplicacion entre A y B: " << endl;
    for (int i = 0;i < l_Res.nFil ;i++ )
    {
        for (int j = 0;j < l_Res.nCol ;j++ )
        {
            cout << l_Res.mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    TLista l_1, l_2;
    TLista l_Res;
    l_Res.mat = {{}};

    leerMatriz(l_1);
    cout << endl;
    leerMatriz(l_2);

    if (l_1.nCol == l_2.nFil)
    {
        multiplicarMatrices(l_1,l_2, l_Res);
        escribirMatriz(l_Res);
    }
    else
    {
        cout << "Error: estas dimensiones no se pueden multiplicar entre si" << endl;
    }
return 0;

}
/*

l_1.mat = {{
                    {{2, 0, 1}},
                    {{3, 0, 0}},
                    {{5, 1, 1}}
    }};
    l_2.mat  = {{
                    {{1, 0, 1}},
                    {{1, 2, 1}},
                    {{1, 1, 0}}
    }};

2 0 1
3 0 0
5 1 1

1 0 1
1 2 1
1 1 0

*/
