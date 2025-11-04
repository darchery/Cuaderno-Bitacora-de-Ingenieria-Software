package org.example;

public class SubSecuenciaMasLargaNoNecesariamenteConsecutiva {

    public int[] L_NoSeguidaNecesarimente (int[] x, int y[]) {
        int n = x.length;
        int m = y.length;
        int[][] SCL = new int[n+1][m+1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    SCL[i][j] = 0;
                } else if (x[i] == y[j]) {
                    SCL[i][j] = SCL[i-1][j-1] + 1;  // Ese 1 se va a ir acumulando por las casillas
                }                                   // es el aumento de la distancia
                else {
                    SCL[i][j] = Math.max(SCL[i-1][j], SCL[i][j-1]);
                }
            }
        }
        
        // Encontramos la solución
        int[] L = new int[2];
        int i = n;
        int j = m;
        
        while (i > 0) {
            if () {
                
            } else if () {
                
            }
        }
        // Evaluar el 0 ya que no lo coge
        return L;
    }*/

/*
    public int[] L_Seguida (int[] x, int y[]) {
        int n = x.length;
        int m = y.length;
        int[][] SCL = new int[n+1][m+1];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == 0 || j == 0) {
                        SCL[i][j] = 0;
                    } else if (x[i] == y[j]) {
                        SCL[i][j] = Math.max(SCL[i-1][j-1] + 1, SCL[i-1][j], SCL[i][j-1]);
                    }                                   // Elegimos el maximo entre el siguiente caracter de ambos
                                                        // o el siguiente caracater de cada uno por separado
                    else {
                        SCL[i][j] = Math.max(SCL[i-1][j], SCL[i][j-1]);
                    }                                   // Elegimos el siguiente caracter de x o de y
                }

        }
    }*/
}
