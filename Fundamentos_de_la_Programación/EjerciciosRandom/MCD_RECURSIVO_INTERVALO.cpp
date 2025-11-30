#include <iostream>
#include <array>
#include <math.h>

// M > N > 0

using namespace std;

int mcdRec(int n,int m)
{
    int res = 1;

    if (m == n)
    {
        res = m;
    }
    else if (m > n)
    {
        res = mcdRec(n,m-n);
    }
    else
    {
        res = mcdRec(n-m,m);
    }
    return res;
}

int main(){
    int m, n;
    int sum = 0;
    do
    {
        cout << "Introduzca n y m(m > n): ";
        cin >> n >> m;
    } while (m < n && m <= 0 && n <= 0);

    for (int i = n;i <= m ;i++ )
    {
        sum += mcdRec(i,m);
        cout << "MCD de " << i << " y " << m << " es: " << mcdRec(i,m) << endl;
    }
    cout << "La suma de los MCD desde " << n << " hasta " << m << " es: " << sum << endl;


return 0;

}
