import java.util.Scanner;
import java.util.Arrays;
/*
 * Tenemos un suministro finito de monedas de n denominaciones con valores d1 , · · · , dn . 
 * Tenemos que pagar una cierta cantidad M. 
 * ¿Cuál es la forma de hacerlo empleando el número mínimo de monedas?
 * 
 * */
public class Cambio {
    public static class Res{
		public int numeroMonedas;
		public int[] sol;

		public Res(int numeroMonedas, int[] sol) {
			this.numeroMonedas = numeroMonedas;
			this.sol = Arrays.copyOf(sol, sol.length);
		}

		@Override
		public String toString() {
			return numeroMonedas +" "+Arrays.toString(sol);
		}
		
		@Override
		public boolean equals(Object obj) {
			boolean ok = this == obj;
			if (!ok && obj instanceof Res) {
				Res aux = (Res)obj;
				
				ok = this.numeroMonedas == aux.numeroMonedas;
				
			}
			return ok;
		}
		
		@Override
		public int hashCode() {
			return Integer.hashCode(this.numeroMonedas);
		}
	}//end Res
    
	public static void main( String[] args){
	    try (Scanner sc = new Scanner(System.in)){
    	    String[] svalor = sc.next().split(",");
    	    String[] scantidad = sc.next().split(",");
    	    int C = Integer.parseInt(sc.next());
    	    
    	    int[] valor = new int[svalor.length];
    	    int[] cantidad = new int[scantidad.length];
    	    
    	    for (int i = 0 ; i < valor.length; i++) valor[i] = Integer.parseInt(svalor[i]);
    	    for (int i = 0 ; i < cantidad.length; i++) cantidad[i] = Integer.parseInt(scantidad[i]);
    	    
    	    Res k = cambio(valor,cantidad,C);
    	    
    	    System.out.println(k.toString());
	    }
	}
	
	public static Res cambio(int[] d,int[] q, int C){
	    int n = d.lenght;
	    int inf = Integer.MAX_VALUE / 2;
	    int[][] NM = new int[n][C+1];
	    
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j <= C; j++) {
	            if (j == 0) {
	                NM[i][j] = 0;
	            }
	            else if (i == 0 && j % d[i] && (j/d[i] <= q[i])) {
	                NM[i][j] = j/d[i];
	            }
	            else if (i == 0) {
	                NM[i][j] = inf;
	            }
	            else {
	                NM[i][j] = NM[i-1][j]; // k == 0
	                
	                for (k = 1; k <= Math.min(q[i], j/d[i]); k++) {
	                    NM[i][j] = Math.min(NM[i][j], k + NM[i-1][j-d[i]*k]);
	                }
	            }
	       }
	   }
	}
}//end class Cambio