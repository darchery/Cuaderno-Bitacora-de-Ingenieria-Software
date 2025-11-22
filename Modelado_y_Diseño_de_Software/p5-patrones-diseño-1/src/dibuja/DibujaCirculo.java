package dibuja;

public class DibujaCirculo {
    private double radio;

    public DibujaCirculo(double radio) {
        this.radio = radio;
    }

    public void dibujarCirculo(){
        if (radio < 1) {
            System.out.println("El radio debe ser mayor o igual a 1.");
            return;
        }

        double r = radio;
        double rReducido = r - 0.5; // mejora la forma visual

        for (int y = (int) r; y >= -r; y--) {
            for (int x = (int) -r; x <= r; x++) {
                if (x * x + y * y <= rReducido * rReducido) {
                    System.out.print("*");
                } else {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}