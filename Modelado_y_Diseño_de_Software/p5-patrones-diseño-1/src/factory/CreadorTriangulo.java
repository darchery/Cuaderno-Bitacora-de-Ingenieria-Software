package factory;

import product.Figura;
import product.Triangulo;

public class CreadorTriangulo extends CreadorFigura {

	/**
	 * 
	 * @param base
	 * @param altura
	 */
	@Override
	public Figura creaFigura(int base, int altura) {
		return new Triangulo(base, altura);
	}

}