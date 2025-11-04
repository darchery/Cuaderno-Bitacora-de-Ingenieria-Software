package org.example;

public class Fibonacci {

    // Versión recursiva simple
    private int fibRec(int n) {
        if (n <= 1) {   // Si n = 0 o n = 1 -> 1
            return 1;
        } else {
            return fibRec(n-1) + fibRec(n-2);
        }
    }

    // Versión array aux donde guardamos los datos de fibonacci
    private int[] fibPrConArray(int n) {
        int[] valoresFib = new int[n];

        valoresFib[0] = 1;
        valoresFib[1] = 1;
        for (int i = 2; i <= n; i++) {
            valoresFib[i] = valoresFib[i-1] + valoresFib[i-2];
        }
        return  valoresFib;
    }

    // Versión final en la que solo uso los 2 últimos valores para calcular
    private int finPr(int n) {
        if (n <= 1) {
            return 1;
        } else {
            int suma = 0, fibAct, fibPrev;

            fibAct = 1;
            fibPrev = 1;
            for (int i = 2; i <= n; i++) {
                suma = fibAct + fibPrev;
                fibPrev = fibAct;
                fibAct = suma;
            }
            return suma;
        }
    }
}


