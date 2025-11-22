package factory;

import product.Circulo;
import product.Figura;

public class CreadorCirculo extends CreadorFigura {

	/*El área de un círculo solo necesita una medida, así que defino este método
    que llamará al heredado (el de abajo)
     */
	/**
	 * 
	 * @param radio
	 * @param medida2
	 */
	@Override
	public Figura creaFigura(int radio, int medida2) {
		return new Circulo(radio);
	}

	/**
	 * 
	 * @param radio
	 */
	public Figura creaFigura(int radio) {
		return creaFigura(radio, radio);
	}

}