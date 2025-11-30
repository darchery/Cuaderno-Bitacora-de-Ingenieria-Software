#include <iostream>
#include <array>
#include <cmath>

using namespace std;

const string VACIO = "VACIO";
const double TOPE = 0.01; //valor absoluto menor que 0.01
const int MAX = 10;

struct TInfo {
    string nombre;
    int gastos;
    int pagRec;
};

typedef array<TInfo, MAX> TDatos;

struct TLista {
    TDatos datos;
    int numPersonas = 0;
};

void leerDatos(TLista& lista)
{
    int index = 0;
    bool fin = false;

    cout << "Introduzca nombres y gastos (FIN para terminar)" << endl;
    while (lista.numPersonas < MAX && !fin)
    {
        cout << "Nombre: ";
        cin >> lista.datos[index].nombre;
        if (lista.datos[index].nombre == "FIN")
        {
            fin = true;
        }
        else
        {
            cout << "Gastos: ";
            cin >> lista.datos[index].gastos;
            index++;
            lista.numPersonas++;
        }
    }
}

void estaRepetido(TLista& lista, bool& repetido,int posAct ,int& posRep)
{
    for (int i = posAct + 1;i < lista.numPersonas && !repetido ;i++ )
    {
        if (lista.datos[posAct].nombre == lista.datos[i].nombre)
        {
            repetido = true;
            posRep = i;
            lista.datos[i].nombre = VACIO;
        }
    }
}

void eliminarInputsRepetidos(TLista& lista)
{
    bool repetido;
    int posRep;

    for (int i = 0;i < lista.numPersonas ;i++ )
    {
        repetido = false;
        if (lista.datos[i].nombre != VACIO)
        {
            estaRepetido(lista,repetido,i,posRep);
        }
        if (repetido)
        {
            lista.datos[i].gastos += lista.datos[posRep].gastos;
            lista.datos[posRep].gastos = 0;
        }
        cout << lista.datos[i].nombre << ": " << lista.datos[i].gastos << endl;
    }
}

int mediaGastos(const TLista& lista)
{
    int suma = 0;
    int newNum = 0;

    for (int i = 0;i < lista.numPersonas ;i++ )
    {
        if (lista.datos[i].nombre != VACIO)
        {
            suma += lista.datos[i].gastos;
            newNum++;
        }
    }
    return suma/newNum;
}

void pagarRecibir(TLista& lista, int media)
{
    int diff;

    for (int i = 0;i < lista.numPersonas ;i++ )
    {
        if (lista.datos[i].nombre != VACIO)
        {
            if (lista.datos[i].gastos != media)
            {
                lista.datos[i].pagRec = media - lista.datos[i].gastos;
                diff = lista.datos[i].pagRec;
                if (diff > 0)
                {
                    cout << lista.datos[i].nombre << " debe pagar " << lista.datos[i].pagRec << endl;
                }
                else
                {
                    cout << lista.datos[i].nombre << " debe recibir " << abs(lista.datos[i].pagRec) << endl;
                }
            }
            else
            {
                cout << lista.datos[i].nombre << " esta a la par" << endl;
            }
        }
    }
}

int main(){
    TLista lista;
    int media;

    leerDatos(lista);
    eliminarInputsRepetidos(lista);
    media = mediaGastos(lista);
    cout << "La media de gastos en comun es: " << media << endl;
    cout << endl;
    pagarRecibir(lista, media);
   // ajusteCuentas(lista,media);
return 0;

}

/*
pepe 20 lola 30 pepe 10 juan 40 lola 20 luis 20 ana 30 eva 34 FIN
Nombre: pepe
Gastos: 20
Nombre: lola
Gastos: 30
Nombre: pepe
Gastos: 10
Nombre: juan
Gastos: 40
Nombre: lola
Gastos: 20
Nombre: luis
Gastos: 20
Nombre: ana
Gastos: 30
Nombre: eva
Gastos: 34
Nombre: FIN
*/
/*
bool enPaz(TLista& lista, int media)
{
    bool paz = true;

    for (int i = 0;i < lista.numPersonas && paz ;i++ )
    {
        if (lista.datos[i].nombre != VACIO)
        {
            if (media - lista.datos[i].pagRec > TOPE)
            {
                paz = false;
            }
        }
    }
    return paz;
}

void ajusteCuentas(TLista& lista, int media)
{
    bool devuelto = false;
    int pagarIndex = 0, recIndex = 0;
    int aPagar = lista.datos[0].pagRec;
    int aRecibir = lista.datos[0].pagRec;

    while (!devuelto)
    {
        // El que mas debe pagar (mas grande)
        for (int i = 0;i < lista.numPersonas  ;i++ )
        {
            if (lista.datos[i].nombre != VACIO && aPagar < lista.datos[i].pagRec)
            {
                aPagar = lista.datos[i].pagRec;
                pagarIndex = i;
            }
        }

        // El que mas debe recibir (mas pequeño)
        for (int i = 0;i < lista.numPersonas  ;i++ )
        {
            if (lista.datos[i].nombre != VACIO && aRecibir > lista.datos[i].pagRec)
            {
                aRecibir = lista.datos[i].pagRec;
                recIndex = i;
            }
        }
        // Se calcula cuánto dinero debe pagar P1 a P2, como la menor de las dos cantidades anteriores
        if (abs(aPagar) > abs(aRecibir))
        {
            aPagar = abs(aRecibir);
        }

        // Ajuste
        cout << lista.datos[pagarIndex].nombre << " paga " << lista.datos[pagarIndex].pagRec << " a " << lista.datos[recIndex].nombre << endl;
        lista.datos[pagarIndex].pagRec -= aPagar;
        lista.datos[recIndex].pagRec += aPagar;

        if (enPaz(lista, media))
        {
            devuelto = true;
        }
    }
}
*/
