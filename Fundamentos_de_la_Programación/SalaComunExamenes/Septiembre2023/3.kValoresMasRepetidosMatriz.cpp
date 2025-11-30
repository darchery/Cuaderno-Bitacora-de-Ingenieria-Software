#include <iostream>
#include <array>
using namespace std;

const int FILA = 3;
const int COL = 4;
typedef array<int,COL> TFila;
typedef array<TFila, FILA> TMatriz;

struct TNumero {
    int num;
    int frecuencia = 0;
};

typedef array<TNumero,COL*FILA> TFrecuencia;
typedef array<bool, COL*FILA> TTachado;

struct TLista
{
    TFrecuencia frec;
    TTachado tachado = {{}};
    int nElementos = 0;
};

typedef array<int,COL*FILA> TVec;

void leerMatriz(TMatriz& mat)
{
    for (int i = 0;i < FILA ;i++ )
    {
        for (int j = 0;j < COL ;j++ )
        {
            cin >> mat[i][j];
        }
    }
}

void esta(const TLista& lista, int num, int posAct, int& index, bool& siEsta)
{
    siEsta = false;

    for (int i = posAct - 1;i >= 0 && !siEsta;i-- )
    {
        if (num == lista.frec[i].num)
        {
            siEsta = true;
            index = i;
        }
    }
}

void sacarFrecuencias(TLista& lista, TMatriz& mat)
{
    int index;
    bool siEsta;

    for (int i = 0;i < FILA ;i++ )
    {
        for (int j = 0;j < COL ;j++ )
        {
            esta(lista,mat[i][j], lista.nElementos,index,siEsta);
            if (!siEsta)
            {
                lista.frec[lista.nElementos].num = mat[i][j];
                lista.frec[lista.nElementos].frecuencia++;
                lista.nElementos++;
            }
            else
            {
                lista.frec[index].frecuencia++;
            }
        }
    }
}

int frecMayor(TLista& lista)
{
    int frecuenciaMayor = 0;
    int index = 0;
    int mayor;

    for (int i = 0;i < lista.nElementos ;i++ )
    {
        if (!lista.tachado[i] && frecuenciaMayor < lista.frec[i].frecuencia)
        {
            frecuenciaMayor = lista.frec[i].frecuencia;
            index = i;
        }
    }
    lista.tachado[index] = true;
    mayor = lista.frec[index].num;
    return mayor;
}

void sacarMayoresFrecuencias(TLista& lista, TVec& vec)
{
    for (int i = 0;i < lista.nElementos ;i++ )
    {
        vec[i] = frecMayor(lista);
    }
}


void escribirMayores(const TVec& vec, int tamVec)
{
    for (int i = 0;i < tamVec ;i++ )
    {
        cout << vec[i] << " ";
    }
}

int main()
{
    TLista lista;
    TVec vec = {{}};
    TMatriz mat = {{
        {{45, -17, 867, 45}},
        {{2, 867, -17, 3}},
        {{1, -2, 45, 3}}
    }};
    // int k;
    // cout << "Introduzca k: "; cin >> k;
    // cout << "Introduzca una matriz " << FILA << " x " << COL << " (fila por fila):" << endl;
    // leerMatriz(mat);

    sacarFrecuencias(lista,mat);
    sacarMayoresFrecuencias(lista,vec);

    if (lista.nElementos < 4)
    {
        cout << "No hay " << 4 << " valores diferentes en la matriz: " << endl;
        escribirMayores(vec,lista.nElementos);
    }
    else
    {
        cout << "Los " << 4 << " que mas se repiten son: " << endl;
        escribirMayores(vec, 4);
    }
    cout << endl;


    if (lista.nElementos < 8)
    {
        cout << "No hay " << 8 << " valores diferentes en la matriz: " << endl;
        escribirMayores(vec,lista.nElementos);
    }
    else
    {
        cout << "Los " << 8 << " que mas se repiten son: " << endl;
        escribirMayores(vec, 8);
    }
    cout << endl;

    if (lista.nElementos < 3)
    {
        cout << "No hay " << 3 << " valores diferentes en la matriz: " << endl;
        escribirMayores(vec,lista.nElementos);
    }
    else
    {
        cout << "Los " << 3 << " que mas se repiten son: " << endl;
        escribirMayores(vec, 3);
    }

    return 0;
}

/*
The values more repeated are: 45 -17 867 3

The values more repeated are: 45 -17 867 3 2 1 -2

The values more repeated are: 45 -17 867
*/
