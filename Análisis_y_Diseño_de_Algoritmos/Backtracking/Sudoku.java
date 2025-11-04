import java.util.*

public class Sudoku {
    public static void main( String[] args){
	    try (Scanner sc = new Scanner(System.in)){
    	    int n = 9;
    	    
    	    int[][] S = new int[n][n];
    	    for (int i = 0; i < n; i++){
    	        String[] datos = sc.next().split(",");
    	        for (int j = 0; j < n; j++){
    	            S[i][j] = Integer.parseInt(datos[j]);
    	        }   
    	    }
    	    
    	    if (resolverSudoku(S,0,0)) {
    	        StringJoiner sjsol = new StringJoiner(",","[","]");
    			for (int i = 0; i < 9; i++) {
    				StringJoiner sjfila = new StringJoiner(",","[","]");
    				for (int j = 0; j < 9; j++) {
    					sjfila.add(Integer.toString(S[i][j]));
    				}
    				sjsol.add(sjfila.toString());
    			}
    			System.out.println(sjsol.toString());
    		}else {
    			System.out.println("No hay solución");
    	    }
	    }
	}
	
	
	private static boolean resolverSudoku(int[][] M,int i,int j) {
		// Se ha completado el Sudoku
		if (i == 9) {
			return true;
		}

		 // Calcular la siguiente posición
		 int next_i = i;
		 int next_j = j + 1;
		 if (next_j == 9) {
			next_i = i + 1;
			next_j = 0;
		 }

		if (M[i][j] != 0) {
			return resolverSudoku(M, next_i, next_j); // Casilla ya llena, pasar a la siguiente
		}
		else {// Probar números del 1 al 9
			for (int k = 1; k <= 9; k++) {
				if (valido(M, i, j, k)) {
					M[i][j] = k;
					if (resolverSudoku(M, next_i, next_j)) {
						return true;
					}
					M[i][j] = 0;
				}
			}
		}
		// No se pudo colocar ningún número válido
		return false;
	}
	
	private static boolean valido( int[][] M, int i,int j,int k) {
		return fila(M,i,k) && columna (M,j,k) && seccion(M,i,j,k);
	}

	private static boolean seccion(int[][] M, int i, int j, int k) {
		int Si = i/3;
		int Sj = j/3;
		
		for (int f=0; f<3; f++) {
			for (int c=0; c<3; c++) {				
				if (M[Si*3+f][Sj*3+c]==k) return false;
			}
		}
		return true;
	}

	private static boolean columna(int[][] M, int j, int k) {
		for (int i = 0; i < 9; i++) {
			if (M[i][j] == k) {
				return false;
			}
		}
		return true;
	}

	private static boolean fila(int[][] M, int i, int k) {
		for (int j = 0; j < 9; j++) {
			if (M[i][j] == k) {
				return false;
			}
		}
		return true;
	}
	
}//end class 