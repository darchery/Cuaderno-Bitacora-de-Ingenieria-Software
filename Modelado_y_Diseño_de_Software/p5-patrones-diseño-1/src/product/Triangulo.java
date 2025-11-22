package product;
import dibuja.DibujaTriangulo;

public class Triangulo implements Figura {
	private double base;
	private double altura;
	private DibujaTriangulo dibujaTriangulo;

	/**
	 *
	 * @param base
	 * @param altura
	 */
	public Triangulo(double base, double altura) {
		this.base = base;
		this.altura = altura;
		dibujaTriangulo = new DibujaTriangulo(base, altura);
	}

	@Override
	public void dibujar() {
		System.out.println("Dibujando un triángulo de base " + base + " y altura " + altura);
		System.out.println("Su área es: " + area());
		dibujaTriangulo.dibujarTriangulo();
	}

	@Override
	public double area() {
		return (base * altura)/2;
	}

}