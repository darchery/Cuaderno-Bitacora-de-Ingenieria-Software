#include <iostream>
#include <string>
#include <array>
#include <math.h>

using namespace std;


void leerCodigo(string& codigo)
{
    string cGrupo, cEditor, cLibro;

    do
    {
        cout << "Introduzca el codigo de grupo: ";
        cin >> cGrupo;
    } while (cGrupo.size() != 1);
    cout << endl;

    do
    {
        cout << "Introduzca el codigo del editor: ";
        cin >> cEditor;
    } while (cEditor.size() != 4);
    cout << endl;

    do
    {
        cout << "Introduzca el codigo del libro: ";
        cin >> cLibro;
    } while (cLibro.size() != 4);
    cout << endl;

    codigo = cGrupo + cEditor + cLibro;
}

void calcularCodigoControl(string& codigo)
{
    int suma = 0;
    int codInt = stoi(codigo);
    int aux;

    for (int i = 9;i >= 0  ;i-- )
    {
        aux = codInt % 10;
        suma += aux * i;
        codInt /= 10;
    }
    cout << suma << endl;
    cout << "Res: ISBN " << codigo;
    if ( suma % 11 == 10)
    {
        cout << 'X';
    }
    else{
        cout << suma % 11;
    }
}

int main(){
    string codigo;

    leerCodigo(codigo);
    calcularCodigoControl(codigo);
return 0;

}
