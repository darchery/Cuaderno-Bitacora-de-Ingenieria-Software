package org.example;

import java.util.Arrays;
import java.util.Scanner;

public class CambioMonedas {
    private int [] sol;
    private int [] denom;
    private int [] cantidad;
    private int M;
    private int num_monedas; //El coste de la solución actual


    /*
     * Constructor de la clase
     */
    public CambioMonedas(int[] readVector, int[] readVector2, int[] readVector3) {
        sol = new int[readVector.length];
        denom = readVector;
        cantidad = readVector2;
        M = readVector3[0];
        num_monedas = Integer.MAX_VALUE; //Iniciamos el número de monedas a infinito para indicar que no tenemos aún solución.
        // Si el problema no tiene solución, esta propiedad no debería actualizarse.
    }

    /*
     * Dado un objeto instanciado de la clase CambioMonedas, este método haya la solución óptima.
     */
    void vueltaAtras() {
        int[] cantidadAux = cantidad;
        int[] solParcial = new int[sol.length];
        asignamosMonedasAlMonto(cantidadAux, solParcial, 0, 0);
    }

    private void asignamosMonedasAlMonto(int[] cantidadAux, int[] solParcial, int mAux, int numMonedasAux) {
        boolean foundSol = false;

        // Caso base 0: ya se llegó a la solución
        if (mAux == M) {
            if (numMonedasAux < num_monedas) {
                num_monedas = numMonedasAux;
                copiarArray(solParcial);
            }
            foundSol = true;
        }

        if (mAux > M) {
            return; // No es posible dar ese cambio
        }

        if (numMonedasAux >= num_monedas) {
            return; // Ya hemos conseguido está solución antes
        }

        // Caso general: probamos las denominaciones
        if (!foundSol) {
            for (int i = 0; i < denom.length; i++) {
                // Quedan monedas de esa denominación
                if (cantidadAux[i] > 0) {
                    // Asignamos una moneda al monto
                    solParcial[i]++;
                    mAux += denom[i];
                    cantidadAux[i]--;

                    // Actualizamos el numero de monedas
                    numMonedasAux++;

                    // Es una solucion parcial óptima
                    if (numMonedasAux < num_monedas) {
                        asignamosMonedasAlMonto(cantidadAux,solParcial,mAux,numMonedasAux);
                    }
                    // Si no -> deshacemos el cambio
                    solParcial[i]--;
                    mAux -= denom[i];
                    cantidadAux[i]++;
                    numMonedasAux--;
                }
            }
        }
    }

    private void copiarArray(int[] solParcial) {
        for (int i = 0; i < denom.length; i++) {
            sol[i] = solParcial[i];
        }
    }

    private static  int[] readVector(Scanner scanner) {

        String[] temp = scanner.nextLine().split(" ");
        int tam = temp.length;
        int []matrix = new int[tam];
        for (int j = 0; j < tam; j++) {
            matrix[j] = Integer.parseInt(temp[j]);
        }

        return matrix;
    }

    public static void main(String[] args) {
        // NO ES NECESARIO EDITAR ESTE METODO.
        Scanner sc=new Scanner(System.in);
        CambioMonedas c=new CambioMonedas(readVector(sc),readVector(sc),readVector(sc));
        sc.close();

        c.vueltaAtras();
        if (c.num_monedas<Integer.MAX_VALUE) {
            System.out.println("La solución es: "+Arrays.toString(c.sol));
            System.out.println("Con: "+c.num_monedas+" monedas");
        }
        else System.out.println("No hay solución");

    }

}