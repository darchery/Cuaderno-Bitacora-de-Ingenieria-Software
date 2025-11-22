package dibuja;

public class DibujaRectangulo {
    double base;
    double altura;

    public DibujaRectangulo(double base, double altura) {
        this.base = base;
        this.altura = altura;
    }

    public void dibujarRectangulo(){
        if (base < 1 || altura < 1) {
            System.out.println("Base y altura deben ser mayores o iguales a 1.");
            return;
        }

        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < base; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
