#include <iostream>

using namespace std;

const int SEM =604800;
const int DIA=84600;
const int HORA=3600;
const int MIN=60;

int main()
{
    int seg, min, hor, dia, sem;
    cout << "Introduce los segundos para convertirlos: " << endl;
    cin >> seg;

    sem = seg/SEM;
    seg = seg%SEM;

    dia = seg/DIA;
    seg = seg%DIA;

    hor = seg /HORA;
    seg = seg%HORA;

    min = seg/MIN;
    seg = seg%MIN;

cout << "Son " << sem << " semanas, " << dia << " dias, " << hor << " horas, " << min << " minutos y " << seg << " segundos" << endl;
    
  

 return 0;
}