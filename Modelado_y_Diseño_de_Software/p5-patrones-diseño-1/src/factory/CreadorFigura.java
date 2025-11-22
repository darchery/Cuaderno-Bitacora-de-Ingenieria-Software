package factory;

import product.Figura;

public abstract class CreadorFigura {

	/**
	 * 
	 * @param medida1
	 * @param medida2
	 */
	//Método fábrica (abstracto)
	public abstract Figura creaFigura(int medida1, int medida2);

	/**
	 * 
	 * @param medida1
	 * @param medida2
	 */
	//Métodos que usan el objeto creado
	public void dibujaFigura(int medida1, int medida2) {
		Figura figura = creaFigura(medida1, medida2); // Método fábrica abstracto para crear Figura
		figura.dibujar();	// Método de la interfaz Figura
	}
}