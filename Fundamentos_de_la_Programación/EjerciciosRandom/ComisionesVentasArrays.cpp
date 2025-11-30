
#include <iostream>
#include <array>
#include <math.h>

/*
• Una empresa tiene 20 agentes de venta (identificados por números
del 1 al 20)

• Los agentes, además de su sueldo mensual, cobran una determinada
comisión si sus ventas excede los 2/3 del promedio de ventas del
grupo (
umbral).

• Se necesita un algoritmo que lea el valor de las ventas realizadas por
cada agente e imprima el número de identificación de aquellos/as
que deban percibir comisión así como el valor correspondiente a sus
ventas.

• Consideraciones:

• Se necesita almacenar durante la ejecución del programa los
valores de las ventas de cada agente: para el cálculo del
promedio y para la comparación sobre el
umbral. Por tanto,
necesitamos 20 variables.
• Se hará un procesamiento similar sobre los datos de cada agente.
*/

/// ESTE PROGRAMA INCIALMENTE ERA BASTANTE INEFICIENTE, PERO CON ALGUNOS RETOQUES SE PUEDE MEJORAR
/// ERROR PRINCIPAL ENCONTRADO ES EL USO DEL FOR EN EL MAIN EL CUAL LLAMA A 3 SUPROGRAMS 20 VECES, ES DECIR 60 VECES
/// PERO AHORA SOLO LOS LLAMA 3 VECES

using namespace std;

const double PORCION = 2.0/3.0;
const int N = 20;

typedef array <double,N> TVentas;

void leerVentas(TVentas& venta)
{
    cout << "Ingrese las ventas de cada agente separadas por espacio." << endl;
    for (int i = 0;i < N ;i++ )
    {
        cout << "Venta del agente " << i+1 << ": ";
        cin >> venta[i];

    }
}

double sumaMediaVentas(TVentas& venta)
{
    double sumaMedia = 0;

    for (int i = 0;i < N ;i++ )
    {
        sumaMedia += venta[i];
    }

    return sumaMedia/N;
}

/*bool superaUmbral(TVentas& venta,double dinero, double umbral)       /// ESTA FUNCION ES INNECESARIA, ES MAS EFICIENTE DESARROLLAR ESTE PROGRAMA SIN ELLA
{
    bool supera = false;
    if (dinero > umbral)
    {
        supera = true;
    }
    return supera;
}*/

void imprimirComision(TVentas& venta, double umbral)                /// VERSION MAS EFICIENTE
{
    for (int i = 0;i < N ;i++ )
    {
        if (venta[i] > umbral)
        {
            cout << "Ventas del agente comercial " << i+1 << ": " << venta[i];
            cout << endl;
        }
    }
}

/*void imprimirComision(TVentas& venta, double umbral)
{
    for (int i = 0;i < N ;i++ )
    {
        if (superaUmbral(venta, venta[i],umbral))
        {
            cout << "Ventas del agente comercial " << i+1 << ": " << venta[i];
            cout << endl;
        }
    }
}*/

int main(){
    TVentas venta;

    leerVentas(venta);
    double umbral = PORCION * sumaMediaVentas(venta);
    imprimirComision(venta, umbral);
return 0;

}

    /*for (int i = 0;i < N ;i++ )
    {
        dinero = venta[i];
        if (superaUmbral(venta, dinero,umbral))
        {
            imprimirComision(dinero, i+1);
        }
    }*/
    // ESTE ES ANTIGUO BUCLE QUE CONSUMIA DEMASIADA MEMORIA

/*
#include <iostream>
#include <array>

using namespace std;

const double PORCION = 2.0/3.0;
const int NUM_AGENTES = 20

typedef array<double, NUM_AGENTES> TVentas;

void leer(TVentas& ventas) {
    for (int i = 0; i < NUM_AGENTES; i++) {
        cout<<"Introduzca ventas del agente "<<i+1<<": ";
        cin>>ventas[i];
    }
}

double media(const TVentas& ventas) {
    double suma = 0.0;
    for (double v : ventas) {
    suma += v;
    }
    return suma/ventas.size();
}

void imprimir(const TVentas& ventas, double umbral)
{
    for (int i = 0; i < NUM_AGENTES; i++) {
        if (ventas[i] > umbral) {
            cout<<"Ventas del Agente "<< i+1 <<": "<<ventas[i] << endl;
        }
    }
}

int main() {
    TVentas ventas;
    double umbral;

    leer(ventas);
    umbral= PORCION * media(ventas);
    imprimir(ventas, umbral);
return 0;
}
*/
