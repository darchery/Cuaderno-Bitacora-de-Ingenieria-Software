package org.example;

public class CoeficientesBinomiales {
    /**
     *      0 1 2 3 . k
     *    0 1
     *    1 1 1
     *    2 1 2 1
     *    3 1 3 3 1
     *    .
     *    n
     *
     *   Para calcular CB(n, k) -> CB(n-1, k-1) + CB(n-1, k)
     *   Informalmente: se puede calcular sumando la diagonal anterior y el que tiene por encima
     * */

    // Versión con triangulo de pascal (bottom - top)
    private int CB(int n, int k) {
        int[][] trianguloPascal = new int[n+1][k+1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= Math.min(n,k); j++) {
                if (j == 0 || i == j) {
                    trianguloPascal[i][j] = 1;
                } else {
                    trianguloPascal[i][j] = trianguloPascal[i-1][j-1] + trianguloPascal[i-1][j];
                }
            }
        }
        return trianguloPascal[n][k];
    }

    // Versión con uso de menos memoria (top - bottom)
    private int cb(int n, int k) {
        int[][] CB = new int[n+1][k+1];
        return cbRec(n, k, CB);
    }

    private int cbRec(int n, int k, int[][] cbAux) {
        // Si es cero es que el valor NO está calculado y por lo tanto lo calcula
        if (cbAux[n][k] == 0) {
            if (n == k || k == 0) {
                cbAux[n][k] = 1;
            } else {
                cbAux[n][k] = cbRec(n-1, k-1, cbAux) + cbRec(n-1, k, cbAux);
            }
        }
        // De lo contrario SI YA está calculado salta aquí y envía el resultado
        return cbAux[n][k];
    }
}
