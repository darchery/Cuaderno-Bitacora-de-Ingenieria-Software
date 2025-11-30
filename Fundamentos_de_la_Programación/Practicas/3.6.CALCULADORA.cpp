#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int main(){
    char operador;
    int op1, op2;
    int resultado=0;

        while (operador != '&')
        {
            cout <<"Operador (+ - * / &): ";
            cin >> operador;

            if (operador == '+')
            {
                cout << "Operando 1: ";
                cin >> op1;
                cout << "Operando 2: ";
                cin >> op2;
                resultado = op1 + op2;
                cout <<"Resultado: " << resultado << endl;
            }
                else if (operador == '-')
                {
                    cout << "Operando 1: ";
                    cin >> op1;
                    cout << "Operando 2: ";
                    cin >> op2;
                    resultado = op1 - op2;
                    cout <<"Resultado: " << resultado << endl;
                }
                    else if (operador == '*')
                    {
                        cout << "Operando 1: ";
                        cin >> op1;
                        cout << "Operando 2: ";
                        cin >> op2;
                        resultado = op1 * op2;
                        cout <<"Resultado: " << resultado << endl;
                    }
                        else if (operador == '/')
                        {
                            cout << "Operando 1: ";
                            cin >> op1;
                            cout << "Operando 2: ";
                            cin >> op2;

                            if (op2 == 0)
                            {
                                cout << "NO se puede DIVIDIR entre CERO..." << endl;
                            }
                            else{
                                resultado = op1 / op2;
                                cout <<"Resultado: " << resultado << endl;
                            }
                        }

                                else if (operador == '&')
                                {
                                    cout << "FIN DEL PROGRAMA" << endl;
                                }

                                    else
                                    {
                                        cout <<"ERROR: Operacion no valida" << endl;
                                    }
        }

return 0;

}
