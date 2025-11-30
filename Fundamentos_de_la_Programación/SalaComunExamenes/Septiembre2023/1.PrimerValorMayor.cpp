#include <iostream>
#include <array>
using namespace std;

const int NMAX = 10;
typedef array<int, NMAX> TVec;

int calcularMedia(TVec& vec)
{
    int suma = 0;

    for (int i = 0;i < NMAX ;i++ )
    {
        suma += vec[i];
    }
    return suma/NMAX;
}

int primerIndiceMayorMedia(TVec& vec, int media)
{
    int index = 0;
    bool found = false;

    for (int i = 0;i < NMAX && !found;i++ )
    {
        if (vec[i] > media)
        {
            index = i;
            found = true;
        }
    }
    return index;
}

int main()
{
	TVec a = {3, 1, 4, 0, 7, 2, 5, 9, 8, 6};
    int media = calcularMedia(a);

	cout << "El primer valor mayor o igual que la media esta en el indice: "
	     <<  primerIndiceMayorMedia(a,media) << endl;
    return 0;
}
