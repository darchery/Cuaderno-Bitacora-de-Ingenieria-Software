#include <iostream>

using namespace std;

/*
Considerando que 1 KByte es equivalente a 1024 Bytes, y 1 MByte es equivalente a 1024
KBytes).

 Por ejemplo, dado el número 26871979, el resultado sería 25 MBytes, 642 KBytes
y 171 Bytes, ya que 26871979 Bytes = 25 MBytes + 642 KBytes + 171 Bytes.

MByte 10 ceros

*/

const int KByte = 1024;
const int MByte = 1024*KByte;

int main()
{
    int byte,kbyte,mbyte;
    cout << "Introduce los bytes para dividirlo: " << endl;
    cin >> byte;
    
    mbyte = byte/MByte;
    byte = byte%MByte;

    kbyte = byte/KByte;
    byte = byte%KByte;

    
    cout << "Son "<< mbyte <<" MBytes, "<< kbyte << " KBytes y "<< byte <<" bytes"<< endl;
    
return 0;
}