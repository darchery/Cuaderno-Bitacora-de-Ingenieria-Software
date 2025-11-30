#include <iostream>
#include <array>
#include <math.h>
#include <cassert>

using namespace std;

const int MAX_PER = 10;
const double UMBRAL = 1e-3;

struct Persona {
    string nombre;
    int gastos = 0;
};

typedef array<Persona, MAX_PER> TPersona;

struct TLista {
    TPersona personas;
    int nPer = 0;
};

double menor(double x, double y)
{
    int m = x;

    if (x > y)
    {
        m = y;
    }
    return m;
}

double valorAbsoluto(double num)
{
    if (num < 0)
    {
        num = -num;
    }
    return num;
}

bool esCero(double num)
{
	return valorAbsoluto(num) < UMBRAL;
}

void leer(Persona& per)
{
    cout << "Nombre: ";
	cin >> per.nombre;
	if (per.nombre != "FIN") {
		cout << "Gastos: ";
		cin >> per.gastos;
	}
}

int buscarPersona(const TLista& lista, Persona& per, int posAct)
{
    int index = -1;
    bool found = false;

    for (int i = posAct - 1;i >= 0 && !found;i-- )
    {
        if (per.nombre == lista.personas[i].nombre)
        {
            found = true;
            index = i;
        }
    }
    return index;
}

void procesarPersona(TLista& lista, Persona& per)
{
    int indexPer = buscarPersona(lista,per,lista.nPer);

    // Primera aparicion
    if (indexPer == -1)
    {
        lista.personas[lista.nPer].nombre = per.nombre;
        lista.personas[lista.nPer].gastos += per.gastos;
        lista.nPer++;
    }
    // Ya ha aparecido
    else
    {
        lista.personas[indexPer].gastos += per.gastos;
    }
}

void leerDatos(TLista& lista)
{
    Persona per;

    leer(per);
    while (per.nombre != "FIN")
    {
        procesarPersona(lista,per);
        leer(per);
    }
}

void mostrarDatos(const TLista& lista)
{
    for (int i = 0;i < lista.nPer;i++ )
    {
        cout << lista.personas[i].nombre << " ha gastado en comun " << lista.personas[i].gastos << endl;
    }
}

double mediaGastos(const TLista& lista)
{
    double sumaGatos = 0;

    for (int i = 0;i < lista.nPer ;i++ )
    {
        sumaGatos += lista.personas[i].gastos;
    }
    return sumaGatos/lista.nPer;
}

void diferenciaGastos(const TLista& lista, TLista& lista_diff, double media)
{
    lista_diff = lista;

    for (int i = 0;i < lista_diff.nPer;i++ )
    {
        lista_diff.personas[i].gastos -= media;
    }
}

void mostrarDiff(const TLista& lista_diff)
{
    for (int i = 0;i < lista_diff.nPer ;i++ )
    {
        if (lista_diff.personas[i].gastos < 0)
        {
            cout << lista_diff.personas[i].nombre << " le debe pagar " << valorAbsoluto(lista_diff.personas[i].gastos) << endl;
        }
        else if (lista_diff.personas[i].gastos > 0)
        {
            cout << lista_diff.personas[i].nombre << " debe recibir " << valorAbsoluto(lista_diff.personas[i].gastos) << endl;
        }
        else
        {
            cout << lista_diff.personas[i].nombre << " esta a la par" << endl;
        }
    }
}

void indexMayorMenor(const TLista& lista_mov, int& indexMayor, int& indexMenor)
{
    indexMayor = 0;
    indexMenor = 0;

    for (int i = 1;i < lista_mov.nPer ;i++ )
    {
        if (lista_mov.personas[indexMayor].gastos < lista_mov.personas[i].gastos)
        {
            indexMayor = i;
        }
        else if (lista_mov.personas[indexMenor].gastos > lista_mov.personas[i].gastos)
        {
            indexMenor = i;
        }
    }
}

bool todosCero(const TLista& lista_mov)
{
    bool cero = true;

    for (int i = 0;i < lista_mov.nPer && cero;i++ )
    {
        if (!esCero(lista_mov.personas[i].gastos) )
        {
            cero = false;
        }
    }
    return cero;
}

void movimientosPagos(TLista& lista_mov)
{
    cout << endl;
	while (!todosCero(lista_mov))
    {
		int indexMayor, indexMenor;

		indexMayorMenor(lista_mov, indexMayor, indexMenor);

		// Comprueba que cumplan esas condiciones y sino para el programa
		assert(lista_mov.personas[indexMayor].gastos > 0);
		assert(lista_mov.personas[indexMenor].gastos < 0);

		// Aqui saca un numero menor entre el mayor gasto y el menor
		// El menor paga y el mayor recibe
		double dd = menor( valorAbsoluto(lista_mov.personas[indexMayor].gastos), valorAbsoluto(lista_mov.personas[indexMenor].gastos) );
		cout << lista_mov.personas[indexMenor].nombre << " paga " << dd << " a " << lista_mov.personas[indexMayor].nombre << endl;

        lista_mov.personas[indexMenor].gastos += dd;
		lista_mov.personas[indexMayor].gastos -= dd;

	}
}

void ajustarCuentas(TLista& lista)
{
    double media = mediaGastos(lista);
    cout << "La media de los gastos en comun es: " << media << endl;
    TLista lista_diff;
    diferenciaGastos(lista,lista_diff,media);
    cout << endl;
    mostrarDiff(lista_diff);
    TLista lista_mov = lista_diff;
	movimientosPagos(lista_mov);
}

int main(){
    TLista lista;

    leerDatos(lista);
    mostrarDatos(lista);
    cout << endl;
    ajustarCuentas(lista);
return 0;

}

// pepe 20 lola 30 pepe 10 juan 40 lola 20 luis 20 ana 30 eva 34 FIN
