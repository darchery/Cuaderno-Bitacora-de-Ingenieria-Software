import java.util.*;

public class Torres {
    public static void main( String[] args){
	    try (Scanner sc = new Scanner(System.in)){
    	    int n = 8;
    	    
    	    boolean[][] L = new boolean[n][n];
    	    for (int i = 0; i < n; i++){
    	        String[] datos = sc.next().split(",");
    	        for (int j = 0; j < n; j++){
    	            L[i][j] = Boolean.parseBoolean(datos[j]);
    	        }   
    	    }
    	    
    	    boolean[][] S = new boolean[8][8];
			List<boolean[][]> mejores = new ArrayList<>();
			resolverTorres(S,0,0,L,mejores);
    	    
    	    boolean[][] M = mejores.get(0);
    	    StringJoiner sjs = new StringJoiner(", ","[","]");
			for (int i = 0; i < 8; i++) {
				StringJoiner sj = new StringJoiner(",","[","]");
				for (int j = 0; j < 8; j++) {
					sj.add(Boolean.toString(M[i][j]));
				}
				sjs.add(sj.toString());
			}
    	    
    	    System.out.println(sjs.toString());
	    }
	}
	
	
	private static void resolverTorres(boolean[][] S,int i,int j,boolean[][] L,
									   List<boolean[][]> mejores) {
		if (i == 8) {
			if (Final(S, L)) {
				int numTorresActual = numTorres(S);
				if (mejores.isEmpty() || numTorresActual < numTorres(mejores.get(0))) {
					mejores.clear();
					mejores.add(copia(S));
				} else if (numTorresActual == numTorres(mejores.get(0))) {
					 mejores.add(copia(S));
					}
			}
			return;
		}

		 int next_i = i;
		 int next_j = j + 1;
		 if (next_j == 8) {
			 next_i = i + 1;
			 next_j = 0;
		 }

		 if (L[i][j]) {
			 resolverTorres(S, next_i, next_j, L, mejores);
			 return;
		 }

		 // Opción 1: No colocar una torre
		 resolverTorres(S, next_i, next_j, L, mejores);

		 // Opción 2: Colocar una torre si es válido
		 if (valido(S, L, i, j)) {
			 S[i][j] = true; // Colocamos la torre
			 resolverTorres(S, next_i, next_j, L, mejores);
			 S[i][j] = false; // Backtracking
		 }
	}
}
	
	
	
	private static boolean[][] copia(boolean[][] s) {
		boolean[][] sol = new boolean[8][8];
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				sol[i][j] = s[i][j];
			}
		}
		return sol;
	}

	private static int numTorres(boolean[][] S) {
		int cont = 0;
		for (int f = 0; f < 8; f++) {					
			for (int c = 0; c < 8; c++) {
				if (S[f][c]) cont++;
			}
		}
		return cont;
	}

	private static boolean valido(boolean[][] s, boolean[][] l, int i, int j) {
		return !estaAmenazada(s,l,i,j);
	}

	private static boolean Final(boolean[][] s, boolean[][] l) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (!l[i][j] && !estaAmenazada(s,l,i,j)) return false;
			}
		}
		return true;
	}

	private static boolean estaAmenazada(boolean[][] s, boolean[][] l, int i, int j) {
		boolean amenazada = false;
		int f = i;
		int c = j;
		
		//Comprobamos por columna superior
		f = i;
		while (f>=0 //Este en el tablero 
			&& !l[f][j] //No sea obstaculo
			&& !amenazada) {
			amenazada = s[f][j];
			if (!amenazada) f--;
		}
		
		if (!amenazada) {
			//Comprobamos por columna inferior
			f = i;
			while (f<8 //Este en el tablero 
				&& !l[f][j] //No sea obstaculo
				&& !amenazada) {
				amenazada = s[f][j];
				if (!amenazada) f++;
			}
		}
		
		if (!amenazada) {
			//Comprobamos por fila izquierda
			c = j;
			while (c>=0 //Este en el tablero 
				&& !l[i][c] //No sea obstaculo
				&& !amenazada) {
				amenazada = s[i][c];
				if (!amenazada) c--;
			}
		}
		
		if (!amenazada) {
			//Comprobamos por fila izquierda
			c = j;
			while (c<8 //Este en el tablero 
				&& !l[i][c] //No sea obstaculo
				&& !amenazada) {
				amenazada = s[i][c];
				if (!amenazada) c++;
			}
		}
		
		return amenazada;
		
	}
	
}//end class 