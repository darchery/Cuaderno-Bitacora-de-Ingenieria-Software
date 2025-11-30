#include <iostream>
#include <array>
using namespace std;

const int FILAS = 7;
const int COLS = 12;
typedef array<char, COLS> TFila;
typedef array<TFila, FILAS> TMatriz;

void calcularDiametro(TMatriz& img,int& diam, int fila, int col)
{
    bool fin = false;

    for (int i = col + 1;i < COLS && !fin;i++ )
    {
        if (img[fila][i] == ' ')
        {
            diam++;
        }
        else
        {
            diam++;
            fin = true;
        }
    }
}

int numAsteriscoPorFila(TMatriz& img, int fila, int col)
{
    int cnt = 0;

    for (int i = col;i < COLS ;i++ )
    {
        if (img[fila][i] == '*')
        {
            cnt++;
        }
    }
    return cnt;
}

int diametro(TMatriz img)
{
    int diam;
    int mayorDiam = 0;
    bool found;

    for (int i = 0;i < FILAS ;i++ )
    {
        found = false;
        diam = 0;
        for (int j = 0;j < COLS && !found;j++ )
        {
            if (img[i][j] == '*' && numAsteriscoPorFila(img,i,j) > 1)
            {
                diam++;
                found = true;
                calcularDiametro(img,diam,i,j);
            }

            // Actualizar mayor
            if (mayorDiam < diam)
            {
                mayorDiam = diam;
            }
        }
    }
    return mayorDiam;
}

int main() {
    TMatriz img1 = {{ {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' '}},
                      {{'*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' '}},
                      {{'*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' '}},
                      {{' ','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' '}},
                    }};
    TMatriz img2 = {{ {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' '}},
                    }};
    TMatriz img3 = {{ {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                      {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                    }};
    cout << "Diameter of first circle: : " << diametro(img1)<< endl;
    cout << "Diameter of second circle: : " << diametro(img2)<< endl;
    cout << "Diameter of third circle: : " << diametro(img3)<< endl;
    return 0;
}
