package product;

import dibuja.DibujaCirculo;

public class Circulo implements Figura {

	private double radio;
	private DibujaCirculo dibujaCirculo;

	/**
	 * 
	 * @param radio
	 */
	public Circulo(double radio) {
		this.radio = radio;
		this.dibujaCirculo = new DibujaCirculo(radio);
	}
	@Override
	public void dibujar() {
		System.out.println("Dibujando un círculo de radio " + radio);
		System.out.println("Su área es: " + area());
		dibujaCirculo.dibujarCirculo();
	}
	@Override
	public double area() {
		return Math.PI * Math.pow(radio, 2);
	}

}