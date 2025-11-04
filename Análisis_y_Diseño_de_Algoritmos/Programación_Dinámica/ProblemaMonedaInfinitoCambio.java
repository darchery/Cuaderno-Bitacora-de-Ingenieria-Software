package org.example;

public class ProblemaMonedaInfinitoCambio {

    public int[] cambioInfinito(int[] d, int C) {
        int n = d.length;
        int[][] NM = new int[n][C+1];
        int INFINITO = Integer.MAX_VALUE/2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= C ; j++) {
                if (j == 0) {                           // No hay dinero que repartir
                    NM[i][j] = 0;
                } else if (i == 0 && j % d[0] == 0) {   // El monto es divisible entre la primera moneda
                    NM[i][j] = j/d[0];
                } else if (i == 0 && j % d[0] != 0) {   // El monto no es divisible entre la primera moneda
                    NM[i][j] = INFINITO;
                } else if (d[0] > j) {                  // Si el cambio es mayor que el monto se coje otro cambio
                    NM[i][j] = NM[i-1][j];
                } else {
                    NM[i][j] = Math.min(NM[i-1][j], 1+ NM[i][j-d[i]]);  // Elegir si con la antigua el NM es menor que
                }                                                       // meter una nueva
            }
        }
        // En este punto tenemos la matriz preparada


        /*
        * Ahora creamremos el array solución con n espacios, para n número de monedas mínimo
        * Ahora debemos pensar donde está la solución
        * Por la naturaleza de los indices la solución no está en NM[n][C] si no en NM[n-1][C]
        * */
        int[] sol = new int[n];
        int i = n-1;
        int j = C;

        /*
        * La clave es buscar donde se han producido los saltos, buscar los puntos críticos
        * Eston se encuentran si el NM anterior a ese es diferente que este, eso quiere decir que justo ha cambiado
        * de numero de monedas mínimo.
        * Como empezamos por el final nos aseguramos que el primer valor que sea igual al anterior es un cambio solución
        * cuando lo es no cambiamos de cambio(mantenemos)
        * Pero cauando son diferentes indica que este cambio no es necesario ya que no ha producido una reducción
        * */
        while (i > 0) {
            if (NM[i][j] != NM[i-1][j]) {   // Si es diferente cambiamos de cambio
                i--;
            } else {
                sol[i]++;
                j -= d[i];  // Le restamos a C el valor del cambio y no cambiamos de camnbio
            }
        }
        sol[0] = NM[0][j];  // Esta línea es necesaria ya que el bucle para en i > 0 y no llega dar el numero de monedas
                            // el último cambio para el tamaño J así que la necesitamos
        return sol;
    }
}
