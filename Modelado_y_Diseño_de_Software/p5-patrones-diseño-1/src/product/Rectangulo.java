package product;

import dibuja.DibujaRectangulo;

public class Rectangulo implements Figura {

	private double base;
	private double altura;
	private DibujaRectangulo dibujaRectangulo;

	/**
	 * 
	 * @param base
	 * @param altura
	 */
	public Rectangulo(int base, int altura) {
		this.base = base;
		this.altura = altura;
		dibujaRectangulo = new DibujaRectangulo(base, altura);
	}

	public void dibujar() {
		System.out.println("Dibujando un rectángulo de base " + base + " y altura " + altura);
		System.out.println("Su área es: " + area());
		dibujaRectangulo.dibujarRectangulo();
	}

	public double area() {
		return base * altura;
	}

}