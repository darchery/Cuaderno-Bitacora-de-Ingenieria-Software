#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main()
{
    int num, N;
    int max; 
    int min;
    int cnt;
    double media = 0.0;



    cout << "Introduce la secuencia: " << endl;
    cin >> num;
    N = num;
    max= num;
    min = num;
    cnt=num;

    
    for (int i = 0; i < N  &&  num!=0; i++)
    {   
        if (num > max)
        {
            max = num;
        }
        else if (num < min)
        {
            min = num;
        }
       //cout <<"Numero actual:  "  <<num << endl;
        media +=num;
       // cout <<"Media; " <<media << endl;
        cin >> num;
    }
    
    cout << "Numero mayor: " << max << endl;
    cout << "Numero menor: " << min << endl;
    cout << "Media: " << media/cnt << endl;
    cout << cnt;

    return 0;
    //ARREGLAR
}



/*
int n;
    cout << "Introduce la secuecia: " << endl;
    cin >> n;
    int sec[n];
 
    while ((n-1)!=0)
    {
        cin >> sec[n];
        n=n-1;
    }*/

    /*
        int N,num;
    int max; 
    int min;
    double media = 0.0;

    cout << "Introduce el numero de  elementos: " << endl;
    cin >> N;


    cout << "Introduce la secuencia: " << endl;
    cin >> max;
    min = max;
    media = max;

    
    for (int i = 1; i < N; i++)
    {
        
        cin >> num;
        
        if (num > max)
        {
            max = num;
        }
        else if (num < min)
        {
            min = num;
        }
        media +=num;
    }
    
    cout << "Numero mayor: " << max << endl;
    cout << "Numero menor: " << min << endl;
    cout << "Media: " << media/N << endl;
    */