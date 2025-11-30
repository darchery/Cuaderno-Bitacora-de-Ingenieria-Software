#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int const FILAS = 5;    // QUE A SU VEZ ES EL ESPACIO QUE TIENE CADA COLUMNA  A  RELLANR
int const COLUMNAS = 3; // QUE A SU VEZ SON LOS ESPACIOS QUE TIENE CAD FILA A RELLENAR
typedef array<int, COLUMNAS> TFila;
typedef array<TFila, FILAS> TMatriz;
// ESTA FORMA ES MEJOR POQUE ASI PUEDO PASAR FILAS

/*
const int NFILAS=5;
const int NCOLUMNAS=3;
typedef array<array<int,NCOLUMNAS>,NFILAS> TMatriz;*/
// CON ESTA FORMA NO SE PODRÍA

int main(){
    TMatriz matriz;

    // matriz[i = 2]; Nos referimos a toda la fila 2
    // matriz[3][0]; Nos referimos a la fila 3 en la columna 0
    /// IMPORTANTE: NO NOS PODEMOS REFERIR DIRECTAMENTE A UNA COLUMNA COMO A UNA FILA, FILA: matriz[1] PERO NO PODEMOS HACER matrix[][1]

    // Declarar una matriz constante
    const TMatriz a = {{ {{1, 2, 3}},
                         {{4, 5, 7}},
                         {{8, 9, 10}},
                         {{11, 12, 13}},
                         {{14, 15, 16}},
                      }};
return 0;

}
