package dibuja;

public class DibujaTriangulo {
    double base;
    double altura;

    public DibujaTriangulo(double base, double altura){
        this.base = base;
        this.altura = altura;
    }

    public void dibujarTriangulo(){
        if (base < 3 || altura < 2 || base % 2 == 0) {
            System.out.println("Base must be an odd number >= 3 and height >= 2.");
            return;
        }

        // The top starts with 1 char, the bottom has 'base' chars.
        // We'll increase the number of chars per line gradually.
        double step = (base - 1) / (double)(altura - 1);

        for (int i = 0; i < altura; i++) {
            int stars = 1 + (int)Math.round(i * step);
            if (stars % 2 == 0) stars--; // keep it odd for centering symmetry

            double spaces = (base - stars) / 2;

            // print spaces
            for (int s = 0; s < spaces; s++) System.out.print(" ");
            // print stars
            for (int s = 0; s < stars; s++) System.out.print("*");
            // newline
            System.out.println();
        }
    }

}

