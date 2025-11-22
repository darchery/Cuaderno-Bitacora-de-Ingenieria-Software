import factory.CreadorCirculo;
import factory.CreadorRectangulo;
import factory.CreadorTriangulo;
import product.Circulo;
import product.Rectangulo;
import product.Triangulo;

public class Main {
    public static void main(String[] args) {
        // Creaos una fábrica
        CreadorTriangulo fabricaTriangulo = new CreadorTriangulo();

        Triangulo triangulo1 = (Triangulo) fabricaTriangulo.creaFigura(5, 5);
        triangulo1.dibujar();

        Triangulo triangulo2 = (Triangulo) fabricaTriangulo.creaFigura(5, 7);
        triangulo2.dibujar();


        // Creaos una fábrica de rectángulos
        CreadorRectangulo fabricaRectangulo = new CreadorRectangulo();

        Rectangulo rectangulo1 = (Rectangulo) fabricaRectangulo.creaFigura(5, 5);
        rectangulo1.dibujar();

        Rectangulo rectangulo2 = (Rectangulo) fabricaRectangulo.creaFigura(2, 2);
        rectangulo2.dibujar();

        // Creaos una fábrica de círculo
        CreadorCirculo fabricaCirculo = new CreadorCirculo();

        Circulo circulo1 = (Circulo) fabricaCirculo.creaFigura(5);
        circulo1.dibujar();

        Circulo circulo2 = (Circulo) fabricaCirculo.creaFigura(2);
        circulo2.dibujar();

    }
}
