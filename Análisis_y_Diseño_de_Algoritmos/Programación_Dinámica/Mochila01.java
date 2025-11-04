
import java.util.Scanner;
import java.util.Arrays;
/*
 * Se dispone de n objetos, cada uno con un peso (wi ) y un beneficio (vi ).
 * También se dispone de una mochila en la que se pueden meter dichos objetos, con una capacidad de peso máximo M.
 * Sin perdida de generalidad se supondrá que todos los valores son > 0.
 * El objetivo consiste en maximizar el valor de los objetos transportados y respetando la limitación de capacidad máxima M
 *
 * */
public class Mochila01 {
	public static class Res{
		public int beneficio;
		public int[] sol;

		public Res(int beneficio, int[] sol) {
			this.beneficio = beneficio;
			this.sol = Arrays.copyOf(sol, sol.length);
		}

		@Override
		public String toString() {
			return beneficio +" "+Arrays.toString(sol);
		}

		@Override
		public boolean equals(Object obj) {
			boolean ok = this == obj;
			if (!ok && obj instanceof Res) {
				Res aux = (Res)obj;

				ok = this.beneficio == aux.beneficio;

			}
			return ok;
		}

		@Override
		public int hashCode() {
			return Integer.hashCode(this.beneficio);
		}
	}

	public static void main( String[] args){
		try (Scanner sc = new Scanner(System.in)){
			String[] speso = sc.next().split(",");
			String[] sbeneficio = sc.next().split(",");
			int W = Integer.parseInt(sc.next());

			Integer[] peso = new Integer[speso.length];
			Integer[] beneficio = new Integer[sbeneficio.length];

			for (int i = 0 ; i < peso.length; i++) peso[i] = Integer.parseInt(speso[i]);
			for (int i = 0 ; i < beneficio.length; i++) beneficio[i] = Integer.parseInt(sbeneficio[i]);

			Res k = mochila01(peso,beneficio,W);

			System.out.println(k.toString());
		}
	}

	public static Res mochila01(Integer[] peso, Integer[] beneficio, int W) {
		int n = peso.length;
		// Matriz para almacenar los beneficios máximos
		int[][] BM = new int[n + 1][W + 1];

		// Llenar la matriz BM con todas las opciones posibles
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= W; j++) {
				if (peso[i - 1] > j) {
					// Si el peso del elemento actual es mayor que la capacidad j, no lo incluimos
					BM[i][j] = BM[i - 1][j];
				} else {
					// Decidir si incluir el elemento actual o no
					BM[i][j] = Math.max(
							beneficio[i - 1] + BM[i - 1][j - peso[i - 1]],
							BM[i - 1][j] );
				}
			}
		}

		// Reconstruir la solución para saber qué elementos fueron incluidos
		int[] sol = new int[n];
		int i = n;
		int j = W;

		while (i > 0 && j >= 0) {
			if (BM[i][j] != BM[i - 1][j]) {
				// Si el beneficio actual es diferente al anterior, el elemento i-1 fue incluido
				sol[i - 1] = 1;
				j -= peso[i - 1];
			}
			i--;
		}

		// Retornar el resultado con el beneficio total y la solución
		return new Res(BM[n][W], sol);
	}
}//end class Mochila01