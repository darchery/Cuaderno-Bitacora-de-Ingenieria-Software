#include <iostream>
#include <array>
#include <math.h>
#include <string.h>

using namespace std;

//AZTECA
const int PUNTO = 1;
const int BANDERA = 20;
const int PLUMA = 400;
const int BOLSA = 8000;
//ROMANO
const int I = 1;
const int V = 5;
const int X = 10;
const int L = 50;
const int C = 100;
const int D = 500;
const int M = 1000;


int main(){
    string sistemaNumerico="";

    //BINDEC
    int numBin, numDec=0, elevado=0, numBinCout;
    //AZTECA
    string simbolo;
    int totalAzteca=0;
    //ROMANO
    string letra;
    int totalRomano=0;
    //ARAMEO

    cout << "Sistemas numericos disponibles: binario a decimal (bindec), azteca, tomano y arameo." << endl;
    cout << "Introdue el tipo de sistema numerico: "  << endl;
    cin >> sistemaNumerico;

    if (sistemaNumerico != "azteca" && sistemaNumerico != "romano" && sistemaNumerico != "arameo" && sistemaNumerico != "bindec")
    {
         cout << "No tenemos conversion para ese sistema numerico, lo sentimos..." << endl;
    }
    else
    {
        if (sistemaNumerico=="bindec")
        {
            cout <<"\n";
            cout << "Bienvenido al modo de Binario a Decimal " << endl;
            cout << "Introduzca el numero binario: ";
            cin >> numBin;

            numBinCout = numBin;

                if (numBin==0)
                {
                    cout <<" 0 en decimal es 0" << endl;
                }
                    else
                    {
                        while(numBin > 0)
                        {
                            numDec += numBin%10*(pow(2,elevado));
                            numBin /= 10;
                            elevado++;
                        }
                        cout << "El numero " << numBinCout << " en decimal es " << numDec << endl;
                    }
        }

        else if (sistemaNumerico=="azteca")
        {
            cout <<"\n";
            cout << "Bienvenido al modo azteca"<< endl;
            cout <<"Instrucciones de uso: "<< endl;
            cout <<"Usted tiene que introducir nombres de simbolos para representar numeros, acabados por un espacio y un punto (.) "<< endl;
            cout << "Valores: " << endl << "punto: 1" << endl << "bandera: 20" << endl << "pluma: 400" << endl << "bolsa: 8000" << endl;
            cout << "Introduce los simbolos correspondientes: ";
            cin >> simbolo;

            while (simbolo !=".")
            {

                if(simbolo=="punto")
                {
                    totalAzteca += PUNTO;
                }
                    else if(simbolo=="bandera")
                    {
                        totalAzteca += BANDERA;
                    }
                        else if(simbolo=="pluma")
                        {
                            totalAzteca += PLUMA;
                        }
                            else if(simbolo=="bolsa")
                            {
                                totalAzteca += BOLSA;
                            }
                cin >> simbolo;
            }

            cout <<"El resultado es: " << totalAzteca << endl;
        }

        else if ( sistemaNumerico == "romano")
        {
            cout <<"\n";
            cout << "Bienvenido al modo romano"<< endl;
            cout <<"Instrucciones de uso: "<< endl;
            cout <<"Usted tiene que introducir letras para representar numeros, acabados por un espacio y un punto (.) "<< endl;
            cout << "Valores: " << endl << "I: 1" << endl << "V: 5" << endl << "X: 10" << endl << "L: 50" << endl << "C: 100" << endl << "D: 500" << endl << "M: 1000" << endl;
            cout << "Introduce los simbolos correspondientes: ";
            cin >> letra;

            while (letra != ".") // PONER UN FOR CON CIN PORQUE SE PELAN LOS ESPACIOS, PARA IMPLEMENTAR LA SUBSTRACCION DE LETRAS DE MENOR VALOR A LETRAS DE MAYOR VALOR
            {
                if(letra=="M")
                {
                    totalRomano += M;
                }
                    else if(letra=="D")
                    {
                        totalRomano += D;
                    }
                        else if(letra=="C")
                        {
                            totalRomano += C;
                        }
                            else if(letra=="L")
                            {
                                totalRomano += L;
                            }
                                else if(letra=="X")
                                {
                                    totalRomano += X;
                                }
                                    else if(letra=="V")
                                    {
                                        totalRomano += V;
                                    }
                                        else if(letra=="I")
                                        {
                                            totalRomano += I;
                                        }
                cin >> letra;
            }
                cout <<"El resultado es: " << totalRomano << endl;
        }
    }

   /* if (secRomana[i]=="I" && secRomana[i+1]=="V")
    {
        valorFinal = V - 1;
    }
        */
return 0;

}
