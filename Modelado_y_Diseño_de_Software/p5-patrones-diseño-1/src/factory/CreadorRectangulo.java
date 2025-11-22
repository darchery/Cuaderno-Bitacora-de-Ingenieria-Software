package factory;

import product.Figura;
import product.Rectangulo;

public class CreadorRectangulo extends CreadorFigura {

	/**
	 * 
	 * @param base
	 * @param altura
	 */
	@Override
	public Figura creaFigura(int base, int altura) {
		return new Rectangulo(base, altura);
	}

}