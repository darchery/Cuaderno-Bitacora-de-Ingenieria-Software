#include <iostream>
#include <array>

using namespace std ;

const int TAM = 10;
typedef array < int , TAM > TArray ;

bool seRepite(TArray& a, int& value)
{
    int rep = 0; // SI ES MAYOR DE 1, SE REPITE Y NO ES ESTRICTO
    bool repite = false;

    for (int i = 0;i < TAM && !repite ;i++ )
    {
        //cout << "Repticiones de " << value << ": " << rep << endl;
        if (value == a[i])
        {
            rep++;
        }
        if (rep > 1)
        {
            repite = true;
        }
    }
    return repite;
}

void strictSmallest(TArray& a, bool& found, int& value)
{
    int menorEstrict = a[0];

    for (int i = 1;i < TAM ;i++ )
    {
        /*cout << "Menor act: " << menorEstrict << endl;
        cout << "Val actual: " << a[i] << endl;
        cout << endl;*/
        if (menorEstrict > a[i])
        {
            menorEstrict = a[i];
        }
    }
    value = menorEstrict;;
    if (seRepite(a, value))
    {
        found = false;
    }
    else
    {
        found = true;
    }
}

int main ()
{
    TArray a1 = {{4 , 7 , 5 , 3 , 5 , 7 , 9 , 32 , 45 , 8}};
    TArray a2 = {{4 , 7 , 5 , 3 , 5 , 7 , 3 , 32 , 45 , 8}};
    TArray a3 = {{4 , 7 , 5 , 3 , 5 , 7 , 3 , 32 , 2 , 8}};
    bool found ;
    int value ;

    strictSmallest ( a1 , found , value ) ;
    if ( found ) cout << " The strict smallest value of first array is : " << value << endl ;
    else cout << " The first array has not strict smallest " << endl ;

    strictSmallest ( a2 , found , value ) ;
    if ( found ) cout << " The strict smallest value of second array is : " << value << endl ;
    else cout << " The second array has not strict smallest " << endl ;

    strictSmallest ( a3 , found , value ) ;
    if ( found ) cout << " The strict smallest value of third array is : " << value << endl ;
    else cout << " The third array has not strict smallest " << endl ;
return 0;
}
