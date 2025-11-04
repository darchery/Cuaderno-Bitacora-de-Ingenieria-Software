
public class Cambio {
    public static void main(String[] args) {
        int[] d = {1,2,5,25,50,100};

        System.out.println("Prestaciones disponibles:");
        escribirArray(d);

        System.out.println("Vector solucion, con numero de monedas:");
        escribirArray(cambioVoraz(d, 289));
    }

    private static int[] cambioVoraz(int[] d, int P) {
        int monto = 0;
        int[] sol = new int[d.length];
        int n = d.length;
        int i = n-1;

        if (P != 0) {
            while (i >= 0 && monto < P) {
                if (d[i] > P || monto + d[i] > P) {
                    i--;
                } else if (monto + d[i] <= P){
                    monto += d[i];
                    sol[i]++;
                }
            }
        }
        return sol;
    }
    private static void escribirArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            if (i < a.length-1) {
                System.out.print(a[i] + ", ");
            }
            else {
                System.out.print(a[i]);
            }
        }
        System.out.println("\n");
    }
}