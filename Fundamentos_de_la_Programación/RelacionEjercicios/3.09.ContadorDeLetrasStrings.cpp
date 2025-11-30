#include <iostream>
#include <array>
#include <math.h>
#include <string>

using namespace std;

void leerSec(string& secuencia)
{
    cout << "Introduzca una secuencia de letras mayusculas (punto para terminar): ";
    getline(cin, secuencia, '.');
}

/*
int primeraAparicionLetra(string& secuencia, char letra)
{
    int pos;
    bool found = false;

    for (int i = 0;i < secuencia.size() && found == false ;i++ )
    {
        if (letra == secuencia[i])
        {
            pos = i;
            found = true;
        }
    }
    return pos;
}
*/

bool repite(string& secuencia, int pos)
{
    bool seRep = false;

    for (size_t i = pos + 1 ;i < secuencia.size() - 1 && seRep == false ;i++ )
    {
        if (secuencia[pos] == secuencia[i]) /// AQUI LA LOGICA QUE USAMOS ES NO IMPRIMIR LA PRIMERA LETRA QUE ENCONTREMOS , SINO LA ULTIMA,
        {                                   /// ASÍ NOS ASEGURAMOS NO TENER TRIFURCAS ENTRE LETRAS REPETIDAS SIGUIENTES
            seRep = true;                   // ERROR COMETIDO: ENFORCARLO DE LA MANERA OPUESTA, TEORICAMENTE MI PROGRMA FUNCIONARIA PERO NOSE PORQUE
        }                                   // NO LO HACE, MI LOGICA ERA COMPARAR LA PRIMERA POSICION EN LA QUE APARECE LA LETRA DESEADA PARA IMPRIMIR SU FRECUENCIA
    }                                       // Y SI ESTA POSICION ES MAYOR, ESO QUIERE DECIR QUE YA HA APERECIDO ANTES Y POR LO TANTO NO HACE FALTA IMPRIMIRLA DE NUEVO
    return seRep;                           // EJ: BAA, CUANDO LLEGUE A sec[2] = A, va a comparar posPrimerA = 1 con posactualA = 2, como 2 > 1 este ya apareció antes
}                                           // Y POR LO TANTO NO SE IMPRIMIRIA, PORQUE YA SE HABRÍA IMPRESO ANTES
/*
bool repite(string secuencia, int pos)
{
    bool seRep = false;

    for (int i = 0;i < secuencia.size() - 1 && seRep == false ;i++ )
    {
        if (pos > primeraAparicionLetra(secuencia, secuencia[i]) )
        {
            seRep = true;
        }
    }
    return seRep;
}
*/

void imprimirLetras(string& secuencia, char letra)
{
    int cnt = 0;

    for (size_t i = 0;i < secuencia.size() ;i++ )
    {
        if (letra == secuencia[i])
        {
            cnt++;
        }
    }
    cout << letra << ": " << cnt << endl;
}

void analizaRepe(string& secuencia)
{
    for (size_t i = 0;i < secuencia.size() ;i++ )
    {
        if (!repite(secuencia, i))
        {
            imprimirLetras(secuencia, secuencia[i]);
        }
    }
}

int main(){
    string secuencia;

    leerSec(secuencia);
    analizaRepe(secuencia);
return 0;

}
