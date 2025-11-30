#include <iostream>
#include <array>
#include <math.h>

using namespace std;

const int MAX = 10;

typedef array<int, MAX> TArray;

int main(){
    TArray a = {{6, 3, 9, 7, 1, 8, 10, 2, 4, 5}};
    int x, k;
    int y;
    int z;

    x = 0;
    for (int i = 0; i < MAX; i++) { /// ES LA SUMA DE TODOS LOS ELEMENTOS DEL ARARY,
        x += a[i];
    }
    cout << "Suma de todos los valores del vector es : " << x << endl;

    y = a[0];
    for (int i = 1; i < MAX; i++) { /// SELECCIONA EL MAYOR ELEMENTO DEL ARRAY
        if (y < a[i]) {
        y = a[i];
        }
        //cout << y << endl;
    }
    cout << "El mayor elemento es: " << y << endl;

    k = 0;
    for (int i = 1; i < MAX; i++) { /// VA COGIENDO LA POSICION SI EL NUMERO ACTUAL ES MAYOR QUE EL SIGUIENTE
        if (a[k] < a[i]) {          ///Y COUTA EL NUMERO MAYOR DEL ARRAY
        k = i;
        }
    }
    z = a[k];
    cout << z << endl;
return 0;

}
